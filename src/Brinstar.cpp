/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Brinstar
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Brinstar, a derived class of
**   class Space.
*********************************************************************/

#include "Brinstar.hpp"

/*********************************************************************
** Descriptiion: constructor for Brinstar.
*********************************************************************/
Brinstar::Brinstar(Player* player, Game* game) : Space(player, game) {
    name = "BRINSTAR";
    flavorText = "An underground complex of caverns and jungles used as a \n"
                  "Space Pirate base.";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* Brinstar::runSpace() {
    Space* nextSpace = this;
    // Call Parent runSpace to display name and flavor text
    if (framesHere == 0) {
        Space::runSpace();
    }

    // Construct and display space menu
    std::string title, prompt;
    title = "";
    prompt = "Please choose from the following options: ";
    std::string options[9] = {"Go to Crateria",
                              "Go to Norfair (Requires Super Missles)",
                              "Go to Maridia (Requires Power Bombs)",
                              "Get Morphing Ball",
                              "Get Missles (Requires Morphing Ball)",
                              "Get Super Missles (Requires Bombs)",
                              "Get Power Bombs (Requires Super Missles)",
                              "Get Extra E Tank (Requires Super Missiles and KRAID defeated, +11s)",
                              "Fight KRAID (Requires Super Missles)"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 9, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to go to Crateria
        if (player->has(SpeedBooster)) {
            game->addTime(24);
        }
        else {
            game->addTime(31);
        }
        framesHere = 0;
        nextSpace = top;
        break;

    case 2 :
        // User chose to go to Norfair
        if (player->has(SuperMissiles)) {
            game->addTime(80);
            framesHere = 0;
            nextSpace = bottom;
        }
        else {
            game->addTime(10);
            ++framesHere;
            std::cout << "\nA green door blocks your path...\n\n";
        }
        break;

    case 3 :
        // User chose to go to Maridia
        if (player->has(PowerBombs)) {
            game->addTime(78);
            // No Speed Booster Penalty
            if (!player->has(SpeedBooster)) {
                game->addTime(10);
            }
            framesHere = 0;
            nextSpace = right;
        }
        else {
            game->addTime(10);
            ++framesHere;
            std::cout << "\nYour progress is halted by seemingly indestructible blocks...\n\n";
        }
        break;

    case 4 :
        // User chose to get Morphing Ball
        if (player->has(MorphBall)) {
            game->addTime(10);
            std::cout << "\nYou already got Morphing Ball...\n\n";
        }
        else {
            game->addTime(3);
            player->give(MorphBall);
            std::cout << "\nYou Received MORPHING BALL\n\n";
        }
        ++framesHere;
        break;

    case 5 :
        // User chose to get Missiles
        if (player->has(Missiles)) {
            game->addTime(10);
            std::cout << "\nYou already got Missiles...\n\n";
        }
        else if (!player->has(MorphBall)) {
            game->addTime(10);
            std::cout << "\nYou come to an opening too small to pass...\n\n";
        }
        else {
            game->addTime(20);
            player->give(Missiles);
            std::cout << "\nYou Received MISSILE\n\n";
        }
        ++framesHere;
        break;

    case 6 :
        // User chose to get Super Missiles
        if (player->has(SuperMissiles)) {
            game->addTime(10);
            std::cout << "\nYou already got Super Missiles...\n\n";
        }
        else if (!player->has(Bombs)) {
            game->addTime(10);
            std::cout << "\nYou do not have Bombs...\n\n";
        }
        else {
            game->addTime(65);
            player->give(SuperMissiles);
            std::cout << "\nYou Received SUPER MISSILE\n\n";
        }
        ++framesHere;
        break;

    case 7 :
        // User chose to get Power Bombs
        if (player->has(PowerBombs)) {
            game->addTime(10);
            std::cout << "\nYou already got Power Bombs...\n\n";
        }
        else if (!player->has(SuperMissiles)) {
            game->addTime(10);
            std::cout << "\nYou do not have Super Missiles...\n\n";
        }
        else {
            game->addTime(120);
            player->give(PowerBombs);
            std::cout << "\nYou Received POWER BOMB\n\n";
        }
        ++framesHere;
        break;

    case 8 :
        // User chose to stop for Kraid E Tank
        if (game->kraidETank) {
            game->addTime(10);
            std::cout << "\nYou already got this E Tank...\n\n";
        }
        else if (!player->has(SuperMissiles)) {
            game->addTime(10);
            std::cout << "\nYou do not have Super Missiles...\n\n";
        }
        else if (!game->kraidDefeated) {
            game->addTime(10);
            std::cout << "\nYou have not yet defeated KRAID...\n\n";
        }
        else {
            game->addTime(11);
            player->addTank();
            game->kraidETank = true;
            std::cout << "\nYou stop for an E Tank near KRAID...\n\n";
        }
        ++framesHere;
        break;

    case 9 :
        // User chose to fight Kraid
        if (!player->has(SuperMissiles)) {
            game->addTime(10);
            std::cout << "\nYou do not have Super Missiles...\n\n";
            ++framesHere;
        }
        else if (game->kraidDefeated) {
            game->addTime(10);
            std::cout << "\nYou already defeated KRAID...\n\n";
            ++framesHere;
        }
        else {
            if (fightKraid()) {
                ++framesHere;
                if (player->has(SpeedBooster)) {
                    game->addTime(63);
                }
                else {
                    game->addTime(93);
                }
                if (game->draygonDefeated) {
                    game->addTime(60);
                }
                game->kraidDefeated = true;
                std::cout << "\nYou defeated KRAID...\n";
                std::cout << "You received VARIA SUIT\n\n";
            }
            else {
                nextSpace = nullptr;
                std::cout << "\nYou fell to KRAID... brutal.\n\n";
                game->completedGame = true;
            }
        }
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: executes battle with Kraid. Player may take damage or
**   die attempting to battle Kraid. If the player defeats Kraid,
**   returns true. If the player does not survive, returns false.
*********************************************************************/
bool Brinstar::fightKraid() {
    int eTankLuck = 10 * (player->getTanks() - 1);
    int totalLuck = player->getLuck() + eTankLuck;
    int range = 100 - totalLuck + 1;
    int roll = rand() % range + totalLuck;

    return (roll > 30);
}
