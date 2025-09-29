#pragma once

enum RadiusMode
{
  REDUCED,
  SIMPLIFIED,
  ACCURATE,
};

extern RadiusMode radius_mode;
void change_radius_mode();

enum BondingMode
{
  FILL,
  DOTTED
};

extern BondingMode bonding_mode;
void change_bonding_mode();
