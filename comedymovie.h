//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef COMEDYMOVIE_H
#define COMEDYMOVIE_H

#include "movie.h"

using namespace std;

class ComedyMovie: public Movie {

public:
    ComedyMovie(int, string, string, int);
    bool operator<(const ComedyMovie&);
    bool operator>(const ComedyMovie&);
    bool operator==(const ComedyMovie&);
};


#endif //INC_343A4_COMEDYMOVIE_H
