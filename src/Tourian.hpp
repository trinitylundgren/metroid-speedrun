/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Tourian
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Tourian, a derived class of
**   class Space.
*********************************************************************/

#ifndef TOURIAN_H
#define TOURIAN_H

#include "Space.hpp"

class Tourian : public Space {
  private:
    bool fightMotherBrain();
  public:
    Tourian(Player*, Game*);
    virtual Space* runSpace();
};

#endif
