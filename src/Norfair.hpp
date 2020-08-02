/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Norfair
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Norfair, a derived class of
**   class Space.
*********************************************************************/

#ifndef NORFAIR_H
#define NORFAIR_H

#include "Space.hpp"

class Norfair : public Space {
  private:
    bool fightRidley();
  public:
    Norfair(Player*, Game*);
    virtual Space* runSpace();
};

#endif
