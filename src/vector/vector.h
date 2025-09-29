#pragma once

#include "../constants.h"

class vec2
{
public:
  f64 x, y;
  vec2();
  vec2(f64 xy);
  vec2(f64 x, f64 y);

  vec2 operator+(const vec2& other);
  vec2 operator-(const vec2& other);
  vec2 operator*(const f64& s);
  vec2 operator/(const f64& s);
  vec2& operator+=(const vec2& other);
  vec2& operator-=(const vec2& other);
  vec2& operator*=(const f64& s);
  vec2& operator/=(const f64& s);
  f64  operator* (const vec2& other);

  void normalize();
  vec2 normalized();

  void rotate(f64 ang);
  vec2 rotated(f64 ang);
};

extern const vec2 VEC_ZERO;
extern const vec2 VEC_X;
extern const vec2 VEC_Y;
extern const vec2 VEC_MX;
extern const vec2 VEC_MY;

class vec3
{
public:
  f64 x, y, z;
  vec3();
  vec3(f64 xyz);
  vec3(f64 x, f64 y, f64 z);
  vec3(vec2 xy);

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
