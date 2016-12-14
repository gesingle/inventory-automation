#include <iostream>
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "logiccontroller.h"


int main() {
	std::cout << "Hello, World!" << std::endl;

	LogicController lc;
	lc.buildMovieInventory();
	lc.buildCustomerTable();
	lc.displayMovieInventory();
	lc.displayCustomerTable();
	lc.buildCommands();

	/*
	ClassicMovie m1(10, "Michael Curtiz", "Casablanca", "Ingrid Bergman", 8, 1942);
	ClassicMovie m2(10, "Michael Curtiz", "Casablanca", "Humphrey Bogart", 8, 1942);
	cout << "m1 < m2" << (m1 < m2) << endl;
	cout << "m1 > m2" << (m1 > m2) << endl;
	cout << "m1 == m2" << (m1 == m2) << endl;
	*/


	return 0;
}