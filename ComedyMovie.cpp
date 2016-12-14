//
// Created by Garrett Singletary on 11/27/16.
//

#include "comedymovie.h"

ComedyMovie::ComedyMovie(int s, string d, string t, int y) {
	stock = s;
	director = d;
	title = t;
	releaseYear = y;
	genre = 'F';
}

bool ComedyMovie::operator<(const ComedyMovie& comovie) const {

	if (this->title < comovie.getTitle()) {
		return true;
	}

	if (this->title == comovie.getTitle()) {
		return (this->releaseYear < comovie.getYear()) ? true : false;
	}

	return false;
}

bool ComedyMovie::operator>(const ComedyMovie& comovie) const {

	if (this->title > comovie.getTitle()) {
		return true;
	}

	if (this->title == comovie.getTitle()) {
		return (this->releaseYear > comovie.getYear()) ? true : false;
	}

	return false;
}

bool ComedyMovie::operator==(const ComedyMovie& comovie) const {

	return (this->title == comovie.getTitle()) && (this->releaseYear == comovie.getYear()) ? true : false;

}