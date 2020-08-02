/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Zebes
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Zebes. Zebes is a linked
**   structure in which nodes are derived classes of Space,
**   each representing a major area of Super Metroid (SNES). Zebes
**   contains logic linking these nodes together to construct the
**   game world.
*********************************************************************/

#include "Zebes.hpp"

/*********************************************************************
** Description: Constructor for Zebes. Links Spaces classes together
**   to form the game world.
*********************************************************************/
Zebes::Zebes(Player* player, Game* game) {

    // Allocate Spaces
    ceres = new Ceres(player, game);
    crateria = new Crateria(player, game);
    brinstar = new Brinstar(player, game);
    wreckedShip = new WreckedShip(player, game);
    norfair = new Norfair(player, game);
    maridia = new Maridia(player, game);
    tourian = new Tourian(player, game);

    // Link Ceres. Note: Ceres is not on planet Zebes, but in orbit
    // around it.
    ceres->setBottom(crateria);

    // Link Crateria
    crateria->setTop(ceres);
    crateria->setRight(wreckedShip);
    crateria->setBottom(brinstar);
    crateria->setLeft(tourian);

    // Link Brinstar
    brinstar->setTop(crateria);
    brinstar->setRight(maridia);
    brinstar->setBottom(norfair);

    // Link Wrecked Ship
    wreckedShip->setBottom(maridia);
    wreckedShip->setLeft(crateria);

    // Link Norfair
    norfair->setTop(brinstar);

    // Link Maridia
    maridia->setTop(wreckedShip);
    maridia->setLeft(brinstar);

    // Link Tourian
    tourian->setRight(crateria);
}

/*********************************************************************
** Description: destructor for Zebes.
*********************************************************************/
Zebes::~Zebes() {
    delete ceres;
    delete crateria;
    delete brinstar;
    delete wreckedShip;
    delete norfair;
    delete maridia;
    delete tourian;
}

/*********************************************************************
** Description: returns a pointer to the starting area (Ceres).
*********************************************************************/
Space* Zebes::getStartingArea() {
    return ceres;
}
