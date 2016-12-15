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

#include "logiccontroller.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

LogicController::LogicController() {

    buildMovieInventory();
    buildCustomerTable();
}

void LogicController::buildMovieInventory() {

    movieInventory = new MovieStorage();
    // "/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4movies.txt"
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
    }

    string line;
    char genre;

    while (!infile.eof()) {

        getline(infile, line);
        stringstream ss(line);

        ss >> genre;

        switch (genre) {
            case 'F':
                movieInventory->addCoMovie(line);
                break;
            case 'D' :
                movieInventory->addDrMovie(line);
                break;
            case 'C' :
                movieInventory->addClMovie(line);
                break;
            default:
                cout << "Genre not valid" << endl;
                break;
        }
    }
    infile.close();
}

void LogicController::displayMovieInventory() {
    cout << endl << "Current Inventory: " << endl;
    cout << "   Comedies: " << endl;
    movieInventory->displayCoMovies();
    cout << "   Dramas: " << endl;
    movieInventory->displayDrMovies();
    cout << "   Classics: " << endl;
    movieInventory->displayClMovies();
    cout << endl;
}

void LogicController::buildCustomerTable() {
    customerTable = new CustomerTable();
    // /Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/
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

    custFile.close();
}

void LogicController::buildCommands() {
    // "/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4commands.txt"
    ifstream infile("data4commands.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
    }

    string line;

    while (!infile.eof()) {

        getline(infile, line);
        stringstream ss(line);

        char command;
        ss >> command;

        switch (command) {
            case 'B':
                parseBorrowReturn(line, command);
                break;
            case 'R' :
                parseBorrowReturn(line, command);
                break;
            case 'H' :
                parseHistory(line);
                break;
            case 'I' :
                displayMovieInventory();
                break;
            default:
                cout << "Invalid Command" << endl;
                break;
        }
    }
    infile.close();
}

void LogicController::parseBorrowReturn(string txtLine, char command) {

    stringstream ss(txtLine);

    ss.ignore();
    ss.ignore();

    string custIDStr = "";
    int custID;
    while(ss.peek() != ' '){
        custIDStr += ss.get();
    }
    ss.ignore();
    custID = stoi(custIDStr);

    char movieType;
    ss >> movieType;
    ss.ignore();

    char genre;
    ss >> genre;
    ss.ignore();

    string title = "";
    string actor = "";
    string director = "";
    string monthStr = "";
    int month;
    string yearStr = "";
    int year;

    switch(genre){
        case 'F':
            while(ss.peek() != ','){
                title += ss.get();
            }
            ss.ignore();
            ss.ignore();
            for(int i = 0; i < 4; i++){
                yearStr += ss.get();
            }
            year = stoi(yearStr);
            if(command == 'B') {
                borrowCoMovie(title, year, custID);
            }
            else if(command == 'R'){
                returnCoMovie(title, year, custID);
            }
            break;
        case 'D' :
            while(ss.peek() != ','){
                director += ss.get();
            }
            ss.ignore();
            ss.ignore();
            while(ss.peek() != ','){
                title += ss.get();
            }
            if(command == 'B') {
                borrowDrMovie(director, title, custID);
            }
            else if(command == 'R'){
                returnDrMovie(director, title, custID);
            }
            break;
        case 'C' :
            ss >> monthStr;
            ss.ignore();
            for(int i = 0; i < 4; i++){
                yearStr += ss.get();
            }
            ss.ignore();
            while(ss.peek() != EOF){
                actor += ss.get();
            }
            actor = actor.substr(0, actor.size()-1);
            month = stoi(monthStr);
            year = stoi(yearStr);
            if(command == 'B') {
                borrowClMovie(month, year, actor, custID);
            }
            else if(command == 'R'){
                returnClMovie(month, year, actor, custID);
            }
            break;
        default :
            cout << "Invalid genre" << endl;
            break;
    }
}

void LogicController::parseHistory(string line) {
    stringstream ss(line);
    ss.ignore();
    ss.ignore();

    string custIDStr = "";
    int custID;
    for(int i = 0; i < 4; i++){
        custIDStr += ss.get();
    }
    custID = stoi(custIDStr);
    custHistory(custID);
}
void LogicController::borrowClMovie(int month, int year, string actor, int custID) {

    ClMovieTree* clMovies = movieInventory->getClMovies();
    ClassicMovie* movie = new ClassicMovie(0, "", "", actor, month, year);
    ClassicMovie* moviePtr;
    Customer* borrowCustomer = new Customer();
    bool found;
    bool foundCust = customerTable->retrieveCustomer(custID, borrowCustomer);

    if(foundCust) {
        found = clMovies->retrieve(*movie, moviePtr);
        if (found) {
            if (moviePtr->getStock() > 0) {
                moviePtr->setStock(moviePtr->getStock() - 1);
                string customerBorrow = "B D C " + to_string(month) + ", " + to_string(year) + ", " + actor;
                borrowCustomer->addHistory(customerBorrow);
            } else {
                cout << "Movie is out of stock" << endl;
            }
        } else {
            cout << "Movie not found." << endl;
        }
    }
    else{
        cout << "Customer not found" << endl;
    }
    delete movie;
}

void LogicController::borrowCoMovie(string title, int year, int custID) {

    CoMovieTree* coMovies = movieInventory->getCoMovies();
    ComedyMovie* movie = new ComedyMovie(0, "", title, year);
    ComedyMovie* moviePtr;
    Customer* borrowCustomer = new Customer();
    bool found;
    bool foundCust = customerTable->retrieveCustomer(custID, borrowCustomer);

    if(foundCust) {
        found = coMovies->retrieve(*movie, moviePtr);
        if (found) {
            if (moviePtr->getStock() > 0) {
                moviePtr->setStock(moviePtr->getStock() - 1);
                string customerBorrow = "B D F " + title + ", " + to_string(year);
                borrowCustomer->addHistory(customerBorrow);
            } else {
                cout << "Movie is out of stock" << endl;
            }
            //delete moviePtr;
        } else {
            cout << "Movie not found." << endl;
        }
    }
    else{
        cout << "Customer not found" << endl;
    }
    delete movie;
}

void LogicController::borrowDrMovie(string director, string title, int custID) {

    DrMovieTree* drMovies = movieInventory->getDrMovies();
    DramaMovie* movie = new DramaMovie(0, director, title, 0);
    DramaMovie* moviePtr;
    Customer* borrowCustomer = new Customer();
    bool found;
    bool foundCust = customerTable->retrieveCustomer(custID, borrowCustomer);

    if(foundCust) {
        found = drMovies->retrieve(*movie, moviePtr);
        if (found) {
            if (moviePtr->getStock() > 0) {
                moviePtr->setStock(moviePtr->getStock() - 1);
                string customerBorrow = "B D D " + director + ", " + title;
                borrowCustomer->addHistory(customerBorrow);
            } else {
                cout << "Movie is out of stock" << endl;
            }
        } else {
            cout << "Movie not found." << endl;
        }
    }
    else{
        cout << "Customer not found" << endl;
    }
    delete movie;
}

void LogicController::returnCoMovie(string title, int year, int custID) {

    CoMovieTree* coMovies = movieInventory->getCoMovies();
    ComedyMovie* movie = new ComedyMovie(0, "", title, year);
    ComedyMovie* moviePtr;
    Customer* returnCustomer = new Customer();
    bool found;
    found = coMovies->retrieve(*movie, moviePtr);
    if (found)
    {
        bool foundCust = customerTable->retrieveCustomer(custID, returnCustomer);
        if (foundCust)
        {

            string customerBorrow = "B D F " + title + ", " + to_string(year);
            bool borrowed = returnCustomer->hasBorrowed(customerBorrow);
            {
                if (borrowed)
                {
                    moviePtr->setStock(moviePtr->getStock() + 1);
                    string customerReturn = "R D F " + title + ", " + to_string(year);
                    returnCustomer->addHistory(customerReturn);
                }

                else
                    cout << "Customer didn't borrow movie.\n";
            }
        }
        else
        {
            cout << "Customer not found.\n";
        }
    }
    else
    {
        cout << "Movie not found.";
        delete moviePtr;
    }
    delete movie;
}

void LogicController::returnClMovie(int month, int year, string actor, int custID)
{
    ClMovieTree* clMovies = movieInventory->getClMovies();
    ClassicMovie* movie = new ClassicMovie(0, "", "", actor, month, year);
    ClassicMovie* moviePtr;
    Customer* returnCustomer = new Customer();
    bool found;

    found = clMovies->retrieve(*movie, moviePtr);
    if (found)
    {
        bool foundCust = customerTable->retrieveCustomer(custID, returnCustomer);
        if (foundCust)
        {

            string customerBorrow = "B D C " + to_string(month) + ", " + to_string(year) + actor;
            bool borrowed = returnCustomer->hasBorrowed(customerBorrow);
            {
                if (borrowed)
                {
                    moviePtr->setStock(moviePtr->getStock() + 1);

                    string customerReturn = "R D C " + to_string(month) + ", " + to_string(year) + actor;
                    returnCustomer->addHistory(customerReturn);
                }

                else
                    cout << "Customer didn't borrow movie.\n";
            }
        }
        else
        {
            cout << "Customer not found.\n";
        }
    }
    else
    {
        cout << "Movie not found.";
        delete moviePtr;
    }
    delete movie;
}

void LogicController::returnDrMovie(string director, string title, int custID) {

    DrMovieTree* drMovies = movieInventory->getDrMovies();
    DramaMovie* movie = new DramaMovie(0, director, title, 0);
    DramaMovie* moviePtr;
    Customer* returnCustomer = new Customer();
    bool found;

    found = drMovies->retrieve(*movie, moviePtr);
    if (found) {
        bool foundCust = customerTable->retrieveCustomer(custID, returnCustomer);
        if (foundCust) {
            string customerBorrow = "B D D " + director + ", " + title;
            bool borrowed = returnCustomer->hasBorrowed(customerBorrow);{
                if (borrowed) {
                    moviePtr->setStock(moviePtr->getStock() + 1);
                    string customerReturn = "R D D " + director + ", " + title;
                    returnCustomer->addHistory(customerReturn);
                    cout << "drama returned" << endl;

                }
                else
                    cout << "Customer didn't borrow movie.\n";
            }
        }
        else {
            cout << "Customer not found.\n";
        }
    }
    else {
        cout << "Movie not found.";
        delete moviePtr;
    }
    delete movie;
}

void LogicController::custHistory(int custID) {

    Customer* customer = new Customer();

    bool found = customerTable->retrieveCustomer(custID, customer);
    if (found)
        customer->displayHistory();
}










