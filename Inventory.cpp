//
// Created by Cody Snow on 12/12/2016
//

#include "Inventory.h"



Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

 void Inventory::makeAction()
{
	displayInventory(clMovieTree, coMovieTree, drMovieTree);
	cout << "In inventory.makeAction()" << endl;
}

void Inventory::displayInventory(ClMovieTree* clTreeRoot, CoMovieTree* coTreeRoot, DrMovieTree* drTreeRoot)
{
	//perform inorder traversal of movies
	cout << "In inventory.displayInventory()" << endl;
	clTreeRoot->display();
	coTreeRoot->display();
	drTreeRoot->display();
}