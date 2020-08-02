/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class WreckedShip
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class WreckedShip, a derived class of
**   class Space.
*********************************************************************/

#include "WreckedShip.hpp"

/*********************************************************************
** Descriptiion: constructor for WreckedShip.
*********************************************************************/
WreckedShip::WreckedShip(Player* player, Game* game) : Space(player, game) {
    name = "WRECKED SHIP";
    flavorText = "A spacecraft that crashed long ago on planet Zebes...";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* WreckedShip::runSpace() {
    Space* nextSpace = this;
    // Call Parent runSpace to display name and flavor text
    if (framesHere == 0) {
        Space::runSpace();
    }

    // Construct and display space menu
    std::string title, prompt;
    title = "";
    prompt = "Please choose from the following options: ";
    std::string options[3] = {"Go to Crateria",
                              "Go to Maridia (Requires PHANTOON defeated)",
                              "Fight PHANTOON"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 3, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to go to Crateria
        game->addTime(20);
        framesHere = 0;
        nextSpace = left;
        break;

    case 2 :
        // User chose to go to Maridia
        if (game->phantoonDefeated) {
            game->addTime(300);
            framesHere = 0;
            nextSpace = bottom;
        }
        else {
            game->addTime(10);
            ++framesHere;
            std::cout << "\nYou have not defeated Phantoon...\n\n";
        }
        break;

    case 3 :
        // User chose to fight Phantoon
        if (game->phantoonDefeated) {
            game->addTime(10);
            ++framesHere;
            std::cout << "\nYou already defeated PHANTOON...\n\n";
        }
        else {
            if (fightPhantoon()) {
                ++framesHere;
                game->addTime(216);
                game->phantoonDefeated = true;
                player->give(GravitySuit);
                std::cout << "\nYou defeated PHANTOON...\n";
                std::cout << "You received GRAVITY SUIT\n\n";
            }
            else {
                nextSpace = nullptr;
                std::cout << "\nYou fell to PHANTOON...\n\n";
                game->completedGame = true;
            }
        }
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: executes battle with Phantoon. Player may take damage or
**   die attempting to battle Phantoon. If the player defeats Phantoon,
**   returns true. If the player does not survive, returns false.
*********************************************************************/
bool WreckedShip::fightPhantoon() {
    int eTankLuck = 10 * (player->getTanks() - 1);
    int totalLuck = player->getLuck() + eTankLuck;
    int range = 100 - totalLuck + 1;
    int roll = rand() % range + totalLuck;
    return (roll > 65);
}
