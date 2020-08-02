/*********************************************************************
** Program name: menu
** Author: Trinity Lundgren
** Date: 2019-09-30
** Description: Implementation file for menu function library.
*********************************************************************/

#include "menu.hpp"

// bar takes as argument an int and returns a bar string equal in length
// to the int passed in. Default length is 80 characters. bar exists for
// decorative use in menu functions.

std::string bar(int length=80) {
    std::string bar = "";
    for (int count = 0; count < length; ++count) {
        bar.append("-");
    }
    bar.append("\n");
    return bar;
}

// getInt takes as arguments a string title, string prompt, integer
// upper bound and integer lower bound (defaults are 0 and INT_MIN).
// Returns the int user input.

int getInt(std::string title, std::string prompt,
           int min, int max, bool clearScreen, bool oneLine) {

    // Display title, bar and prompt
    std::string userPrompt = prompt;
    while (true) {
        if (clearScreen) {
            system("clear");
        }
        if (!oneLine) {
            std::cout << std::endl;
            std::cout << title << std::endl;
            std::cout << bar(title.size());
        }
        std::cout << userPrompt;

        if (!oneLine) {
            std::cout << std::endl;
        }

        // Get integer from the user
        int userChoice = 0;
        userChoice = intAndOnlyInt(std::cin);
        if ((userChoice < 0) || !isBetween(userChoice, min, max)) {
            userPrompt = ("Invalid input. Please enter an integer between " +
                          std::to_string(min) + " and " + std::to_string(max) +
                          ".");
        }

        // When the user has made a valid choice, exit the loop and return it
        else {
            return userChoice;
        }
    }
}

// get double gets a double from the user.
double getDouble(std::string prompt, double min, double max) {
    double response;
    while (true) {
        std::cout << prompt;
        if(std::cin >> response && response >= min && response <= max) {
            cinRefresh();
            return response;
        }
        else {
            prompt = "Invalid input. Please enter a number between " +
                     std::to_string(min) + " and " + std::to_string(max) +
                     ": ";
            cinRefresh();
        }
    }
    return -1;
}

// getString gets a string from the user, then clears out the input stream.
std::string getString(std::string prompt) {
    //system("clear");
    std::cout << prompt;
    std::string returnStr = "";
    std::getline(std::cin, returnStr);
    std::cout << std::endl;
    //cinRefresh();
    return returnStr;
}

// cinRefresh clears out the input stream.
void cinRefresh() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

// optionMenu takes as arguments a string title, string prompt, array
// of string option text, and the number of options. Displays the menu
// and prompts the user to enter the option number. Returns the option.
// A return value of 0 indicated the user chose to exit.

int optionMenu(std::string title, std::string prompt,
               std::string* optionPtr, int numOptions,
               bool exitAllowed, bool clearScreen) {

    // Display menu. If additional options were added above, modify the code
    // below as needed to display more options.
    std::string userPrompt = prompt;
    while(true) {
        if (clearScreen) {
            system("clear");
        }
        std::cout << std::endl;
        std::cout << title << std::endl;
        std::cout << bar(title.size());
        std::cout << userPrompt << std::endl;

        // Display each option, 1-indexed
        for (int i = 0; i < numOptions; ++i) {
            std::cout << "Press [" << (i + 1) << "] ";
            std::cout << optionPtr[i] << std::endl;
        }

        // Display exit option
        if (exitAllowed) {
            std::cout << "Press [0] to Exit" << std::endl;
        }

        // Read and validate user input. Whether 0 is a valid input depends
        // on whether exitAllowed is enabled
        int userChoice = 0;
        userChoice = intAndOnlyInt(std::cin);
        if ((userChoice < 0) ||
            (exitAllowed && !isBetween(userChoice, 0, numOptions)) ||
            (!exitAllowed && !isBetween(userChoice, 1, numOptions))) {
            userPrompt = "Invalid input. Please choose from the options below.";
        }

        // When the user has made a valid choice, exit the loop and return the
        // value
        else {
            return userChoice;
        }
    }
}

// vectorMenu takes as arguments a string title, string prompt, and a
// std::vector of string options. vectorMenu displays the menu
// and prompts the user to enter the option number. Returns the option.
// A return value of 0 indicates the user chose to exit.

int vectorMenu(std::string title, std::string prompt,
               std::vector<std::string> optionVector,
               bool exitAllowed, bool clearScreen) {

    // Display menu. If additional options were added above, modify the code
    // below as needed to display more options.
    std::string userPrompt = prompt;
    while(true) {
        if (clearScreen) {
            system("clear");
        }
        std::cout << std::endl;
        std::cout << title << std::endl;
        std::cout << bar(title.size());
        std::cout << userPrompt << std::endl;

        // Display each option, 1-indexed
        for (size_t i = 0; i < optionVector.size(); ++i) {
            std::cout << "Press [" << (i + 1) << "] ";
            std::cout << optionVector[i] << std::endl;
        }

        // Display exit option
        if (exitAllowed) {
            std::cout << "Press [0] to Exit" << std::endl;
        }

        // Read and validate user input. Whether 0 is a valid input depends
        // on whether exitAllowed is enabled
        int userChoice = 0;
        userChoice = intAndOnlyInt(std::cin);
        if ((userChoice < 0) ||
            (exitAllowed && !isBetween(userChoice, 0, optionVector.size())) ||
            (!exitAllowed && !isBetween(userChoice, 1, optionVector.size()))) {
            userPrompt = "Invalid input. Please choose from the options below.";
        }

        // When the user has made a valid choice, exit the loop and return the
        // value
        else {
            return userChoice;
        }
    }
}

// collectEnter() prompts the user for an Enter and collects it
void collectEnter() {
    std::cout << std::endl << "Press ENTER to continue..." << std::flush;
    std::cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
}

// randomInt() returns a random integer between the int low and int high
//   arguments, inclusive. Should be seeded with <cstdlib> srand once
//   per program run.
int randomInt(int low, int high) {
    high -= (low - 1);
    return (rand() % high) + low;
}
