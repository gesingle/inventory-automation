//
// Created by Garrett Singletary on 12/12/16.
//


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
	void displayCustomerTable();
	void buildCommands();

private:
	MovieStorage* movieInventory;
	CustomerTable* customerTable;
	void parseBorrowReturn(string, char);
	void parseHistory(string);
	void borrowClMovie(int, int, string);
	void borrowCoMovie(string, int, int);
	void borrowDrMovie(string, string);
	void returnCoMovie(string, int, int);
	void returnClMovie(int, int, string, int);
	void returnDrMovie(string, string, int);
	void custHistory(int);

};


#endif //INC_343A4_LOGICCONTROLLER_H