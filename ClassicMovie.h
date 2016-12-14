//
// Created by Garrett Singletary on 11/27/16.
//
//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef CLASSICMOVIE_H
#define CLASSICMOVIE_H

#include "movie.h"

class ClassicMovie : public Movie {

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