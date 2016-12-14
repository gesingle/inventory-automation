//
// Created by Cody Snow on 12/12/2016
//

#include "TransactionFactory.h"

TransactionFactory::TransactionFactory()
{
}

TransactionFactory::~TransactionFactory()
{
}

//wanted this to call the helper functions to assign newTrans
Transaction* TransactionFactory::construct(istream& ins, MovieTree* movieTree, CustomerTable& Customers)
{
	
	Customer cust;
	
	//testing, 
	cout << "In transactionfactory.construct()" << endl;
	char trans = 'R';
	
	Transaction* newTrans = NULL;
	newTrans = new Return;
	newTrans->setMovieTree(movieTree);
	Return* newReturn = NULL;
	newReturn = dynamic_cast<Return*>(newTrans);
	cust.setCustomerID(1111);
	return newTrans;
}

Inventory* TransactionFactory::createInventoryTransaction()
{
	//placeholders
	Inventory* inventoryTrans = NULL;
	return inventoryTrans;
}
History* TransactionFactory::createHistoryTransaction()
{
	//placeholders
	History* historyTrans = NULL;
	return historyTrans;
}
Borrow* TransactionFactory::createBorrowTransaction()
{
	//placeholders
	Borrow* borrowTrans = NULL;
	return borrowTrans;
}
void TransactionFactory::createReturnTransaction(Transaction*& trans, MovieTree* movieTree)
{
	//placeholders
	cout << "In return Trans" << endl;
	return;
}