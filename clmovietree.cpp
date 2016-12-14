//
// Created by Garrett Singletary on 12/12/16.
//

#include "clmovietree.h"

ClMovieTree::ClMovieTree() {

}

bool ClMovieTree::insert(ClassicMovie *m) {

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
    return false;
}

void ClMovieTree::displayHelper(MovieNode* node) const{

    if(node != NULL){
        displayHelper(node->left);
        cout << node->movie->getStock() << " " << node->movie->getYear() << " " << node->movie->getActor() << endl;
        displayHelper(node->right);
    }
}

void ClMovieTree::display() const {
    displayHelper(this->root);
}

bool ClMovieTree::retrieve(const ClassicMovie& movie, ClassicMovie*& moviePtr) const {

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