//
// Created by Garrett Singletary on 12/12/16.
//

#ifndef INC_343A4_MOVIESTORAGE_H
#define INC_343A4_MOVIESTORAGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "classicmovie.h"
#include "comedymovie.h"
#include "classicmovie.h"
#include "movietree.h"

class MovieStorage {

public:
	MovieStorage();
	void addClMovie(string);
	void addCoMovie(string);
	void addDrMovie(string);
	void displayClMovies();
	void displayCoMovies();
	void displayDrMovies();

private:
	MovieTree* clMovies = NULL;
	MovieTree* coMovies = NULL;
	MovieTree* drMovies = NULL;
};


#endif //INC_343A4_MOVIESTORAGE_H