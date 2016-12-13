//
// Created by Garrett Singletary on 12/13/16.
//

#include "DrMovieTree.h"

DrMovieTree::DrMovieTree() {

}

bool DrMovieTree::insert(DramaMovie *m) {

    // initialize root if tree is empty
    if(root == NULL){
        root = new MovieNode();
        root->movie = m;
    }

    else {
        // temp Node for tree traversal
        MovieNode* current = root;
        while(true) {
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
}

void DrMovieTree::displayHelper(MovieNode* node) const{

    if(node != NULL){
        displayHelper(node->left);
        cout << node->movie->getDirector() << " " << node->movie->getTitle() << endl;
        displayHelper(node->right);
    }
}

void DrMovieTree::display() const {
    displayHelper(this->root);
}