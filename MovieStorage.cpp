//
// Created by Garrett Singletary on 12/12/16.
//

#include "MovieStorage.h"

MovieStorage::MovieStorage() {

    clMovies = new ClMovieTree();
    coMovies = new CoMovieTree();
    drMovies = new DrMovieTree();
}

void MovieStorage::addClMovie(string txtLine) {

    stringstream ss(txtLine);
    ss.ignore(256, ' ');

    string stockStr;
    int stock;
    while(ss.peek() != ','){
        stockStr += ss.get();
    }
    ss.ignore();
    ss.ignore();

    stock = stoi(stockStr);

    string director = "";
    while(ss.peek() != ','){
        director += ss.get();
    }
    ss.ignore();
    ss.ignore();

    string title = "";
    while(ss.peek() != ','){
        title += ss.get();
    }
    ss.ignore();
    ss.ignore();

    string actor = "";
    while(ss.peek() != ' '){
        actor += ss.get();
    }
    actor += ss.get();
    while(ss.peek() != ' '){
        actor += ss.get();
    }
    ss.ignore();

    string monthStr = "";
    int month;
    while(ss.peek() != ' '){
        monthStr += ss.get();
    }
    ss.ignore();
    month = stoi(monthStr);

    string yearStr = "";
    int year;
    for(int i = 0; i < 4; i++){
        yearStr += ss.get();
    }
    year = stoi(yearStr);

/*
    cout << stock << endl;
    cout << director << endl;
    cout << title << endl;
    cout << actor << endl;
    cout << month << endl;
    cout << year << endl;
*/

    ClassicMovie* clMovie = new ClassicMovie(stock, director, title, actor, month, year);
    clMovies->insert(clMovie);
    //cout << "added clMovie" << endl;
}

void MovieStorage::addCoMovie(string txtLine) {

    stringstream ss(txtLine);
    ss.ignore(256, ' ');
    string stockStr;
    int stock;
    while(ss.peek() != ','){
        stockStr += ss.get();
    }
    ss.ignore();
    ss.ignore();

    stock = stoi(stockStr);

    string director = "";
    while(ss.peek() != ','){
        director += ss.get();
    }
    ss.ignore();
    ss.ignore();

    string title = "";
    while(ss.peek() != ','){
        title += ss.get();
    }
    ss.ignore();
    ss.ignore();

    string yearStr = "";
    int year;
    for(int i = 0; i < 4; i++){
        yearStr += ss.get();
    }
    year = stoi(yearStr);

    /*
    cout << stock << endl;
    cout << director << endl;
    cout << title << endl;
    cout << year << endl;
     */

    ComedyMovie* coMovie = new ComedyMovie(stock, director, title, year);
    coMovies->insert(coMovie);
    //cout << "added coMovie" << endl;
}


void MovieStorage::addDrMovie(string txtLine) {

    stringstream ss(txtLine);
    ss.ignore(256, ' ');
    string stockStr;
    int stock;
    while(ss.peek() != ','){
        stockStr += ss.get();
    }
    ss.ignore();
    ss.ignore();

    stock = stoi(stockStr);

    string director = "";
    while(ss.peek() != ','){
        director += ss.get();
    }
    ss.ignore();
    ss.ignore();

    string title = "";
    while(ss.peek() != ','){
        title += ss.get();
    }
    ss.ignore();
    ss.ignore();

    string yearStr = "";
    int year;
    for(int i = 0; i < 4; i++){
        yearStr += ss.get();
    }
    year = stoi(yearStr);

    /*
    cout << stock << endl;
    cout << director << endl;
    cout << title << endl;
    cout << year << endl;
     */

    DramaMovie* drMovie = new DramaMovie(stock, director, title, year);
    drMovies->insert(drMovie);
    //cout << "added drMovie" << endl;
}

void MovieStorage::displayClMovies() {
    clMovies->display();
}

void MovieStorage::displayCoMovies() {
    coMovies->display();
}

void MovieStorage::displayDrMovies() {
    drMovies->display();
}


