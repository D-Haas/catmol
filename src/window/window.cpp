#include "./window.h"
#include <algorithm>
#include <cmath>
#include <math.h>
#include <stdlib.h>
#include "../customization/customization.h"

using namespace std;

#define SQR(n) (n*n)

int w_rows, w_cols;
int w_width, w_height;
double scale;

double *distance_map = NULL;

void setup_colors()
{
  use_default_colors();
  for (i16 i=0; i<COLORS; i++)
  {
    init_pair(i, i, -1);
  }
}

void update_window_size(WINDOW *win)
{
  getmaxyx(win, w_rows, w_cols);
  w_width = w_cols / 2;
  w_height = w_rows;

  if (distance_map)
    free(distance_map);
  distance_map = (double *)calloc(w_width * w_height, sizeof(double));
}

void clean_map()
{
  for (int i = 0; i < w_width * w_height; i++)
    distance_map[i] = -9999999;
}

void draw_pixel(WINDOW *win, int x, int y, i32 color)
{
  /*
   * Draws a single pixel on screen
  */

  // Move cursor to x, y  position
  wmove(win, y, x*2);

  // Set color
  wattron(win, COLOR_PAIR(color));

  // Draw filled boxes
  // 2 boxes ~= 1 pixel
  // (Depending on your monospaced font proportions)
  waddch(win, ACS_BLOCK);
  waddch(win, ACS_BLOCK);

  // Put color to normal
  wattroff(win, COLOR_PAIR(color));
}

void draw_dot(WINDOW *win, vec3 pos, i32 color)
{
  /*
   * Draws a pixel in screen
   * Taking into account if something was rendered
   * "above" it or not
  */
  int ix = round(pos.x);
  int iy = round(pos.y);
  if (pos.z > distance_map[iy * w_width + ix])
  {
    distance_map[iy * w_width + ix] = pos.z;
    draw_pixel(win, ix, iy, color);
  }
}

void draw_sphere_int(WINDOW *win, vec3 pos, f64 radius, i32 color)
{
  /*
   * Draws a sphere on the given position
   * with a certain radius and color
   *
   * This version of the method uses int for
   * most math
  */

  // Get sphere center x and y
  int center_x = (int)pos.x, center_y = (int)pos.y;

  // Get sphere limits for each direction
  int top = (int)(pos.y - radius);
  int bottom = (int)(pos.y + radius);
  int left = (int)(pos.x - radius);
  int right = (int)(pos.x + radius);

  // Get radius squared
  int radius_sqr = (int)(radius * radius);

  // Iterate over pixels within the sphere limits
  for (int x = max(0, left); x < min(w_width, right); x++)
    for (int y = max(0, top); y < min(w_height, bottom); y++)
    {
      int dist_sqr = SQR((center_x-x)) + SQR((center_y-y));
      if (dist_sqr <= radius_sqr)
      {
        double dist = sqrt((double) dist_sqr);
        double colliding_angle = acos(dist/radius);
        double distance = pos.z + sin(colliding_angle);

        if (distance > distance_map[y * w_width + x])
        {
          distance_map[y * w_width + x] = distance;
          draw_pixel(win, x, y, color);
        }
      }
    }
}

void draw_sphere(WINDOW *win, vec3 pos, f64 radius, i32 color)
{
  double top        = floor(pos.y - radius) + 0.5;
  double bottom     = ceil( pos.y + radius) - 0.5;
  double left       = floor(pos.x - radius) + 0.5;
  double right      = ceil( pos.x + radius) - 0.5;
  double radius_sqr = radius * radius;

  double width = (double) w_width;
  double height = (double) w_height;
  double max_x = min(width - 0.5, right);
  double max_y = min(height - 0.5, bottom);
  for (double x = max(0.5, left); x <= max_x; x++)
    for (double y = max(0.5, top); y <= max_y; y++)
    {
      double dist_sqr = SQR((pos.x-x)) + SQR((pos.y-y));
      if (dist_sqr <= radius_sqr)
      {
        double dist = sqrt(dist_sqr);
        double colliding_angle = acos(dist/radius);
        double distance = pos.z + sin(colliding_angle);

        int ix = round(x);
        int iy = round(y);
        if (distance > distance_map[iy * w_width + ix])
        {
          distance_map[iy * w_width + ix] = distance;
          draw_pixel(win, ix, iy, color);
        }
      }
    }
}

void draw_line(WINDOW *win, vec3 pos1, vec3 pos2, i32 color)
{
  double dist = (pos2 - pos1).mod();

  vec3 dir_vec = (pos2 - pos1).normalized();

  double step = bonding_mode == FILL ? 1.0 : 2.0;

  double i = 0.0;
  while (i < dist)
  {
    draw_dot(
      win,
      pos1 + (dir_vec*i),
      color
    );

    i+= step;
  }
}




