#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
#include "Transaction.h"

#include <iostream>
#include <string>
#include <list>

using namespace std;

class Customer : public Person
{
	friend ostream& operator<<(ostream& outs, const Customer& rhs);
public:
	Customer();
	Customer(string first, string last, int number);
	~Customer();

	void setFName(string name);
	void setLName(string name);
	void setCustomerID(int number);
	std::string getFName() const;
	std::string getLName() const;
	int getCustomerID() const;
	//void displayHistory(ostream& outs) const;
	//bool addHistory(Transaction* borrowed);

private:
	int customerID;
	//string firstName;
	//string lastName;

	list<Transaction*> transHistory;

};


#endif