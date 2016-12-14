//
// Created by Cody Snow on 12/01/2016
// Last Modified 12/12/2016 -> added operator>> and display functions
//

#include "Customer.h"

using namespace std;

Customer::Customer() : Person()
{
	firstName = "";
	lastName = "";
	customerID = -1;
}

Customer::Customer(string first, string last, int number) : Person(first, last)
{
	firstName = first;
	lastName = last;
	customerID = number;
}
Customer::~Customer()
{
}
void Customer::setFName(std::string name)
{
	firstName = name;
}

void Customer::setLName(std::string name)
{
	lastName = name;
}

void Customer::setCustomerID(int number)
{
	customerID = number;
}

std::string Customer::getFName() const
{
	return firstName;
}

std::string Customer::getLName() const
{
	return lastName;
}

int Customer::getCustomerID() const
{
	return customerID;
}

void Customer::displayHistory(ostream& outs) const
{
	outs << this << endl;
}

bool Customer::addHistory(string transaction)
{
	transHistory.push_back(transaction);
	return true;
}


ostream& operator<<(ostream& outs, const Customer& rhs)
{
	outs << "Customer: " << rhs.getFName() << " " << rhs.getLName() << "  ID: " << rhs.getCustomerID() << endl;
	
	for (int i = 0; i < rhs.transHistory.size(); i++)
		outs << rhs.transHistory[i] << endl;
		
	return outs;

}