//
// Created by Cody Snow on 12/12/2016
//

#include "actionTransaction.h"

ActionTransaction::ActionTransaction()
{
	customer = NULL;
	movie = NULL;
	borrowed = false;
}

ActionTransaction::~ActionTransaction()
{
}

void ActionTransaction::setCustomer(Customer& cust)
{
	*customer = cust;
}