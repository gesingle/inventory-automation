/* ------------------------------------------------ main.cpp -----------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 Runnable for movie inventory system.
 -----------------------------------------------------------------------------------------------------------------------
Assumptions:
    1. Invalid commands, customers, and movies are handled as per the assignment write up.
    2. The supplied txt files are formatted correctly
    3. C++ compiler is set to C++11
 -----------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "logiccontroller.h"

int main() {

    LogicController lc;
    lc.buildCommands();
    return 0;
}