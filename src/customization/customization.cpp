#include "./customization.h"

RadiusMode radius_mode = SIMPLIFIED;
BondingMode bonding_mode = DOTTED;

void change_radius_mode()
{
  switch (radius_mode)
  {
    case REDUCED:
      radius_mode = SIMPLIFIED;
      break;
    case SIMPLIFIED:
      radius_mode = ACCURATE;
      break;
    case ACCURATE:
      radius_mode = REDUCED;
      break;
  }
}

void change_bonding_mode()
{
  switch (bonding_mode)
  {
    case FILL:
      bonding_mode = DOTTED;
      break;
    case DOTTED:
      bonding_mode = FILL;
      break;
  }
}
