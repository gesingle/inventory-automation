//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef INC_343A4_CLASSICMOVIE_H
#define INC_343A4_CLASSICMOVIE_H

#include "movie.h"

class ClassicMovie: public Movie{

public:
    ClassicMovie(int, string, string, string, int);
    bool operator<(const ClassicMovie&);
    bool operator>(const ClassicMovie&);
    bool operator==(const ClassicMovie&);
    string getActor() const;

private:
    string actor;
};


#endif //INC_343A4_CLASSICMOVIE_H
