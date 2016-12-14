//
// Created by Garrett Singletary on 12/12/16.
//

#ifndef CLMOVIETREE_H
#define CLMOVIETREE_H

#include <iostream>
#include "classicmovie.h"

class ClMovieTree {

public:
    ClMovieTree();
    bool insert(ClassicMovie* movie);
    void display() const;

private:
    struct MovieNode {
        ClassicMovie* movie;		// pointer to data object
        MovieNode* left;			// left subtree pointer
        MovieNode* right;		// right subtree pointer
    };
    MovieNode* root = NULL;	    // root of the tree
    void displayHelper(MovieNode*) const;
};


#endif //INC_343A4_MOVIETREE_H
