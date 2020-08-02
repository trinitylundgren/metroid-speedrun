/*********************************************************************
** Program name: menu
** Author: Trinity Lundgren
** Date: 2019-09-30
** Description: Header file for menu function library.
*********************************************************************/

#ifndef MENU_H
#define MENU_H

#include <string>
#include <vector>
#include <iostream>
#include <limits>
#include <cstdlib>
#include <climits>
#include "inputValidation.hpp"

std::string bar(int);
int getInt(std::string, std::string, int=0, int=INT_MAX, bool = true, bool = false);
double getDouble(std::string prompt, double min, double max);
std::string getString(std::string prompt);
void cinRefresh();
int optionMenu(std::string, std::string, std::string*, int,
               bool=true, bool=true);
int vectorMenu(std::string, std::string, std::vector<std::string>,
               bool=true, bool=true);
void collectEnter();
int randomInt(int, int);
#endif
