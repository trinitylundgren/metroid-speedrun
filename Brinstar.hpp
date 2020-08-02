/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Brinstar
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Brinstar, a derived class of
**   class Space.
*********************************************************************/

#ifndef BRINSTAR_H
#define BRINSTAR_H

#include "Space.hpp"

class Brinstar : public Space {
  private:
    bool fightKraid();
  public:
    Brinstar(Player*, Game*);
    virtual Space* runSpace();
};

#endif
