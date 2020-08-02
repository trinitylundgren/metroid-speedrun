/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Maridia
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Maridia, a derived class of
**   class Space.
*********************************************************************/

#ifndef MARIDIA_H
#define MARIDIA_H

#include "Space.hpp"

class Maridia : public Space {
  private:
    bool fightDraygon();
  public:
    Maridia(Player*, Game*);
    virtual Space* runSpace();
};

#endif
