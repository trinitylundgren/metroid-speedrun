/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Maridia
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Maridia, a derived class of
**   class Space.
*********************************************************************/

#include "Maridia.hpp"

/*********************************************************************
** Descriptiion: constructor for Maridia.
*********************************************************************/
Maridia::Maridia(Player* player, Game* game) : Space(player, game) {
    name = "MARIDIA";
    flavorText = "It's wet.";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* Maridia::runSpace() {
    Space* nextSpace = this;
    // Call Parent runSpace to display name and flavor text
    if (framesHere == 0) {
        Space::runSpace();
    }

    // Construct and display space menu
    std::string title, prompt;
    title = "";
    prompt = "Please choose from the following options: ";
    std::string options[5] = {"Go to Brinstar",
                              "Go to Wrecked Ship",
                              "Get Botwoon E Tank (Req. Speed Booster and G Suit)",
                              "Get Space Jump (Req. DRAYGON defeated, +15s)",
                              "Fight DRAYGON"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 5, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to go to Brinstar
        if (player->has(SpeedBooster)) {
            game->addTime(72);
        }
        else {
            game->addTime(90);
        }
        framesHere = 0;
        nextSpace = left;
        break;

    case 2 :
        // User chose to go to Wrecked Ship
        game->addTime(300);
        framesHere = 0;
        nextSpace = top;
        break;

    case 3 :
        // User chose to get Botwoon E Tank
        if (game->botwoonETank) {
            game->addTime(10);
            std::cout << "\nYou already got the Botwoon E Tank...\n\n";
        }
        else if (player->has(SpeedBooster) && player->has(GravitySuit)) {
            game->addTime(10);
            player->addTank();
            game->botwoonETank = true;
            std::cout << "\nYou picked up the Botwoon E Tank...\n\n";
        }
        ++framesHere;
        break;

    case 4 :
        // User chose to get Space Jump
        if (player->has(SpaceJump)) {
            game->addTime(10);
            std::cout << "\nYou already have Space Jump...\n";
            std::cout << "You shouldn't have picked it up once, let alone more than once...\n\n";
        }
        else if (game->draygonDefeated) {
            game->addTime(10);
            player->give(SpaceJump);
            std::cout << "\nYou Received A TIME PENALTY\n";
            std::cout << "Space Jump has no place in a WR Any% Run!\n\n";
        }
        else {
            game->addTime(10);
            std::cout << "\nYou have not yet defeated DRAYGON...\n\n";
        }
        ++framesHere;
        break;

    case 5 :
        // User chose to fight Draygon
        if (game->draygonDefeated) {
            game->addTime(10);
            ++framesHere;
            std::cout << "\nYou already defeated Draygon...\n\n";
        }
        else {
            if (fightDraygon()) {
                ++framesHere;
                game->addTime(121);
                game->draygonDefeated = true;
                std::cout << "\nYou defeated DRAYGON...\n\n";
            }
            else {
                nextSpace = nullptr;
                std::cout << "\nYou fell to DRAYGON...\n\n";
                game->completedGame = true;
            }
        }
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: executes battle with Draygon. Player may take damage or
**   die attempting to battle Draygon. If the player defeats Draygon,
**   returns true. If the player does not survive, returns false.
*********************************************************************/
bool Maridia::fightDraygon() {
    int eTankLuck = 10 * (player->getTanks() - 1);
    int totalLuck = player->getLuck() + eTankLuck;
    int range = 100 - totalLuck + 1;
    int roll = rand() % range + totalLuck;

    return (roll > 50);
}
