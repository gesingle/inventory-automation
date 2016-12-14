//
// Created by Garrett Singletary on 12/13/16.
//

#ifndef COMOVIETREE_H
#define COMOVIETREE_H

#include <iostream>
#include "comedymovie.h"

class CoMovieTree {

public:
	CoMovieTree();
	bool insert(ComedyMovie* movie);
	void display() const;

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