#ifndef TRANSACTIONFACTORY_H
#define TRANSACTIONFACTORY_H

//
// Created by Cody Snow on 12/12/2016
//

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
#include "MovieTree.h"	

class TransactionFactory
{
public:
	TransactionFactory();
	~TransactionFactory();

	static Transaction* construct(std::istream& ins, MovieTree* movieTree, CustomerTable& customers); //will be implemented differently, file will already be parsed

private:
	Inventory* createInventoryTransaction();
	History* createHistoryTransaction();
	Borrow* createBorrowTransaction();
	void createReturnTransaction(Transaction*& trans, MovieTree* movieTree);
};

#endif