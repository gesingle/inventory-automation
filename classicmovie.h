/* ------------------------------------------------ classicmovie.h -----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class defines the functionality of a classic movie.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H

#include "movie.h"

class ClassicMovie: public Movie{

public:
    ClassicMovie(int, string, string, string, int, int);
    bool operator<(const ClassicMovie&) const;
    bool operator>(const ClassicMovie&) const;
    bool operator==(const ClassicMovie&) const;
    string getActor() const;
    int getReleaseMonth() const;

private:
    string actor;
    int releaseMonth;
};

#endif //INC_343A4_CLASSICMOVIE_H
