/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Tourian
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Tourian, a derived class of
**   class Space.
*********************************************************************/

#include "Tourian.hpp"

/*********************************************************************
** Descriptiion: constructor for Tourian.
*********************************************************************/
Tourian::Tourian(Player* player, Game* game) : Space(player, game) {
    name = "TOURIAN";
    flavorText = "It's crawling with Metroids!";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* Tourian::runSpace() {
    Space* nextSpace = this;
    // Call Parent runSpace to display name and flavor text
    if (framesHere == 0) {
        Space::runSpace();
    }
    if (!game->motherBrainDefeated) {
        // Construct and display space menu
        std::string title, prompt;
        title = "";
        prompt = "Please choose from the following options: ";
        std::string options[1] = {"Fight MOTHER BRAIN"};

        // Collect and process user input
        int userChoice =  optionMenu(title, prompt, options, 1, false, false);
        switch(userChoice) {
        case 1 :
            if (fightMotherBrain()) {
                game->addTime(326);
                game->motherBrainDefeated = true;
                std::cout << "\nYou defeated MOTHER BRAIN...\n\n";
            }
            else {
                std::cout << "\nYou fell to MOTHER BRAIN...\n\n";
                nextSpace = nullptr;
                game->completedGame = true;
            }
            break;
        }
        return nextSpace;
    }

    // Mother Brain Defeated
    std::string title, prompt;
    title = "EVERYTHING IS EXPLODING";
    prompt = "Please choose from the following options: ";
    std::string options[1] = {"ESCAPE TO CRATERIA"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 1, false, false);
    switch(userChoice) {
    case 1 :
        game->addTime(59);
        nextSpace = right;
        break;
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: executes battle with MB. Player may take damage or
**   die attempting to battle MB. If the player defeats MB,
**   returns true. If the player does not survive, returns false.
*********************************************************************/
bool Tourian::fightMotherBrain() {
    if (player->getTanks() < 3) {
        return false;
    }
    int eTankLuck = 10 * (player->getTanks() - 1);
    int totalLuck = player->getLuck() + eTankLuck;
    int range = 100 - totalLuck + 1;
    int roll = rand() % range + totalLuck;

    return (roll > 60);
}
