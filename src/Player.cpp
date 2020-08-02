/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Player
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Player, representing the Samus
**   with which the user will navigate Spaces and play the Game.
*********************************************************************/

#include "Player.hpp"

/*********************************************************************
** Description: constructor for class Player. Takes as argument a
**   std::string to assign to field gamertag, which determines
**   player's luck.
*********************************************************************/
Player::Player(Gamertag g) {

    // Assign gamertag and corresponding luck
    switch(g) {
    case Behemoth78 :
        gamertag = "Behemoth78";
        luck = 0;
        break;
    case zoast :
        gamertag = "zoast";
        luck = 15;
        break;
    case HeyWafflesOwn :
        gamertag = "HeyWafflesOwn";
        luck = 30;
        break;
    case trincel :
        gamertag = "trincel";
        luck = 45;
        break;
    }
    // Begin with one full energy tank
    energy = energyTanks = 1;
}

/*********************************************************************
** Description: returns the std::string Player's gamertag.
*********************************************************************/
std::string Player::getGamertag() const {
    return gamertag;
}

/*********************************************************************
** Description: adds Items to the inventory set. Takes as argument an
**   Item and adds it to inventory.
*********************************************************************/
void Player::give(Item item) {
    inventory.insert(item);
}

/*********************************************************************
** Description: checks whether the Player has an item. Returns true if
**   the item is present in the Player's inventory.
*********************************************************************/
bool Player::has(Item item) const {
    return (inventory.find(item) != inventory.end());
}

/*********************************************************************
** Description: returns the int value of energyTanks.
*********************************************************************/
int Player::getTanks() const {
    return energyTanks;
}

/*********************************************************************
** Description: increments energyTanks and energy. Called when the
**   Player gets an energyTank during the game.
*********************************************************************/
void Player::addTank() {
    ++energyTanks;
    ++energy;
}

/*********************************************************************
** Description: returns the int value of energy.
*********************************************************************/
int Player::getEnergy() const {
    return energy;
}

/*********************************************************************
** Description: decrements energy by 1, and returns true if the
**   Player survived (energy remaining > 0), and false otherwise.
*********************************************************************/
bool Player::takeDamage() {
    --energy;
    return (energy > 0);
}

/*********************************************************************
** Description: updates player's current location. Takes a Space* to
**   the location to move to.
*********************************************************************/
void Player::setLocation(Space* space) {
    currentLocation = space;
}

/*********************************************************************
** Description: returns a Space* to player's current location.
*********************************************************************/
Space* Player::getLocation() const {
    return currentLocation;
}

/*********************************************************************
** Description: returns the int Player's luck.
*********************************************************************/
int Player::getLuck() const {
    return luck;
}
