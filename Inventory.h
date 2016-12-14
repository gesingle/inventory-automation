//
// Created by Cody Snow on 12/12/2016
//

#ifndef INVENTORY_H
#define INVENTORY_H

#include "Movie.h"
#include "MovieTree.h"
#include "DisplayTransaction.h"
#include <iostream>

using namespace std;

class Inventory: public DisplayTransaction
{
public:
	Inventory();
	~Inventory();
	void makeAction();
	void displayInventory(MovieTree* movies); //tree should already be in order
};

#endif