/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Ceres
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Ceres, a derived class of
**   class Space.
*********************************************************************/

#ifndef CERES_H
#define CERES_H

#include "Space.hpp"

class Ceres : public Space {
  public:
    Ceres(Player*, Game*);
    virtual Space* runSpace();
};

#endif
