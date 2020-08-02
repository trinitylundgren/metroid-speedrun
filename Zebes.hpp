/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Zebes
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Zebes. Zebes is a linked
**   structure in which nodes are derived classes of Space,
**   each representing a major area of Super Metroid (SNES). Zebes
**   contains logic linking these nodes together to construct the
**   game world.
*********************************************************************/

#ifndef ZEBES_H
#define ZEBES_H

#include "Ceres.hpp"
#include "Crateria.hpp"
#include "Brinstar.hpp"
#include "WreckedShip.hpp"
#include "Norfair.hpp"
#include "Maridia.hpp"
#include "Tourian.hpp"

class Zebes {
  private:
    Ceres* ceres;
    Crateria* crateria;
    Brinstar* brinstar;
    WreckedShip* wreckedShip;
    Norfair* norfair;
    Maridia* maridia;
    Tourian* tourian;
  public:
    Zebes(Player*, Game*);
    ~Zebes();
    Space* getStartingArea();
};

#endif
