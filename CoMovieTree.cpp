//
// Created by Garrett Singletary on 12/13/16.
//

#include "comovietree.h"

CoMovieTree::CoMovieTree() {
}

bool CoMovieTree::insert(ComedyMovie *m) {

	// initialize root if tree is empty
	if (root == NULL) {
		root = new MovieNode();
		root->movie = m;
	}

	else {
		// temp Node for tree traversal
		MovieNode* current = root;
		while (true) {
			if (*m < *current->movie) {
				if (current->left == NULL) {
					current->left = new MovieNode();
					current->left->movie = m;
					return true;
				}
				else {
					current = current->left;
					continue;
				}
			}
			if (*m > *current->movie) {
				if (current->right == NULL) {
					current->right = new MovieNode();
					current->right->movie = m;
					return true;
				}
				else {
					current = current->right;
					continue;
				}
			}
		}
	}
	return false;
}

void CoMovieTree::displayHelper(MovieNode* node) const {

	if (node != NULL) {
		displayHelper(node->left);
		cout << node->movie->getStock() << " " << node->movie->getTitle() << " " << node->movie->getYear() << endl;
		displayHelper(node->right);
	}
}

void CoMovieTree::display() const {
	displayHelper(this->root);
}

bool CoMovieTree::retrieve(const ComedyMovie& movie, ComedyMovie*& moviePtr) const {

	// temp node for tree traversal
	MovieNode* current = root;
	bool found = false;

	while (!found) {
		if (movie < *current->movie) {
			if (current->left == NULL) {
				return false;
			}
			else
				current = current->left;
		}
		else if (movie > *current->movie) {
			if (current->right == NULL) {
				return false;
			}
			else
				current = current->right;
		}
		else {
			moviePtr = current->movie;
			found = true;
		}
	}

	return true;
}


