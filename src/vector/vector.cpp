#include "vector.h"
#include <cmath>
#include <math.h>

/*
 * This is a module for vector math in R3
 * There might be no need to explain what
 * is done here, since some operations are
 * trivial
*/
vec3::vec3()
{
  this->x = 0;
  this->y = 0;
  this->z = 0;
}

vec3::vec3(f64 xyz)
{
  this->x = xyz;
  this->y = xyz;
  this->z = xyz;
}

vec3::vec3(f64 x, f64 y, f64 z)
{
  this->x = x;
  this->y = y;
  this->z = z;
}

vec3 vec3::operator+(vec3 const& other)
{
  return vec3(x+other.x, y+other.y, z+other.z);
}

vec3 vec3::operator-(vec3 const& other)
{
  return vec3(x-other.x, y-other.y, z-other.z);
}

vec3 vec3::operator*(f64 const& s)
{
  return vec3(x*s, y*s, z*s);
}

vec3 vec3::operator/(f64 const& s)
{
  return vec3(x/s, y/s, z/s);
}

vec3& vec3::operator+=(vec3 const& other)
{
  this->x+= other.x;
  this->y+= other.y;
  this->z+= other.z;
  return *this;
}

vec3& vec3::operator-=(vec3 const& other)
{
  this->x-= other.x;
  this->y-= other.y;
  this->z-= other.z;
  return *this;
}

vec3& vec3::operator*=(f64 const& s)
{
  this->x*= s;
  this->y*= s;
  this->z*= s;
  return *this;
}

vec3& vec3::operator/=(f64 const& s)
{
  this->x/= s;
  this->y/= s;
  this->z/= s;
  return *this;
}

f64 vec3::operator*(vec3 const& other)
{
  return (x*other.x) + (y*other.y) + (z*other.z);
}

void vec3::normalize()
{
  f64 invmag = 1/sqrt(x*x + y*y + z*z);
  this->x = x*invmag;
  this->y = y*invmag;
  this->z = z*invmag;
}

vec3 vec3::normalized()
{
  f64 invmag = 1/sqrt(x*x + y*y + z*z);
  return vec3(x*invmag, y*invmag, z*invmag);
}

double vec3::sqr_mod()
{
  return (x*x + y*y + z*z);
}

double vec3::mod()
{
  return sqrt(x*x + y*y + z*z);
}

void vec3::rotate_x(f64 ang)
{
  f64 s = sin(ang);
  f64 c = cos(ang);
  f64 y = this->y, z = this->z;
  this->y = c*y - s*z;
  this->z = s*y + c*z;
}

vec3 vec3::rotated_x(f64 ang)
{
  f64 s = sin(ang);
  f64 c = cos(ang);
  return vec3(
    x,
    c*y - s*z,
    s*y + c*z
  );
}

void vec3::rotate_y(f64 ang)
{
  f64 s = sin(ang);
  f64 c = cos(ang);
  f64 z = this->z, x = this->x;
  this->z = c*z - s*x;
  this->x = s*z + c*x;
}

vec3 vec3::rotated_y(f64 ang)
{
  f64 s = sin(ang);
  f64 c = cos(ang);
  return vec3(
    s*z + c*x,
    y,
    c*z - s*x
  );
}

void vec3::rotate_z(f64 ang)
{
  f64 s = sin(ang);
  f64 c = cos(ang);
  f64 x = this->x, y = this->y;
  this->x = c*x - s*y;
  this->y = s*x + c*y;
}

vec3 vec3::rotated_z(f64 ang)
{
  f64 s = sin(ang);
  f64 c = cos(ang);
  return vec3(
    c*x - s*y,
    s*x + c*y,
    z
  );
}
