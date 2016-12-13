#ifndef INVENTORY_H
#define INVENTORY_H

#include "Movie.h"
#include "DisplayTransaction.h"
#include <iostream>

using namespace std;

class Inventory: public DisplayTransaction
{
public:
	Inventory();
	~Inventory();
	void makeAction();
	void displayInventory(BSTree* movie); //overload for different movie trees.
};

#endif