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

// ------------------------------------------------ LogicController ----------------------------------------------------
//  Constructor
// ---------------------------------------------------------------------------------------------------------------------
LogicController::LogicController() {

    buildMovieInventory();
    buildCustomerTable();
}

// ------------------------------------------------ ~LogicController ---------------------------------------------------
//  Destructor
// ---------------------------------------------------------------------------------------------------------------------
LogicController::~LogicController() {
    deleteStorage();
}

// ------------------------------------------------ buildMovieInventory ------------------------------------------------
//  Builds movie inventory from .txt file. Parses movies by genre and adds them to the appropriate movie tree
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::buildMovieInventory() {

    movieInventory = new MovieStorage();
    // "/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4movies.txt"
    ifstream infile("data4movies.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
    }

    // string to contain each complete line from file
    string line;
    char genre;

    while (!infile.eof()) {

        getline(infile, line);
        stringstream ss(line);

        ss >> genre;

        // identify genre and add movie to apppropriate movie tree
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
                // Notify user if invalid genre is used
                cout << "Genre not valid" << endl;
                break;
        }
    }
    infile.close();
}

// ------------------------------------------------ displayMovieInventory ----------------------------------------------
//  Displays all movies in inventory by genre (Comedies -> Dramas -> Classics)
// ---------------------------------------------------------------------------------------------------------------------
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

// ------------------------------------------------ buildCustomerTable -------------------------------------------------
//  Builds a hash table of customers from input file
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::buildCustomerTable() {
    customerTable = new CustomerTable();
    // /Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/
    ifstream custFile("data4customers.txt");

    if (!custFile)
        cout << "ERROR: Customer file not found." << endl;

    // string to contain each complete line
    string line;
    // pointer to hold new customer
    Customer* customer;

    while (!custFile.eof())
    {
        int custID;
        string first, last;

        custFile >> custID;
        custFile >> last;
        custFile >> first;

        // check for invalid customer ID
        if (!(custID < 0000 || custID > 9999))
        {
            // create new customer and add to the hash table
            customer = new Customer(first, last, custID);
            customerTable->addCustomer(customer);
        }
    }

    custFile.close();
}

// --------------------------------------------- displayCustomerTable --------------------------------------------------
//  Displays data for all Customers in CustomerTable
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::displayCustomerTable()
{
    cout << "Displaying all customers:\n";
    customerTable->displayCustomers();
}

// ------------------------------------------------ buildCommands ------------------------------------------------------
//  Reads in a series of commands from a .txt file and executes them
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::buildCommands() {
    // "/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4commands.txt"
    ifstream infile("data4commands.txt");
    if (!infile) {
        cout << "File could not be opened." << endl;
    }

    // string to hold each complete line
    string line;

    while (!infile.eof()) {

        getline(infile, line);
        stringstream ss(line);

        char command;
        ss >> command;

        // check for command to be executed
        switch (command) {
            case 'B':
                // borrow
                parseBorrowReturn(line, command);
                break;
            case 'R' :
                // return
                parseBorrowReturn(line, command);
                break;
            case 'H' :
                // output customer history
                parseHistory(line);
                break;
            case 'I' :
                // display movie inventory
                displayMovieInventory();
                break;
            default:
                // notify user of invalid command
                cout << "Invalid Command" << endl;
                break;
        }
    }
    infile.close();
}

// ------------------------------------------------ parseBorrowReturn --------------------------------------------------
//  Parses a line of txt for a borrow or return (B or R) command and executes the command
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::parseBorrowReturn(string txtLine, char command) {

    stringstream ss(txtLine);

    ss.ignore();
    ss.ignore();

    // parse customer ID
    string custIDStr = "";
    int custID;
    while(ss.peek() != ' '){
        custIDStr += ss.get();
    }
    ss.ignore();
    custID = stoi(custIDStr);

    // parse movie type
    char movieType;
    ss >> movieType;
    ss.ignore();

    // parse movie genre
    char genre;
    ss >> genre;
    ss.ignore();

    // placeholder for all possible movie attributes
    string title = "";
    string actor = "";
    string director = "";
    string monthStr = "";
    int month;
    string yearStr = "";
    int year;

    // check movie genre and excute appropriate borrow or return command for that genre
    switch(genre){
        case 'F':
            // gather pertinant info for comedies
            while(ss.peek() != ','){
                title += ss.get();
            }
            ss.ignore();
            ss.ignore();
            for(int i = 0; i < 4; i++){
                yearStr += ss.get();
            }
            year = stoi(yearStr);
            // check if borrow or return
            if(command == 'B') {
                borrowCoMovie(title, year, custID);
            }
            else if(command == 'R'){
                returnCoMovie(title, year, custID);
            }
            break;
        case 'D' :
            // gather pertinant info for dramas
            while(ss.peek() != ','){
                director += ss.get();
            }
            ss.ignore();
            ss.ignore();
            while(ss.peek() != ','){
                title += ss.get();
            }
            // check if borrow or return
            if(command == 'B') {
                borrowDrMovie(director, title, custID);
            }
            else if(command == 'R'){
                returnDrMovie(director, title, custID);
            }
            break;
        case 'C' :
            // gather pertinant infor for classics
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
            // check if borrow or return
            if(command == 'B') {
                borrowClMovie(month, year, actor, custID);
            }
            else if(command == 'R'){
                returnClMovie(month, year, actor, custID);
            }
            break;
        default :
            // notify user of invalid movie genre
            cout << "Invalid genre" << endl;
            break;
    }
}

// ------------------------------------------------ parseHistory -------------------------------------------------------
//  Parses a line of txt for a history (H) command
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::parseHistory(string line) {
    stringstream ss(line);
    ss.ignore();
    ss.ignore();

    // parse customer ID
    string custIDStr = "";
    int custID;
    for(int i = 0; i < 4; i++){
        custIDStr += ss.get();
    }
    custID = stoi(custIDStr);
    custHistory(custID);
}

// ------------------------------------------------ borrowClMovie ------------------------------------------------------
//  Executes commmand to borrow a classic movie
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::borrowClMovie(int month, int year, string actor, int custID) {

    // get the appropriate movie tree
    ClMovieTree* clMovies = movieInventory->getClMovies();
    // create temp movie for tree traversal
    ClassicMovie* movie = new ClassicMovie(0, "", "", actor, month, year);
    // pointer to hold actual movie
    ClassicMovie* moviePtr;
    // pointer to hold customer
    Customer* borrowCustomer;
    bool found;
    bool foundCust = customerTable->retrieveCustomer(custID, borrowCustomer);

    // if customer is valid
    if(foundCust) {
        found = clMovies->retrieve(*movie, moviePtr);
        // if movie is in inventory
        if (found) {
            // check stock
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

// ------------------------------------------------ borrowCoMovie ------------------------------------------------------
//  Executes commmand to borrow a comedy movie
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::borrowCoMovie(string title, int year, int custID) {

    // get the appropriate movie tree
    CoMovieTree* coMovies = movieInventory->getCoMovies();
    // create temp movie for tree traversal
    ComedyMovie* movie = new ComedyMovie(0, "", title, year);
    // pointer to hold actual movie
    ComedyMovie* moviePtr;
    // pointer to hold customer
    Customer* borrowCustomer;
    bool found;
    bool foundCust = customerTable->retrieveCustomer(custID, borrowCustomer);

    // if customer is valid
    if(foundCust) {
        found = coMovies->retrieve(*movie, moviePtr);
        if (found) {
            // check stock
            if (moviePtr->getStock() > 0) {
                moviePtr->setStock(moviePtr->getStock() - 1);
                string customerBorrow = "B D F " + title + ", " + to_string(year);
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

// ------------------------------------------------ borrowDrMovie ------------------------------------------------------
//  Executes commmand to borrow a drama movie
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::borrowDrMovie(string director, string title, int custID) {

    // get the appropriate movie tree
    DrMovieTree* drMovies = movieInventory->getDrMovies();
    // create temp movie for tree traversal
    DramaMovie* movie = new DramaMovie(0, director, title, 0);
    // pointer to hold actual movie
    DramaMovie* moviePtr;
    // pointer to hold customer
    Customer* borrowCustomer;
    bool found;
    bool foundCust = customerTable->retrieveCustomer(custID, borrowCustomer);

    // if customer is valid
    if(foundCust) {
        found = drMovies->retrieve(*movie, moviePtr);
        if (found) {
            // check stock
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

// ------------------------------------------------ returnCoMovie ------------------------------------------------------
//  Executes commmand to return a comedy movie
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::returnCoMovie(string title, int year, int custID) {

    CoMovieTree* coMovies = movieInventory->getCoMovies();
    ComedyMovie* movie = new ComedyMovie(0, "", title, year);
    // pointer to hold actual movie
    ComedyMovie* moviePtr;
    // pointer to hold customer
    Customer* returnCustomer;
    bool found;
    found = coMovies->retrieve(*movie, moviePtr);

    // if movie is valid
    if (found) {
        // if customer is valid
        bool foundCust = customerTable->retrieveCustomer(custID, returnCustomer);
        if (foundCust) {
            string customerBorrow = "B D F " + title + ", " + to_string(year);
            bool borrowed = returnCustomer->hasBorrowed(customerBorrow);
            // check if movie was previously borrowed by customer
            if (borrowed) {
                moviePtr->setStock(moviePtr->getStock() + 1);
                string customerReturn = "R D F " + title + ", " + to_string(year);
                returnCustomer->addHistory(customerReturn);
            }
            else
                cout << "Customer didn't borrow movie.\n";
        }
        else
            cout << "Customer not found.\n";
    }
    else {
        cout << "Movie not found.";
        delete moviePtr;
    }
    delete movie;
}

// ------------------------------------------------ returnClMovie ------------------------------------------------------
//  Executes commmand to return a classic movie
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::returnClMovie(int month, int year, string actor, int custID)
{
    ClMovieTree* clMovies = movieInventory->getClMovies();
    ClassicMovie* movie = new ClassicMovie(0, "", "", actor, month, year);
    // pointer to hold actual movie
    ClassicMovie* moviePtr;
    // pointer to hold customer
    Customer* returnCustomer;
    bool found;
    found = clMovies->retrieve(*movie, moviePtr);

    // if movie is valid
    if (found) {
        // if customer is valid
        bool foundCust = customerTable->retrieveCustomer(custID, returnCustomer);
        if (foundCust) {
            string customerBorrow = "B D C " + to_string(month) + ", " + to_string(year) + actor;
            bool borrowed = returnCustomer->hasBorrowed(customerBorrow);{
                // check if movie was previously borrowed by customer
                if (borrowed) {
                    moviePtr->setStock(moviePtr->getStock() + 1);
                    string customerReturn = "R D C " + to_string(month) + ", " + to_string(year) + actor;
                    returnCustomer->addHistory(customerReturn);
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

// ------------------------------------------------ returnDrMovie ------------------------------------------------------
//  Executes commmand to return a drama movie
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::returnDrMovie(string director, string title, int custID) {

    DrMovieTree* drMovies = movieInventory->getDrMovies();
    DramaMovie* movie = new DramaMovie(0, director, title, 0);
    // pointer to hold actual movie
    DramaMovie* moviePtr;
    // pointer to hold customer
    Customer* returnCustomer;
    bool found;
    found = drMovies->retrieve(*movie, moviePtr);

    // if movie is valid
    if (found) {
        // if customer is valid
        bool foundCust = customerTable->retrieveCustomer(custID, returnCustomer);
        if (foundCust) {
            string customerBorrow = "B D D " + director + ", " + title;
            bool borrowed = returnCustomer->hasBorrowed(customerBorrow);
            // check if movie was previously borrowed by customer
            if (borrowed) {
                moviePtr->setStock(moviePtr->getStock() + 1);
                string customerReturn = "R D D " + director + ", " + title;
                returnCustomer->addHistory(customerReturn);
                cout << "drama returned" << endl;

            }
            else
                cout << "Customer didn't borrow movie.\n";
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

// ------------------------------------------------ custHistory --------------------------------------------------------
//  Executes commmand to display customer history
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::custHistory(int custID) {

    // pointer to hold custmer object
    Customer* customer;

    // check if customer is in system
    bool found = customerTable->retrieveCustomer(custID, customer);
    if (found)
        customer->displayHistory();
}

// ------------------------------------------------ deleteStorage --------------------------------------------------------
//  Deletes storage pointers
// ---------------------------------------------------------------------------------------------------------------------
void LogicController::deleteStorage() {

    delete customerTable;
    delete movieInventory;
}









