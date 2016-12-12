#include "Customer.h"
//#include <string>

using namespace std;

Customer::Customer() : Person()
{
	firstName = " ";
	lastName = " ";
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
	//intentionally blank
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

int Customer::getCustomerID()
{
	return customerID;
}