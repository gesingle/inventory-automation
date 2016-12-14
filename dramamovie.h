//
// Created by Garrett Singletary on 11/27/16.
//

#ifndef DRAMAMOVIE_H
#define DRAMAMOVIE_H

#include "movie.h"

class DramaMovie: public Movie {

public:
    DramaMovie(int, string, string, int);
    bool operator<(const DramaMovie&);
    bool operator>(const DramaMovie&);
    bool operator==(const DramaMovie&);
};

#endif //INC_343A4_DRAMAMOVIE_H

