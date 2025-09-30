#pragma once

#include "../constants.h"

class vec3
{
public:
  f64 x, y, z;
  vec3();
  vec3(f64 xyz);
  vec3(f64 x, f64 y, f64 z);

  vec3 operator+(const vec3& other);
  vec3 operator-(const vec3& other);
  vec3 operator*(const f64& s);
  vec3 operator/(const f64& s);
  vec3& operator+=(const vec3& other);
  vec3& operator-=(const vec3& other);
  vec3& operator*=(const f64& s);
  vec3& operator/=(const f64& s);
  f64  operator* (const vec3& other);

  void normalize();
  vec3 normalized();

  double sqr_mod();
  double mod();

  void rotate_x(f64 ang);
  vec3 rotated_x(f64 ang);
  void rotate_y(f64 ang);
  vec3 rotated_y(f64 ang);
  void rotate_z(f64 ang);
  vec3 rotated_z(f64 ang);
};
