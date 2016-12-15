/* ------------------------------------------------ drmovietree.cpp ----------------------------------------------------
 Created by Garrett Singletary and Cody Snow on 12/01/2016
 CSS343 Assignment #4
 Date of Last Modification: 12/14/2016
 -----------------------------------------------------------------------------------------------------------------------
 This class implements a binary search tree to hold drama movies.
 -----------------------------------------------------------------------------------------------------------------------
*/

#include "drmovietree.h"

// ------------------------------------------------ DrMovieTree --------------------------------------------------------
//  Constructor
// ---------------------------------------------------------------------------------------------------------------------
DrMovieTree::DrMovieTree() {

}

// ------------------------------------------------ insert -------------------------------------------------------------
//  Inserts a movie into the tree
// ---------------------------------------------------------------------------------------------------------------------
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
    return false;
}

// ------------------------------------------------ displayHelper ------------------------------------------------------
//  Helper function for displaying the movie tree using inorder traversal
// ---------------------------------------------------------------------------------------------------------------------
void DrMovieTree::displayHelper(MovieNode* node) const{

    if(node != NULL){
        displayHelper(node->left);
        cout << "      " << node->movie->getStock() << " " << node->movie->getDirector() << " " << node->movie->getTitle() << endl;
        displayHelper(node->right);
    }
}

// ------------------------------------------------ display ------------------------------------------------------------
//  Displays all the movies in the tree
// ---------------------------------------------------------------------------------------------------------------------
void DrMovieTree::display() const {
    displayHelper(this->root);
}

// ------------------------------------------------ retrieve -----------------------------------------------------------
//  Returns a pointer to the movie being searched for if it exist
// ---------------------------------------------------------------------------------------------------------------------
bool DrMovieTree::retrieve(const DramaMovie& movie, DramaMovie*& moviePtr) const {

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