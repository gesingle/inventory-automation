//
// Created by Cody Snow on 12/12/2016
//

#include "History.h"
#include "Customer.h"

History::History()
{
}

History::History(Customer* cust)
{
	customer = cust;
}

History::~History() 
{
}

//override makeAction to implement history action, displays history of customer
void History::makeAction() //line consists of customerID
{
	printHistory();
}

void History::printHistory()
{
	cout << *customer << endl;
}


void History::setCustomer(Customer* cust)
{
	customer = cust;
}


