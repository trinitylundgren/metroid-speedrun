/*********************************************************************
** Program name: inputValidation library
** Author: Trinity Lundgren
** Date: 2019-10-08
** Description: implementation file for inputValidation, a library of
**              input validation functions for use in other programs.
**
** Together, intAndOnlyInt and isBetween may be used to get a user input
** that is a non-negative whole integer and then assert that it is in
** a desired range.
*********************************************************************/

#include "inputValidation.hpp"

// intAndOnlyInt gets a line from the input stream, and validates whether
// it has only a positive integer (may be 0). Returns the input if so,
// and returns -1 otherwise. std::cin is a valid istream object argument.

int intAndOnlyInt(std::istream& inputStream) {
    if (inputStream) {                       // If inputStream has contents
        int userInt = 0;
        bool validInput = false;
        std::string inputLine;

        // Use getline() to get characters from the istream object reference
        // passed in up to the delimiter '\n' (which is also extracted and
        // discarded) and place the characters into the string inputLine
        std::getline(inputStream, inputLine);

        // Create a stringstream object called lineStream out of the string
        // input line. This will be used to extract characters from
        // linestream into an int variable.
        std::stringstream lineStream(inputLine);

        // If the contents of lineStream can be cast to an integer
        // variable, then the user input at least one integer number
        // at the beginning of the string
        if ((lineStream >> userInt)) {
            validInput = true;
        }

        // Check whether the user input anything else after the int,
        // such as characters like '.' or others - this will reject
        // floats, or inputs with nonsense after int like "52 dsd";
        // this will also reject scientific notation ('E').
        char endJunk;
        if (lineStream >> endJunk) { // If you can still get characters
            validInput = false;      // out of the stream
        }
        if (validInput) {
            return userInt;
        }
        else {
            return -1;
        }
    }
    return -1;
}

// isBetween returns whether the int value is between the values of
// min and max, inclusive.

bool isBetween(int value, int min, int max) {
    return (value >= min && value <= max);
}
