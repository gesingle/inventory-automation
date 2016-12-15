/* ------------------------------------------------ comedymovie.h ------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class defines the functionality of a comedy movie.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "movie.h"

using namespace std;

class ComedyMovie: public Movie {

public:
    ComedyMovie(int, string, string, int);
    bool operator<(const ComedyMovie&) const;
    bool operator>(const ComedyMovie&) const;
    bool operator==(const ComedyMovie&) const;
};


#endif //INC_343A4_COMEDYMOVIE_H
