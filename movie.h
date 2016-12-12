//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef INC_343A4_MOVIE_H
#define INC_343A4_MOVIE_H

#include "item.h"
#include <string>

using namespace std;

class Movie: public Item {

public:
    Movie();
    int getYear();
    string getDirector();
    string getTitle();
    enum getGenre();

protected:
    int releaseYear;
    string title;
    string director;
    char mediaType;
    char genre;




};


#endif //INC_343A4_MOVIE_H
