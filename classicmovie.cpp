/* ------------------------------------------------ classicmovie.cpp -----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class defines the functionality of a classic movie.
 -----------------------------------------------------------------------------------------------------------------------
*/

#include <iostream>
#include "classicmovie.h"

// ------------------------------------------------ ClassicMovie -------------------------------------------------------
//  Constructor
// ---------------------------------------------------------------------------------------------------------------------
ClassicMovie::ClassicMovie(int s, string d, string t, string a, int m, int y) {
    stock = s;
    director = d;
    title = t;
    actor = a;
    releaseMonth = m;
    releaseYear = y;
    genre = 'C';
}

// ------------------------------------------------ operator< ----------------------------------------------------------
//  Overload for <
// ---------------------------------------------------------------------------------------------------------------------
bool ClassicMovie::operator<(const ClassicMovie& clmovie) const{

    // check by release date then major actor
    if(this->releaseYear < clmovie.getYear()){
        return true;
    }

    if(this->releaseYear == clmovie.getYear()){
        if(this->releaseMonth < clmovie.getReleaseMonth()){
            return true;
        }
        if(this->releaseMonth == clmovie.getReleaseMonth()) {
            return this->actor < clmovie.getActor();
        }
    }

    return false;
}

// ------------------------------------------------ operator> ----------------------------------------------------------
//  Overload for >
// ---------------------------------------------------------------------------------------------------------------------
bool ClassicMovie::operator>(const ClassicMovie& clmovie) const{

    // check by release date then major actor
    if(this->releaseYear > clmovie.getYear()){
        return true;
    }

    if(this->releaseYear == clmovie.getYear()){
        if(this->releaseMonth > clmovie.getReleaseMonth()){
            return true;
        }
        if(this->releaseMonth == clmovie.getReleaseMonth()) {
            return (this->actor > clmovie.getActor());
        }
    }

    return false;
}

// ------------------------------------------------ operator== ---------------------------------------------------------
//  Overload for ==
// ---------------------------------------------------------------------------------------------------------------------
bool ClassicMovie::operator==(const ClassicMovie& clmovie) const{

    // check by release date then major actor
    return (this->releaseYear == clmovie.getYear()) && (this->releaseMonth == clmovie.getReleaseMonth()) &&
            (this->actor == clmovie.getActor());

}

// ------------------------------------------------ getActor -----------------------------------------------------------
//  Returns the film's actor
// ---------------------------------------------------------------------------------------------------------------------
string ClassicMovie::getActor() const{
    return actor;
}

// ------------------------------------------------ getReleaseMonth ----------------------------------------------------
//  Returns the films release month
// ---------------------------------------------------------------------------------------------------------------------
int ClassicMovie::getReleaseMonth() const{
    return releaseMonth;
}
