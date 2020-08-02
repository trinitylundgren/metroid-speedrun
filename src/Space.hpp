/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Space
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for parent class Space, representing
**   playable areas in the game.
*********************************************************************/

#ifndef SPACE_H
#define SPACE_H

#include <string>
#include <iostream>
#include <cstdlib>

class Player;
class Game;

class Space {
  protected:
    Player* player;
    Game* game;
    int framesHere;
    std::string name;
    std::string flavorText;
    Space* top;
    Space* right;
    Space* bottom;
    Space* left;
 public:
    Space(Player*, Game*);
    virtual ~Space()=0;
    std::string getName() const;
    void setTop(Space*);
    void setRight(Space*);
    void setBottom(Space*);
    void setLeft(Space*);
    Space* getTop() const;
    Space* getRight() const;
    Space* getBottom() const;
    Space* getLeft() const;
    virtual Space* runSpace();
};

#include "Player.hpp"
#include "Game.hpp"
#endif
