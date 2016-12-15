/* ------------------------------------------------ dramamovie.h -------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class defines the functionality of a classic movie.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"

class DramaMovie: public Movie {

public:
    DramaMovie(int, string, string, int);
    bool operator<(const DramaMovie&) const;
    bool operator>(const DramaMovie&) const;
    bool operator==(const DramaMovie&) const;
};

#endif //INC_343A4_DRAMAMOVIE_H

