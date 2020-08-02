/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Game
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Game. Game contains all logic
**   pertaining to driving and displaying the game to the user,
**   collecting user input and executing player interactions.
*********************************************************************/

#ifndef GAME_H
#define GAME_H

#include <string>
#include <cstdlib>
#include <ctime>
#include <cstdio>

#include "Player.hpp"
#include "menu.hpp"

class Zebes;
class Ceres;
class Crateria;
class Brinstar;
class Norfair;
class WreckedShip;
class Maridia;
class Tourian;

class Game {
  protected:
    friend class Ceres;
    friend class Crateria;
    friend class Brinstar;
    friend class Norfair;
    friend class WreckedShip;
    friend class Maridia;
    friend class Tourian;
    Zebes* zebes;
    Player* samus;
    int gameTime;
    bool brinstarBombETank;
    bool kraidETank;
    bool firefleaETank;
    bool hiJumpETank;
    bool postRidleyETank;
    bool botwoonETank;
    bool ceresRidleyDefeated;
    bool phantoonDefeated;
    bool ridleyDefeated;
    bool kraidDefeated;
    bool draygonDefeated;
    bool motherBrainDefeated;
    bool completedGame;
    bool savedAnimals;
  public:
    Game();
    ~Game();
    void runGame();
    void addTime(int);
    int getTime() const;
    std::string getTimeStr() const;
};

#include "Zebes.hpp"
#include "Ceres.hpp"
#include "Crateria.hpp"
#include "Brinstar.hpp"
#include "Norfair.hpp"
#include "WreckedShip.hpp"
#include "Maridia.hpp"
#include "Tourian.hpp"
#endif
