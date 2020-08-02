/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Ceres
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Ceres, a derived class of
**   class Space.
*********************************************************************/

#include "Ceres.hpp"

/*********************************************************************
** Descriptiion: constructor for Ceres.
*********************************************************************/
Ceres::Ceres(Player* player, Game* game) : Space(player, game) {
    framesHere = 0;
    name = "SPACE STATION CERES";
    flavorText = "The station is quiet. Where is everybody?";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* Ceres::runSpace() {
    // Call Parent runSpace to display name and flavor text first frame here
    if (framesHere == 0) {
        Space::runSpace();
    }

    // Construct and display space menu
    std::string title, prompt;
    Space* nextSpace = this;
    if (game->ceresRidleyDefeated) {
        title = "All the scientists... They're gone...";
    }
    else {
        title = "As you happen upon the last Metroid, a skeletal dragon with glowing eyes appears.";
    }
    prompt = "Please choose from the following options: ";
    std::string options[2] = {"Sit on Ridley's tail and take damage as quickly as possible", "Leave"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 2, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to fight Ridley
        ++framesHere;
        if (game->ceresRidleyDefeated) {
            game->addTime(10);
            std::cout << "\nYou've already fought Ridley. Time to escape!\n\n";
        }
        else {
            game->addTime(65);
            std::cout << "\nRidley takes off, clutching the last Metroid in his talons. You survive...\n\n";
            game->ceresRidleyDefeated = true;
        }
        break;

    case 2 :
        // User chose to leave
        if (game->ceresRidleyDefeated) {
            framesHere = 0;
            game->addTime(73);
            nextSpace = bottom;
        }
        else {
            ++framesHere;
            game->addTime(10);
            std::cout << "\nCan't escape! You must face Ridley.\n\n";
        }
    }
    return nextSpace;
}
