/* ------------------------------------------------ dramamovie.cpp -----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class defines the functionality of a drama movie.
 -----------------------------------------------------------------------------------------------------------------------
*/

#include "dramamovie.h"

// ------------------------------------------------ ComedyMovie --------------------------------------------------------
//  Constructor
// ---------------------------------------------------------------------------------------------------------------------
DramaMovie::DramaMovie(int s, string d, string t, int y) {
    stock = s;
    director = d;
    title = t;
    releaseYear = y;
    genre = 'D';
}

// ------------------------------------------------ operator< ----------------------------------------------------------
//  Overload for <
// ---------------------------------------------------------------------------------------------------------------------
bool DramaMovie::operator<(const DramaMovie& dmovie) const{

    // check by director then title
    if(this->director < dmovie.getDirector()){
        return true;
    }

    if(this->director == dmovie.getDirector()){
        return (this->title < dmovie.getTitle());
    }

    return false;
}

// ------------------------------------------------ operator> ----------------------------------------------------------
//  Overload for >
// ---------------------------------------------------------------------------------------------------------------------
bool DramaMovie::operator>(const DramaMovie& dmovie) const{

    // check by director then title
    if(this->director > dmovie.getDirector()){
        return true;
    }

    if(this->director == dmovie.getDirector()){
        return (this->title > dmovie.getTitle());
    }

    return false;
}

// ------------------------------------------------ operator== ---------------------------------------------------------
//  Overload for ==
// ---------------------------------------------------------------------------------------------------------------------
bool DramaMovie::operator==(const DramaMovie& dmovie) const{

    // check by director then title
    return (this->director == dmovie.getDirector()) && (this->title == dmovie.getTitle());
}
