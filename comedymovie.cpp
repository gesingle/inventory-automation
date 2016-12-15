/* ------------------------------------------------ comedymovie.cpp ----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class defines the functionality of a comedy movie.
 -----------------------------------------------------------------------------------------------------------------------
*/

#include "comedymovie.h"

// ------------------------------------------------ ComedyMovie --------------------------------------------------------
//  Constructor
// ---------------------------------------------------------------------------------------------------------------------
ComedyMovie::ComedyMovie(int s, string d, string t, int y) {
    stock = s;
    director = d;
    title = t;
    releaseYear = y;
    genre = 'F';
}

// ------------------------------------------------ operator< ----------------------------------------------------------
//  Overload for <
// ---------------------------------------------------------------------------------------------------------------------
bool ComedyMovie::operator<(const ComedyMovie& comovie) const{

    // check by title then release year
    if(this->title < comovie.getTitle()){
        return true;
    }

    if(this->title == comovie.getTitle()){
        return (this->releaseYear < comovie.getYear()) ? true : false;
    }

    return false;
}

// ------------------------------------------------ operator> ----------------------------------------------------------
//  Overload for >
// ---------------------------------------------------------------------------------------------------------------------
bool ComedyMovie::operator>(const ComedyMovie& comovie) const{

    // check by title then release year
    if(this-> title > comovie.getTitle()){
        return true;
    }

    if(this->title == comovie.getTitle()){
        return (this->releaseYear > comovie.getYear()) ? true : false;
    }

    return false;
}

// ------------------------------------------------ operator== ---------------------------------------------------------
//  Overload for ==
// ---------------------------------------------------------------------------------------------------------------------
bool ComedyMovie::operator==(const ComedyMovie& comovie) const{

    // check by title then release year
    return (this->title == comovie.getTitle()) && (this->releaseYear == comovie.getYear()) ? true : false;

}
