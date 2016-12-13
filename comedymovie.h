//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef INC_343A4_COMEDYMOVIE_H
#define INC_343A4_COMEDYMOVIE_H

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
