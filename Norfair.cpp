/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Norfair
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Norfair, a derived class of
**   class Space.
*********************************************************************/

#include "Norfair.hpp"

/*********************************************************************
** Descriptiion: constructor for Norfair.
*********************************************************************/
Norfair::Norfair(Player* player, Game* game) : Space(player, game) {
    name = "NORFAIR";
    flavorText = "The extreme heat in this lava-filled cavern is so intense, \n"
                 "you can hardly stand it...";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* Norfair::runSpace() {
    Space* nextSpace = this;
    // Call Parent runSpace to display name and flavor text
    if (framesHere == 0) {
        Space::runSpace();
    }

    // Construct and display space menu
    std::string title, prompt;
    title = "";
    prompt = "Please choose from the following options: ";
    std::string options[6] = {"Go to Brinstar",
                              "Get Fireflea E Tank (Requires Power Bombs, +26s)",
                              "Get Hi Jump E Tank (+2s before Speed Booster)",
                              "Get Speed Booster",
                              "Get Optional E Tank (Requires Ridley Defeated, +13)",
                              "Fight RIDLEY"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 6, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to go to Brinstar
        if (player->has(SpeedBooster)) {
            game->addTime(156);
        }
        else {
            game->addTime(170);
        }
        framesHere = 0;
        nextSpace = top;
        break;

    case 2 :
        // User chose to get Fireflea E Tank
        if (game->firefleaETank) {
            game->addTime(10);
            std::cout << "\nYou already got the Fireflea E Tank...\n\n";
        }
        else if (!player->has(PowerBombs)) {
            game->addTime(10);
            std::cout << "\nYou do not have Power Bombs...\n\n";
        }
        else {
            game->addTime(26);
            player->addTank();
            game->firefleaETank = true;
            std::cout << "\nYou picked up the Fireflea E Tank...\n\n";
        }
        ++framesHere;
        break;

    case 3 :
        // User chose to get Hi Jump E Tank
        if (game->hiJumpETank) {
            game->addTime(10);
            std::cout << "\nYou already got the Hi Jump E Tank...\n\n";
        }
        else {
            if (player->has(SpeedBooster)) {
                game->addTime(13);
            }
            else {
                game->addTime(2);
            }
            player->addTank();
            game->hiJumpETank = true;
            std::cout << "\nYou picked up the Hi Jump E Tank...\n\n";
        }
        ++framesHere;
        break;

    case 4 :
        // User chose to get Speed Booster
        if (player->has(SpeedBooster)) {
            game->addTime(10);
            std::cout << "\nYou already got Speed Booster...\n\n";
        }
        else {
            game->addTime(148);
            player->give(SpeedBooster);
            std::cout << "\nYou Received SPEED BOOSTER\n\n";
        }
        ++framesHere;
        break;

    case 5 :
        // User chose to get optional post-Ridley E Tank
        if (game->postRidleyETank) {
            game->addTime(10);
            std::cout << "\nYou already got this E Tank...\n\n";
        }
        else if (game->ridleyDefeated) {
            game->addTime(13);
            player->addTank();
            std::cout << "\nYou received the Post-RIDLEY E Tank...\n\n";
        }
        else {
            game->addTime(10);
            std::cout << "\nYou have not yet defeated RIDLEY...\n\n";
        }
        ++framesHere;
        break;

    case 6 :
        // User chose to fight Ridley
        if (game->ridleyDefeated) {
            game->addTime(10);
            ++framesHere;
            std::cout << "\nYou already defeated RIDLEY...\n\n";
        }
        else {
            if (fightRidley()) {
                ++framesHere;
                game->addTime(333);
                game->ridleyDefeated = true;
                std::cout << "\nYou defeated RIDLEY...\n\n";
            }
            else {
                nextSpace = nullptr;
                std::cout << "\nYou fell to RIDLEY...\n\n";
                game->completedGame = true;
            }
        }
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: executes battle with Ridley. Player may take damage or
**   die attempting to battle Ridley. If the player defeats Ridley,
**   returns true. If the player does not survive, returns false.
*********************************************************************/
bool Norfair::fightRidley() {
    int eTankLuck = 10 * (player->getTanks() - 1);
    int totalLuck = player->getLuck() + eTankLuck;
    int range = 100 - totalLuck + 1;
    int roll = rand() % range + totalLuck;

    return (roll > 65);
}
