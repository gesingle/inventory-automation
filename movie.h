/* ------------------------------------------------ movie.h ------------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class is a parent class for all movies.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef MOVIE_H
#define MOVIE_H

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
