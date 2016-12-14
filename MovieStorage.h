//
// Created by Garrett Singletary on 12/12/16.
//

//
// Created by Garrett Singletary on 12/12/16.
//

#ifndef MOVIESTORAGE_H
#define MOVIESTORAGE_H

#include <iostream>
#include <fstream>
#include <sstream>
#include "classicmovie.h"
#include "comedymovie.h"
#include "dramamovie.h"
#include "classicmovie.h"
#include "clmovietree.h"
#include "comovietree.h"
#include "drmovietree.h"

class MovieStorage {

public:
	MovieStorage();
	void addClMovie(string);
	void addCoMovie(string);
	void addDrMovie(string);
	void displayClMovies();
	void displayCoMovies();
	void displayDrMovies();
	ClMovieTree* getClMovies();
	CoMovieTree* getCoMovies();
	DrMovieTree* getDrMovies();

private:
	ClMovieTree* clMovies = NULL;
	CoMovieTree* coMovies = NULL;
	DrMovieTree* drMovies = NULL;
};


#endif //INC_343A4_MOVIESTORAGE_H