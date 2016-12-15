/* ------------------------------------------------ drmovietree.h ------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class implements a binary search tree to hold drama movies.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef DRMOVIETREE_H
#define DRMOVIETREE_H

#include <iostream>
#include "dramamovie.h"

class DrMovieTree {

public:
    DrMovieTree();
    bool insert(DramaMovie* movie);
    void display() const;
    bool retrieve(const DramaMovie&, DramaMovie* &) const;

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
