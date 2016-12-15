/* ------------------------------------------------ logiccontroller.cpp ------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class implements the primary business logic for the movie store inventory system.
 -----------------------------------------------------------------------------------------------------------------------
Assumptions:
    1. Invalid commands, customers, and movies are handled as per the assignment write up.
    2. The supplied txt files are formatted correctly
    3. C++ compiler is set to C++11
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef LOGICCONTROLLER_H
#define LOGICCONTROLLER_H

#include <fstream>
#include "moviestorage.h"
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "customertable.h"
#include "customer.h"

class LogicController {

public:
    LogicController();
    ~LogicController();
    void buildMovieInventory();
    void buildCustomerTable();
    void displayMovieInventory();
    void buildCommands();

private:
    // holds all movies
    MovieStorage* movieInventory;
    // holds all customers
    CustomerTable* customerTable;
    void parseBorrowReturn(string, char);
    void parseHistory(string);
    void borrowClMovie(int, int, string, int);
    void borrowCoMovie(string, int, int);
    void borrowDrMovie(string, string, int);
    void returnClMovie(int, int, string, int);
    void returnCoMovie(string, int, int);
    void returnDrMovie(string, string, int);
    void custHistory(int);
    void deleteStorage();



};


#endif //INC_343A4_LOGICCONTROLLER_H
