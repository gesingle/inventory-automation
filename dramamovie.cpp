//
// Created by Garrett Singletary on 11/27/16.
//

#include "dramamovie.h"

DramaMovie::DramaMovie(int s, string d, string t, int y) {
    stock = s;
    director = d;
    title = t;
    releaseYear = y;
    genre = 'D';
}

bool DramaMovie::operator<(const DramaMovie& dmovie) {

    if(this->director < dmovie.getDirector()){
        return true;
    }

    if(this->director == dmovie.getDirector()){
        return (this->title < dmovie.getTitle());
    }

    return false;
}

bool DramaMovie::operator>(const DramaMovie& dmovie) {

    if(this->director > dmovie.getDirector()){
        return true;
    }

    if(this->director == dmovie.getDirector()){
        return (this->title > dmovie.getTitle());
    }

    return false;
}

bool DramaMovie::operator==(const DramaMovie& dmovie) {

    return (this->director == dmovie.getDirector()) && (this->title == dmovie.getTitle());
}
