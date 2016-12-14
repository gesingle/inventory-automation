//
// Created by Garrett Singletary on 11/27/16.
//

#include "movie.h"

int Movie::getYear() const{
    return releaseYear;
}

string Movie::getDirector() const{
    return director;
}

string Movie::getTitle() const{
    return title;
}

char Movie::getGenre() const{
     return genre;
}

int Movie::getStock() const {
    return stock;
}

void Movie::addToInventory() const {

}

void Movie::setStock(int s) {
    stock = s;
}

Movie::Movie() {

}
