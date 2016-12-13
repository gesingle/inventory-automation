#ifndef HISTORY_H
#define HISTORY_H

#include "DisplayTransaction.h"
#include "Customer.h"
#include "CustomerTable.h"

class History : public DisplayTransaction
{
	//friend std::ostream& operator<<(std::ostream& outs, const History& history);

public:
	History();
	//History(Customer* customer);
	~History();

	//override makeAction to implement history action, displays history of customer
	virtual void makeAction(); //line consists of customerID
	void setCustomer(Customer& cust);
	void displayHistory();

private:
	Customer* customer;
	void printHistory();
};


#endif