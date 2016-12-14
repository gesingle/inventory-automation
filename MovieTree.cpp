//
// Created by Garrett Singletary on 12/12/16.
//

#include "MovieTree.h"

MovieTree::MovieTree() {

}

void MovieTree::insert(Movie *m) {

	// initialize root if tree is empty
	if (root == NULL) {
		root = new MovieNode();
		root->movie = m;
	}

	else {
		// temp Node for tree traversal
		MovieNode* current = root;
		while (true) {
			// discard duplicates
			if (*m == *current->movie) {
				return;
			}
			if (*m < *current->movie) {
				if (current->left == NULL) {
					current->left = new MovieNode();
					current->left->movie = m;
					return;
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
					return;
				}
				else {
					current = current->right;
					continue;
				}
			}
		}
	}
}

void MovieTree::displayHelper(MovieTree::MovieNode* node) const {

	if (node != NULL) {
		displayHelper(node->left);
		cout << node->movie->getYear() << endl;
		displayHelper(node->right);
	}
}

void MovieTree::display() const {
	displayHelper(this->root);
}