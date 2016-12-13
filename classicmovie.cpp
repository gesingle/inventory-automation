//
// Created by Garrett Singletary on 11/27/16.
//
#include <iostream>
#include "classicmovie.h"

ClassicMovie::ClassicMovie(int s, string d, string t, string a, int m, int y) {
    stock = s;
    director = d;
    title = t;
    actor = a;
    releaseMonth = m;
    releaseYear = y;
}

bool ClassicMovie::operator<(const ClassicMovie& clmovie) {

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

bool ClassicMovie::operator>(const ClassicMovie& clmovie) {

    if(this-> title > clmovie.getTitle()){
        return true;
    }

    if(this->releaseYear == clmovie.getYear()){
        if(this->releaseMonth > clmovie.getReleaseMonth()){
            return true;
        }
        if(this->releaseMonth == clmovie.getReleaseMonth()) {
            return this->actor > clmovie.getActor();
        }
    }

    return false;
}

bool ClassicMovie::operator==(const ClassicMovie& clmovie) {

    return (this->releaseYear == clmovie.getYear()) && (this->actor == clmovie.getActor());

}

string ClassicMovie::getActor() const{
    return this->actor;
}

int ClassicMovie::getReleaseMonth() const{
    return releaseMonth;
}