//
// Created by Garrett Singletary on 12/12/16.
//

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
            borrowCoMovie(title, year, custID);
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
            borrowDrMovie(director, title);
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
            month = stoi(monthStr);
            year = stoi(yearStr);
            borrowClMovie(month, year, actor);
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
void LogicController::borrowClMovie(int month, int year, string actor) {

    cout << "borrowing Cl" << endl;
    cout << month << ":" << year << ":" << actor << endl;
    ClMovieTree* clMovies = movieInventory->getClMovies();
    ClassicMovie* movie = new ClassicMovie(0, "", "", actor, month, year);
    ClassicMovie* moviePtr;
    bool found;
    found = clMovies->retrieve(*movie, moviePtr);
    if(found){
        if(moviePtr->getStock() > 0){
            moviePtr->setStock(moviePtr->getStock() - 1);
        }
        else{
            cout << "Movie is out of stock" << endl;
        }
    }
    else{
        cout << "Movie not found." << endl;
    }
    delete movie;
}

void LogicController::borrowCoMovie(string title, int year, int custID) {

    cout << "borrowing Co" << endl;
    CoMovieTree* coMovies = movieInventory->getCoMovies();
    ComedyMovie* movie = new ComedyMovie(0, "", title, year);
    ComedyMovie* moviePtr;
    bool found;
    found = coMovies->retrieve(*movie, moviePtr);
    if(found){
        if(moviePtr->getStock() > 0){
            moviePtr->setStock(moviePtr->getStock() - 1);
        }
        else{
            cout << "Movie is out of stock" << endl;
        }
        //delete moviePtr;
    }
    else{
        cout << "Movie not found." << endl;
    }
    delete movie;
}

void LogicController::borrowDrMovie(string director, string title) {

    cout << "borrowing Dr" << endl;
    DrMovieTree* drMovies = movieInventory->getDrMovies();
    DramaMovie* movie = new DramaMovie(0, director, title, 0);
    DramaMovie* moviePtr;
    bool found;
    found = drMovies->retrieve(*movie, moviePtr);
    if(found){
        if(moviePtr->getStock() > 0){
            moviePtr->setStock(moviePtr->getStock() - 1);
        }
        else{
            cout << "Movie is out of stock" << endl;
        }
    }
    else{
        cout << "Movie not found." << endl;
    }
    delete movie;
}

void LogicController::returnMovie(const Movie* movie, int custID) {

}

void LogicController::custHistory(int custID) {

}










