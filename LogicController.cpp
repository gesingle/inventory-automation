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
}

void LogicController::displayMovieInventory() {
    movieInventory->displayCoMovies();
    movieInventory->displayDrMovies();
    movieInventory->displayClMovies();
}


