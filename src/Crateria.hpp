/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Crateria
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Crateria, a derived class of
**   class Space.
*********************************************************************/

#ifndef CRATERIA_H
#define CRATERIA_H

#include "Space.hpp"

class Crateria : public Space {
  private:
    Space* preMotherBrain();
    Space* postMotherBrain();
  public:
    Crateria(Player*, Game*);
    virtual Space* runSpace();

};

#endif
