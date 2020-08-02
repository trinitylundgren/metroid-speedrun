/*********************************************************************
** Program name: Super Metroid Any WR Attempt - class Game
** Author: Trinity Lundgren
** Date: 2019-12-09
** Description: Implementation for class Game. Game contains all logic
**   pertaining to driving and displaying the game to the user,
**   collecting user input and executing player interactions.
*********************************************************************/

#include "Game.hpp"

/*********************************************************************
** Description: constructor for class Game.
*********************************************************************/
Game::Game() {
    gameTime = 0;
    brinstarBombETank = false;
    kraidETank = false;
    firefleaETank = false;
    hiJumpETank = false;
    postRidleyETank = false;
    botwoonETank = false;
    ceresRidleyDefeated = false;
    phantoonDefeated = false;
    ridleyDefeated = false;
    kraidDefeated = false;
    draygonDefeated = false;
    motherBrainDefeated = false;
    completedGame = false;
    savedAnimals = false;
}

/*********************************************************************
** Description: destructor for class Game.
*********************************************************************/
Game::~Game() {
    delete samus;
    delete zebes;
}

/*********************************************************************
** Description: drives the game.
*********************************************************************/
void Game::runGame() {
    // Clear screen
    system("clear");
    // Seed RNG
    srand(time(0));

    // Title Screen & Premise
    std::cout << "\nSUPER METROID ANY% WR ATTEMPT\n";
    std::cout << "Do you have what it takes? Make the right choices and beat 40:56.\n";
    std::cout << bar(80);
    std::string opening =
        "I first battled the Metroids on planet Zebes. It was there that I\n"
        "foiled the plans of the Space Pirate leader Mother Brain to use the\n"
        "creatures to attack Galactic Civilization...\n"
        "\n"
        "I next fought the Metroids on their homeworld, SR388. I completely\n"
        "eradicated them except for a larva, which after hatching followed me\n"
        "like a confused child...\n"
        "\n"
        "I personally delivered it to the Galactic Research Station at Ceres\n"
        "so the scientists could study its energy producing qualities...\n"
        "\n"
        "The scientists' findings were astounding! They discovered that the\n"
        "powers of the Metroid might be harnessed for the good of\n"
        "civilization!\n"
        "\n"
        "Satisfied that all was well, I left the station to seek a new bounty\n"
        "to hunt. But, I had hardly gone beyond the asteroid belt when I\n"
        "picked up a distress signal!\n"
        "\n"
        "Ceres station was under attack!!\n"
        "\n";
    std::cout << opening;

    // Select gamertag and create player
    std::string title = "Select Difficulty";
    std::string prompt = "Please choose a gamertag: ";
    std::string options[4] = {"for Behemoth78 (Legendary)",
                              "for zoast (Heroic)",
                              "for HeyWafflesOwn (Normal)",
                              "for trincel (Easy)"};
    int tag = optionMenu(title, prompt, options, 4, false, false);

    switch(tag) {
        case 1 :
            samus = new Player(Behemoth78);
            break;
        case 2 :
            samus = new Player(zoast);
            break;
        case 3 :
            samus = new Player(HeyWafflesOwn);
            break;
        case 4 :
            samus = new Player(trincel);
            break;
    }

    // Create Zebes
    zebes = new Zebes(samus, this);
    samus->setLocation(zebes->getStartingArea());

    // Game loop
    while (!completedGame) {
        //std::cout << samus->getLocation()->getName() << std::endl;
        Space* currentLocation = samus->getLocation();
        Space* nextLocation = currentLocation->runSpace();
        samus->setLocation(nextLocation);
    }
    if (motherBrainDefeated) {
        if (savedAnimals) {
            std::cout << "\nAs you escape the destruction, you look back to see a pixel "
                         "fire off into space... They're safe...\n\n";
        }
        std::cout << "\nWR TIME: 40:56" << std::endl;
        std::cout << "YOUR FINAL TIME: " << getTimeStr() << std::endl;
        if (gameTime <= 2456) {
            std::cout << "\nYOU ACHIEVED A WR RUN" << std::endl;
            std::cout << "Click here to download zero-suit.rar\n\n";
        }
        else {
            std::cout << "You did not achieve WR Pace. Keep trying...\n\n";
        }
    }
    else {
        std::cout << "YOU DIED...\n\n" << std::endl;
    }
}

/*********************************************************************
** Description: adds an int number of seconds to time.
*********************************************************************/
void Game::addTime(int seconds) {
    gameTime += seconds;
}

/*********************************************************************
** Description: returns the int value of time in seconds.
*********************************************************************/
int Game::getTime() const {
    return gameTime;
}

/*********************************************************************
** Description: returns the std::string time in HH::MM::SS format.
*********************************************************************/
std::string Game::getTimeStr() const {
    std::string timeStr = "";
    int hours = gameTime / 3600;
    int minutes = (gameTime - (hours * 3600)) / 60;
    int seconds = gameTime % 60;
    if (hours < 10) {
        timeStr += "0";
    }
    timeStr += std::to_string(hours);
    timeStr += ":";
    if (minutes < 10) {
        timeStr += "0";
    }
    timeStr += std::to_string(minutes);
    timeStr += ":";
    if (seconds < 10) {
        timeStr += "0";
    }
    timeStr += std::to_string(seconds);
    return timeStr;
}
