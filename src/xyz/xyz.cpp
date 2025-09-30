#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <ncurses.h>
#include "./xyz.h"
#include "../window/window.h"
#include "../customization/customization.h"

using namespace std;

#define SQR(n) (n*n)

Structure::Structure(string xyz_path)
{

  ifstream file = ifstream(xyz_path); 
  i32 total_lines = 0;
  string line;
  char c_line[128];


  char atom_symbol[128];
  f64 x, y, z;
  i64 scan_result;

  //Get number of atoms in xyz file and pop comment line
  getline(file, line);
  strcpy(c_line, line.c_str());
  scan_result = sscanf(c_line, "%d", &total_lines);
  getline(file, line);

  this->atoms      = (Atom*) calloc(total_lines, sizeof(Atom));
  this->len        = total_lines;
  this->size_scale = 1.0;
  this->name       = xyz_path;

  u16 atoms_scanned = 0;
  while (getline(file, line) && atoms_scanned < total_lines)
  {
    strcpy(c_line, line.c_str());
    scan_result = sscanf(c_line, "%s %lf %lf %lf", atom_symbol, &x, &y, &z);
    u8 atom_number = atomic_symbol_to_number(atom_symbol);
    if (scan_result == 4)
    {
      Atom atom;
      atom.atomic_number = atom_number;
      atom.pos = vec3(x, y, z);

      atoms[atoms_scanned] = atom;
      atoms_scanned++;

    }

  }

  file.close();

  center();
}

void Structure::rotate_x(double ang)
{
  for (u16 i=0; i<len; i++)
    atoms[i].pos.rotate_x(ang);
}

void Structure::rotate_y(double ang)
{
  for (u16 i=0; i<len; i++)
    atoms[i].pos.rotate_y(ang);
}

void Structure::rotate_z(double ang)
{
  for (u16 i=0; i<len; i++)
    atoms[i].pos.rotate_z(ang);
}

void Structure::scale(WINDOW *win)
{
  double max_dist = 0;
  double temp_dist;

  for (u32 i = 0; i < len; i++)
    for (u32 j = i+1; j < len; j++)
    {
      temp_dist = (atoms[i].pos - atoms[j].pos).mod();
      temp_dist+= atomic_radi[atoms[i].atomic_number] + atomic_radi[atoms[j].atomic_number];
      if (temp_dist > max_dist)
        max_dist = temp_dist;
    }

  double width, height;
  getmaxyx(win, height, width);
  double min_dimension = min(width, height);

  double ratio = min_dimension/max_dist;
  for (u32 i=0; i < len; i++)
    atoms[i].pos*= ratio;

  this->size_scale*= ratio;
}

void Structure::center()
{
  vec3 avg_pos = vec3();
  double total_mass = 0;
  for (u32 i = 0; i < len; i++)
  {
    double atomic_mass = atomic_masses[atoms[i].atomic_number];
    avg_pos+= atoms[i].pos * atomic_mass;
    total_mass+= atomic_mass;
  }
  avg_pos/= total_mass;

  for (u32 i = 0; i < len; i++)
    atoms[i].pos-= avg_pos;
}

void Structure::draw(WINDOW *win)
{

  vec3 screen_center = vec3((double)w_width, (double)w_height, 0)/2;

  for (u32 i = 0; i < len; i++)
  {
    vec3 drawing_pos = atoms[i].pos + screen_center;
    double radius;
    switch (radius_mode)
    {
      case REDUCED:
        radius = atomic_radi[atoms[i].atomic_number]*size_scale/2;
        break;
      case SIMPLIFIED:
        radius = sqrt(atomic_radi[atoms[i].atomic_number])*size_scale/2;
        break;
      case ACCURATE:
        radius = atomic_radi[atoms[i].atomic_number]*size_scale;
        break;
      default:
        radius = 1;
    }
    draw_sphere(
      win,
      drawing_pos,
      radius,
      atomic_colors_term[atoms[i].atomic_number]
    );
  }

  for (u32 i = 0; i < len; i++)
    for (u32 j = i+1; j < len; j++)
    {
      double radi_sum = atomic_radi[atoms[i].atomic_number] + atomic_radi[atoms[j].atomic_number];
      double dist = (atoms[i].pos - atoms[j].pos).mod();
      if ((dist/size_scale) <= (radi_sum + 0.23))
      {
        draw_line(
          win,
          atoms[i].pos + screen_center,
          atoms[j].pos + screen_center,
          COLOR_WHITE
        );
      }
    }
}
