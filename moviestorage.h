/* ------------------------------------------------ moviestorage.h -----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class holds binary search trees for the various movie genres with functionality to add movies as well as to get
 and display the individual trees
 -----------------------------------------------------------------------------------------------------------------------
*/

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
    ~MovieStorage();
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
