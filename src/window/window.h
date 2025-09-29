#pragma once

#include <ncurses.h>
#include "../vector/vector.h"

extern int w_rows;
extern int w_cols;
extern int w_width;
extern int w_height;

extern f64 *distance_map;

void setup_colors();
void update_window_size(WINDOW *win);
void clean_map();
void draw_pixel(WINDOW *win, int x, int y, i32 color);
void draw_sphere(WINDOW *win, vec3 pos, f64 radius, i32 color);
void draw_line(WINDOW *win, vec3 pos1, vec3 pos2, i32 color);
