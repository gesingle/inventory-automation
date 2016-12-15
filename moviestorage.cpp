/* ------------------------------------------------ moviestorage.cpp -----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class holds binary search trees for the various movie genres with functionality to add movies as well as to get
 and display the individual trees
 -----------------------------------------------------------------------------------------------------------------------
*/

#include "moviestorage.h"

// ------------------------------------------------ MovieStorage -------------------------------------------------------
//  Constructor
// ---------------------------------------------------------------------------------------------------------------------
MovieStorage::MovieStorage() {

    clMovies = new ClMovieTree();
    coMovies = new CoMovieTree();
    drMovies = new DrMovieTree();
}

// ------------------------------------------------ ~MovieStorage ------------------------------------------------------
//  Destructor
// ---------------------------------------------------------------------------------------------------------------------
MovieStorage::~MovieStorage() {
    delete clMovies;
    delete coMovies;
    delete drMovies;

}
// ------------------------------------------------ addClMovie ---------------------------------------------------------
//  Parses movie info and adds it to classic tree
// ---------------------------------------------------------------------------------------------------------------------
void MovieStorage::addClMovie(string txtLine) {

    // parse appropriate info from the line of txt
    stringstream ss(txtLine);
    ss.ignore(256, ' ');

    //stock
    string stockStr;
    int stock;
    while(ss.peek() != ','){
        stockStr += ss.get();
    }
    ss.ignore();
    ss.ignore();

    stock = stoi(stockStr);

    // director
    string director = "";
    while(ss.peek() != ','){
        director += ss.get();
    }
    ss.ignore();
    ss.ignore();

    // title
    string title = "";
    while(ss.peek() != ','){
        title += ss.get();
    }
    ss.ignore();
    ss.ignore();

    //actor
    string actor = "";
    while(ss.peek() != ' '){
        actor += ss.get();
    }
    actor += ss.get();
    while(ss.peek() != ' '){
        actor += ss.get();
    }
    ss.ignore();

    // month
    string monthStr = "";
    int month;
    while(ss.peek() != ' '){
        monthStr += ss.get();
    }
    ss.ignore();
    month = stoi(monthStr);

    //year
    string yearStr = "";
    int year;
    for(int i = 0; i < 4; i++){
        yearStr += ss.get();
    }
    year = stoi(yearStr);

    // create new movie and add to tree
    ClassicMovie* clMovie = new ClassicMovie(stock, director, title, actor, month, year);
    clMovies->insert(clMovie);
}

// ------------------------------------------------ addCoMovie ---------------------------------------------------------
//  Parses movie info and adds it to comedy tree
// ---------------------------------------------------------------------------------------------------------------------
void MovieStorage::addCoMovie(string txtLine) {

    // parse appropriate info from the line of txt
    stringstream ss(txtLine);
    ss.ignore(256, ' ');

    //stock
    string stockStr;
    int stock;
    while(ss.peek() != ','){
        stockStr += ss.get();
    }
    ss.ignore();
    ss.ignore();

    stock = stoi(stockStr);

    // director
    string director = "";
    while(ss.peek() != ','){
        director += ss.get();
    }
    ss.ignore();
    ss.ignore();

    // title
    string title = "";
    while(ss.peek() != ','){
        title += ss.get();
    }
    ss.ignore();
    ss.ignore();

    // year
    string yearStr = "";
    int year;
    for(int i = 0; i < 4; i++){
        yearStr += ss.get();
    }
    year = stoi(yearStr);

    // create new movie and add to tree
    ComedyMovie* coMovie = new ComedyMovie(stock, director, title, year);
    coMovies->insert(coMovie);
}

// ------------------------------------------------ addDrMovie ---------------------------------------------------------
//  Parses movie info and adds it to drama tree
// ---------------------------------------------------------------------------------------------------------------------
void MovieStorage::addDrMovie(string txtLine) {

    // parse appropriate info from the line of txt
    stringstream ss(txtLine);
    ss.ignore(256, ' ');

    // stock
    string stockStr;
    int stock;
    while(ss.peek() != ','){
        stockStr += ss.get();
    }
    ss.ignore();
    ss.ignore();

    stock = stoi(stockStr);

    // director
    string director = "";
    while(ss.peek() != ','){
        director += ss.get();
    }
    ss.ignore();
    ss.ignore();

    // title
    string title = "";
    while(ss.peek() != ','){
        title += ss.get();
    }
    ss.ignore();
    ss.ignore();

    // year
    string yearStr = "";
    int year;
    for(int i = 0; i < 4; i++){
        yearStr += ss.get();
    }
    year = stoi(yearStr);

    // create new movie and add to tree
    DramaMovie* drMovie = new DramaMovie(stock, director, title, year);
    drMovies->insert(drMovie);
}

// ------------------------------------------------ displayClMovies ----------------------------------------------------
//  Displays all movies in the classic tree
// ---------------------------------------------------------------------------------------------------------------------
void MovieStorage::displayClMovies() {
    clMovies->display();
}

// ------------------------------------------------ displayCoMovies ----------------------------------------------------
//  Displays all movies in the comedy tree
// ---------------------------------------------------------------------------------------------------------------------
void MovieStorage::displayCoMovies() {
    coMovies->display();
}

// ------------------------------------------------ displayDrMovies ----------------------------------------------------
//  Displays all movies in the drama tree
// ---------------------------------------------------------------------------------------------------------------------
void MovieStorage::displayDrMovies() {
    drMovies->display();
}

// ------------------------------------------------ getClMovies --------------------------------------------------------
//  Displays all movies in the classic tree
// ---------------------------------------------------------------------------------------------------------------------
ClMovieTree *MovieStorage::getClMovies() {
    return clMovies;
}

// ------------------------------------------------ getCoMovies --------------------------------------------------------
//  Displays all movies in the comedy tree
// ---------------------------------------------------------------------------------------------------------------------
CoMovieTree *MovieStorage::getCoMovies() {
    return coMovies;
}

// ------------------------------------------------ getDrMovies --------------------------------------------------------
//  Displays all movies in the drama tree
// ---------------------------------------------------------------------------------------------------------------------
DrMovieTree *MovieStorage::getDrMovies() {
    return drMovies;
}





