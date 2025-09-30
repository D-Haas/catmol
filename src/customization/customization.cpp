#include "./customization.h"

RadiusMode radius_mode = SIMPLIFIED;
BondingMode bonding_mode = DOTTED;

void change_radius_mode()
{
  /*
   * Cycle radius mode, as the name says
   * REDUCED -> Radius are reduced so bondings can be shown
   * SIMPLIFIED -> Radius are brought closer together = sqrt(REDUCED)
   * ACCURATE -> Radius dimensions are accurate
  */
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
  /*
   * Cycle bonding mode, as the name also says
   * FILL -> Bondings are drawn as a filled line
   * DOTTED -> Bondings are drawn every other pixel (as dots)
  */
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
