//
// Created by Garrett Singletary on 12/12/16.
//

#ifndef INC_343A4_MOVIETREE_H
#define INC_343A4_MOVIETREE_H

#include <iostream>
#include "movie.h"

class MovieTree {

public:
    MovieTree();
    void insert(Movie* movie);
    void display() const;

private:
    struct MovieNode {
        Movie* movie;		// pointer to data object
        MovieNode* left;			// left subtree pointer
        MovieNode* right;		// right subtree pointer
    };
    MovieNode* root = NULL;	    // root of the tree
    void displayHelper(MovieNode*) const;
};


#endif //INC_343A4_MOVIETREE_H
