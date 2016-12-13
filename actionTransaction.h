#ifndef ACTIONTRANSACTION_H
#define ACTIONTRANSACTION_H

#include "Transaction.h"
#include "Movie.h"
#include "ClassicMovie.h"
#include "ComedyMovie.h"
#include "DramaMovie.h"
#include "Customer.h"

#include <iostream>
using namespace std;

class ActionTransaction : public Transaction
{
public:
	ActionTransaction();
	~ActionTransaction();
	virtual void makeAction() = 0;

	void setCustomer(Customer& cust);

protected:
	Movie* movie;
	Customer* customer;
	bool borrowed;

};

#endif