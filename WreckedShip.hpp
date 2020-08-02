/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class WreckedShip
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class WreckedShip, a derived class of
**   class Space.
*********************************************************************/

#ifndef WRECKEDSHIP_H
#define WRECKEDSHIP_H

#include "Space.hpp"

class WreckedShip : public Space {
  private:
    bool fightPhantoon();
  public:
    WreckedShip(Player*, Game*);
    virtual Space* runSpace();
};

#endif
