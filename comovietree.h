/* ------------------------------------------------ comovietree.h ------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class implements a binary search tree to hold comedy movies.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef COMOVIETREE_H
#define COMOVIETREE_H

#include <iostream>
#include "comedymovie.h"

class CoMovieTree {

public:
    CoMovieTree();
    bool insert(ComedyMovie* movie);
    void display() const;
    bool retrieve(const ComedyMovie&, ComedyMovie* &) const;

private:
    struct MovieNode {
        ComedyMovie* movie;		// pointer to data object
        MovieNode* left;			// left subtree pointer
        MovieNode* right;		// right subtree pointer
    };
    MovieNode* root = NULL;	    // root of the tree
    void displayHelper(MovieNode*) const;
};


#endif //INC_343A4_COMOVIETREE_H
