#include <iostream>
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "logiccontroller.h"

int main() {
	std::cout << "Hello, World!" << std::endl;

	LogicController lc;
	//lc.buildMovieInventory();
	lc.buildCustomerTable();



	return 0;
}