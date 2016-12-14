//
// Created by Garrett Singletary on 12/12/16.
//

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
    void buildMovieInventory();
    void buildCustomerTable();
    void displayMovieInventory();
    void buildCommands();

private:
    MovieStorage* movieInventory;
    CustomerTable* customerTable;
    void parseBorrowReturn(string, char);
    void parseHistory(string);
};


#endif //INC_343A4_LOGICCONTROLLER_H
