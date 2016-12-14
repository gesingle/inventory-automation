//
// Created by Garrett Singletary on 12/12/16.
//

#include "logiccontroller.h"
#include <fstream>
#include <iostream>
#include <sstream>

LogicController::LogicController() {

}

void LogicController::buildMovieInventory() {

	movieInventory = new MovieStorage();

	ifstream infile("data4movies.txt");
	if (!infile) {
		cout << "File could not be opened." << endl;
	}

	string line;
	char genre;

	while (getline(infile, line)) {

		getline(infile, line);
		stringstream ss(line);

		ss >> genre;

		switch (genre) {
		case 'F':
			movieInventory->addCoMovie(line);
			break;
		case 'D':
			movieInventory->addDrMovie(line);
			break;
		case 'C':
			movieInventory->addClMovie(line);
			break;
		}
	}

	movieInventory->displayClMovies();
	infile.close();

}

void LogicController::buildCustomerTable()
{
	customerTable = new CustomerTable();
	
	ifstream custFile("data4customers.txt");

	if (!custFile)
		cout << "ERROR: Customer file not found." << endl;

	string line;
	Customer* customer;
	
	while (!custFile.eof())
	{
		int custID;
		string first, last;

		custFile >> custID;
		custFile >> last;
		custFile >> first;

		if (!(custID < 0000 || custID > 9999))
		{
			customer = new Customer(first, last, custID);
			customerTable->addCustomer(customer);
		}
	}
	
	customerTable->displayCustomers();
	custFile.close();
	
}