#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

#include <iostream>
#include "Transaction.h"
#include "actionTransaction.h"
#include "displayTransaction.h"
#include "Inventory.h"
#include "History.h"
#include "Borrow.h"
#include "Return.h"
#include "BSTree.h"
#include "CustomerTable.h"
#include "Customer.h"

class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();

	static Transaction* construct(std::istream& ins, BSTree* movieTree, CustomerTable& customers); //will be implemented differently, file will already be parsed

private:
	Inventory* createInventoryTransaction(std::istream& inStream);
	History* createHistoryTransaction(std::istream& inStream);
	Borrow* createBorrowTransaction(std::istream& inStream, BSTree* movieTree);
	Return* createReturnTransaction(std::istream& inStream, BSTree* movieTree);
};

#endif