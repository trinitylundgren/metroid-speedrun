/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Player
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Header file for class Player, representing the Samus
**   with which the user will navigate Spaces and play the Game.
*********************************************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <set>

#include "Space.hpp"

enum Gamertag {Behemoth78, zoast, HeyWafflesOwn, trincel};

enum Item {MorphBall, Missiles, Bombs, SuperMissiles, VariaSuit,
           SpeedBooster, PowerBombs, GravitySuit, SpaceJump};
class Player {
  private:
    Space* currentLocation;
    std::string gamertag;
    int luck;
    int energyTanks;
    int energy;
    std::set<Item> inventory;
  public:
    Player(Gamertag);
    std::string getGamertag() const;
    void give(Item item);
    bool has(Item item) const;
    int getTanks() const;
    void addTank();
    int getEnergy() const;
    bool takeDamage();
    void setLocation(Space*);
    Space* getLocation() const;
    int getLuck() const;
};

#endif
