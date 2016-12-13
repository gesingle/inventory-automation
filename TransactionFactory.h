#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <iostream>
#include "Transaction.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"
#include "BSTree.h"

class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();

	Transaction* construct(std::istream* ins, BSTree* movie);

private:
	Inventory* createInventoryTransaction(std::istream& inStream);
	History* createHistoryTransaction(std::istream& inStream);
	Borrow* createBorrowTransaction(std::istream& inStream, BSTree* movieTrees);
	Return* createReturnTransaction(std::istream& inStream, BSTree* movieTrees);
};

#endif