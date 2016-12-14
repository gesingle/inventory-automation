//
// Created by Garrett Singletary on 12/12/16.
//

#ifndef INC_343A4_LOGICCONTROLLER_H
#define INC_343A4_LOGICCONTROLLER_H

#include <fstream>
#include "moviestorage.h"
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "CustomerTable.h"
#include "Customer.h"

class LogicController {

public:
	LogicController();
	void buildMovieInventory();
	void buildCustomerTable();

	void computeTransactions();

private:
	MovieStorage* movieInventory;
	CustomerTable* customerTable;
};


#endif //INC_343A4_LOGICCONTROLLER_H