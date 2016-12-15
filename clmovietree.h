/* ------------------------------------------------ clmovietree.h ------------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class implements a binary search tree to hold classic movies.
 -----------------------------------------------------------------------------------------------------------------------
*/

#ifndef CLMOVIETREE_H
#define CLMOVIETREE_H

#include <iostream>
#include "classicmovie.h"

class ClMovieTree {

public:
    ClMovieTree();
    ~ClMovieTree();
    bool insert(ClassicMovie* movie);
    void display() const;
    bool retrieve(const ClassicMovie&, ClassicMovie* &) const;

private:
    struct MovieNode {
        ClassicMovie* movie;		// pointer to data object
        MovieNode* left;			// left subtree pointer
        MovieNode* right;		// right subtree pointer
    };
    MovieNode* root = NULL;	    // root of the tree
    void displayHelper(MovieNode*) const;
    void makeEmpty();
    void deleteNode(MovieNode*&);
};


#endif //INC_343A4_MOVIETREE_H
