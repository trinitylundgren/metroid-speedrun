/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Space
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for parent class Space, representing
**   playable areas in the game.
*********************************************************************/

#include "Space.hpp"

/*********************************************************************
** Description: Constructor for class Space. Takes as argument a
**   pointer to a Player.
*********************************************************************/
Space::Space(Player* p, Game* g) {
    player = p;
    game = g;
    framesHere = 0;
    top = nullptr;
    right = nullptr;
    bottom = nullptr;
    left = nullptr;
}

/*********************************************************************
** Description: pure virtual destructor. Enforces Space as an abstract
**   class only.
*********************************************************************/
Space::~Space() {}

/*********************************************************************
** Description: returns the std::string Space name.
*********************************************************************/
std::string Space::getName() const {
    return name;
}

/*********************************************************************
** Description: assigns a Space* to top.
*********************************************************************/
void Space::setTop(Space* t) {
    top = t;
}

/*********************************************************************
** Description: assigns a Space* to right.
*********************************************************************/
void Space::setRight(Space* r) {
    right = r;
}

/*********************************************************************
** Description: assigns a Space* to bottom.
*********************************************************************/
void Space::setBottom(Space* b) {
    bottom = b;
}

/*********************************************************************
** Description: assigns a Space* to left.
*********************************************************************/
void Space::setLeft(Space* l) {
    left = l;
}

/*********************************************************************
** Description: returns a pointer to the top Space relative to this
**   Space.
*********************************************************************/
Space* Space::getTop() const {
    return top;
}

/*********************************************************************
** Description: returns a pointer to the right Space relative to this
**   Space.
*********************************************************************/
Space* Space::getRight() const {
    return right;
}

/*********************************************************************
** Description: returns a pointer to the bottom Space relative to this
**   Space.
*********************************************************************/
Space* Space::getBottom() const {
    return bottom;
}

/*********************************************************************
** Description: returns a pointer to the left Space relative to this
**   Space.
*********************************************************************/
Space* Space::getLeft() const {
    return left;
}

/*********************************************************************
** Description: runs the space.
*********************************************************************/
Space* Space::runSpace() {
    std::cout << bar(80);
    std::cout << "\nYou are in " << name << std::endl;
    std::cout << flavorText << std::endl << std::endl;
    std::cout << "Game Time: " << game->getTimeStr() << std::endl;
    std::cout << "Energy: " << player->getEnergy() << " of ";
    std::cout << player->getTanks() << " tanks" << std::endl;
    return this;
}
