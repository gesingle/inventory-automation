//
// Created by Garrett Singletary on 12/12/16.
//

#include "logiccontroller.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

LogicController::LogicController() {

}

void LogicController::buildMovieInventory() {

    movieInventory = new MovieStorage();
    // "/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4movies.txt"
    ifstream infile("/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4movies.txt");
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
    movieInventory->displayCoMovies();
    movieInventory->displayDrMovies();
    movieInventory->displayClMovies();
}

void LogicController::buildCustomerTable() {
    customerTable = new CustomerTable();

    ifstream custFile("/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4customers.txt");

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

void LogicController::buildCommands() {
    // "/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4commands.txt"
    ifstream infile("/Users/GSingletary/Desktop/School/CSS343/A4/assignment4_data/data4commands.txt");
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
                cout << "parsing borrow" << endl;
                parseBorrowReturn(line, command);
                break;
            case 'R' :
                cout << "parsing return" << endl;
                parseBorrowReturn(line, command);
                break;
            case 'H' :
                cout << "parsing history" << endl;
                parseHistory(line);
                break;
            case 'I' :
                cout << "parsing inventory" << endl;
                //displayMovieInventory();
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
            cout << "parsing a comedy" << endl;
            while(ss.peek() != ','){
                title += ss.get();
            }
            ss.ignore();
            ss.ignore();
            for(int i = 0; i < 4; i++){
                yearStr += ss.get();
            }
            year = stoi(yearStr);
            break;
        case 'D' :
            cout << "parsing a drama" << endl;

            while(ss.peek() != ','){
                director += ss.get();
            }
            ss.ignore();
            ss.ignore();
            while(ss.peek() != ','){
                title += ss.get();
            }
            break;
        case 'C' :
            cout << "parsing a classic" << endl;
            ss >> monthStr;
            ss.ignore();
            for(int i = 0; i < 4; i++){
                yearStr += ss.get();
            }
            ss.ignore();
            while(ss.peek() != EOF){
                actor += ss.get();
            }
            month = stoi(monthStr);
            year = stoi(yearStr);
            break;
        default :
            cout << "Invalid genre" << endl;
            break;
    }
}

void LogicController::parseHistory(string line) {

    stringstream ss(line);
    ss.ignore();

    string custIDStr = "";
    int custID;
    for(int i = 0; i < 4; i++){
        custIDStr += ss.get();
    }
    custID = stoi(custIDStr);
}






