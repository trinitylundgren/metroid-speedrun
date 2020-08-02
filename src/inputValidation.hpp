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

#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>
#include <istream>
#include <sstream>

int intAndOnlyInt(std::istream&);
bool isBetween(int, int, int);

#endif
