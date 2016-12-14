//
// Created by Garrett Singletary on 12/13/16.
//

#ifndef DRMOVIETREE_H
#define DRMOVIETREE_H

#include <iostream>
#include "dramamovie.h"

class DrMovieTree {

public:
    DrMovieTree();
    bool insert(DramaMovie* movie);
    void display() const;

private:
    struct MovieNode {
        DramaMovie* movie;		// pointer to data object
        MovieNode* left;			// left subtree pointer
        MovieNode* right;		// right subtree pointer
    };
    MovieNode* root = NULL;	    // root of the tree
    void displayHelper(MovieNode*) const;
};


#endif //INC_343A4_DRMOVIETREE_H
