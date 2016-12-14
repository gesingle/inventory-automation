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
	displayInventory(movieTree);
	cout << "In inventory.makeAction()" << endl;
}

void Inventory::displayInventory(MovieTree* movies)
{
	//perform inorder traversal of movies
	cout << "In inventory.displayInventory()" << endl;
}