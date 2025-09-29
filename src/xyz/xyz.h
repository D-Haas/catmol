#pragma once

#include <ncurses.h>
#include <string>
#include "../constants.h"
#include "../vector/vector.h"

using namespace std;

typedef struct {
  u8 atomic_number;
  vec3 pos;
} Atom;

class Structure {
public:
  Atom *atoms;
  u16 len;
  double size_scale;
  string name;

  Structure(string xyz_str);
  ~Structure() = default;

  void rotate_x(double ang);
  void rotate_y(double ang);
  void rotate_z(double ang);

  void draw(WINDOW *win);
  void scale(WINDOW *win);
  
  void center();
};
