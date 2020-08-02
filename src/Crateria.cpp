/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Crateria
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Crateria, a derived class of
**   class Space.
*********************************************************************/

#include "Crateria.hpp"

/*********************************************************************
** Descriptiion: constructor for Crateria.
*********************************************************************/
Crateria::Crateria(Player* player, Game* game) : Space(player, game) {
    name = "CRATERIA";
    flavorText = "A bleak and rocky area drenched with acid rain and many "
                 "caves to explore.";
}

/*********************************************************************
** Descriptiion: runSpace drives the logic for this Space's display
**   text, user input and interaction.
*********************************************************************/
Space* Crateria::runSpace() {
    Space* nextSpace = this;
    // Call Parent runSpace to display name and flavor text
    if (framesHere == 0) {
        Space::runSpace();
    }
    if (game->motherBrainDefeated) {
        nextSpace = postMotherBrain();
    }
    else {
        nextSpace = preMotherBrain();
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: Crateria behavior before defeating Mother Brain.
*********************************************************************/
Space* Crateria::preMotherBrain() {
    Space* nextSpace = this;

    // Construct and display space menu
    std::string title, prompt;
    title = "";
    prompt = "Please choose from the following options: ";
    std::string options[4] = {"Go to Brinstar",
                              "Go to Wrecked Ship (Requires Power Bombs)",
                              "Go to Tourian (Requires ?)",
                              "Get Bombs (Requires Missiles)"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 4, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to go to Brinstar
        game->addTime(45);
        if (player->has(Bombs) && !game->brinstarBombETank) {
            player->addTank();
            game->brinstarBombETank = true;
            std::cout << "You got an Energy Tank on the way to Brinstar\n\n";
        }
        framesHere = 0;
        nextSpace = bottom;
        break;

    case 2 :
        // User chose to go to Wrecked Ship
        if (player->has(PowerBombs)) {
            game->addTime(41);
            framesHere = 0;
            nextSpace = right;
        }
        else {
            game->addTime(10);
            ++framesHere;
            std::cout << "A yellow door blocks your path...\n\n";
        }
        break;
    case 3 :
        // User chose to go to Tourian
        if (game->phantoonDefeated && game->ridleyDefeated &&
            game->kraidDefeated && game->draygonDefeated) {
            game->addTime(106);
            framesHere = 0;
            nextSpace = left;
        }
        else {
            game->addTime(10);
            ++framesHere;
            std::cout << "You see a strange statue, with four glowing eyes...\n\n";
        }
        break;
    case 4 :
        // User chose to get Bombs
        if (player->has(Bombs)) {
            game->addTime(10);
            std::cout << "You already got Bombs...\n\n";
        }
        else if (!player->has(Missiles)) {
            game->addTime(10);
            std::cout << "A purple door blocks your path...\n\n";
        }
        else {
            game->addTime(53);
            player->give(Bombs);
            std::cout << "You Received BOMB\n\n";
        }
        ++framesHere;
        break;
    }
    return nextSpace;
}

/*********************************************************************
** Descriptiion: Crateria behavior after defeating Mother Brain.
*********************************************************************/
Space* Crateria::postMotherBrain() {
    Space* nextSpace = nullptr;

    // Construct and display space menu
    std::string title, prompt;
    title = "ESCAPE PLANET ZEBES";
    prompt = "Please choose from the following options: ";
    std::string options[2] = {"Save the Animals",
                              "Save the Frames"};

    // Collect and process user input
    int userChoice =  optionMenu(title, prompt, options, 2, false, false);
    switch(userChoice) {
    case 1 :
        // User chose to save the animals
        game->addTime(15);
        std::cout << "Forfeiting precious seconds, you free the Dachora and Etecoons from a fiery tomb...\n\n";
        break;

    case 2 :
        // User chose to save the frames
        game->addTime(4);
        std::cout << "Nothing can hold you back from glory...\n\n";
        break;
    }

    // No SpeedBooster penalty
    if (!player->has(SpeedBooster)) {
        game->addTime(10);
    }

    // End the game
    game->completedGame = true;
    return nextSpace;
}
