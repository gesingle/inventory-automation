#include "TransactionFactory.h"

TransactionFactory::TransactionFactory()
{
}

TransactionFactory::~TransactionFactory()
{
}

Transaction* TransactionFactory::construct(istream& ins, MovieTree* movieTree, CustomerTable& Customers)
{
	Customer cust;
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
	Inventory* inventoryTrans = NULL;
	return inventoryTrans;
}
History* TransactionFactory::createHistoryTransaction()
{
	History* historyTrans = NULL;
	return historyTrans;
}
Borrow* TransactionFactory::createBorrowTransaction()
{
	Borrow* borrowTrans = NULL;
	return borrowTrans;
}
void TransactionFactory::createReturnTransaction(Transaction*& trans, MovieTree* movieTree)
{
	cout << "In return Trans" << endl;
	return;
}