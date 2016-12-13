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
    int getYear() const;
    string getDirector() const;
    string getTitle() const;
    char getGenre() const;
    int getStock() const;
    void addToInventory() const;
    void setStock(int);


protected:
    int releaseYear;
    string title;
    string director;
    char mediaType;
    char genre;
    int stock;
}
;


#endif //INC_343A4_MOVIE_H
