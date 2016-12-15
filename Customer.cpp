//*****************************************************************************
// Customer.h
// CSS 343 Assignment 4 Implementation
// Garrett Singletary, Cody Snow
// Created: December 01, 2016
// Last Modified: December 14, 2016
//
// Implements Customer class functions
//******************************************************************************

#include "Customer.h"
using namespace std;


//-------------------------------------------------------------------------------
// default constructor
// Instantiates a Customer object with empty strings for first and last name.
// customerID is assigned -1, indicating that the value needs to be updated.
// This is used to check for validity before inserting a Customer into a table.
//-------------------------------------------------------------------------------
Customer::Customer() : Person()
{
	firstName = "";
	lastName = "";
	customerID = -1;
	
}

//-------------------------------------------------------------------------------
// overloaded constructor
// Instantiates a Customer object, assigning the provided string names to 
// firstName and lastName. The provided number is assigned as the customerID.
//-------------------------------------------------------------------------------
Customer::Customer(string first, string last, int number) : Person(first, last)
{
	firstName = first;
	lastName = last;
	customerID = number;
}


//-------------------------------------------------------------------------------
// destructor
//-------------------------------------------------------------------------------
Customer::~Customer()
{
}


//-------------------------------------------------------------------------------
// setFName
// assigns Customer firstName with the provided string name
//-------------------------------------------------------------------------------
void Customer::setFName(std::string name)
{
	firstName = name;
}


//-------------------------------------------------------------------------------
// setFName
// assigns Customer lastName with the provided string name
//-------------------------------------------------------------------------------
void Customer::setLName(std::string name)
{
	lastName = name;
}


//-------------------------------------------------------------------------------
// setCustomerID
// Assigns customerID with the provided number.
//-------------------------------------------------------------------------------
void Customer::setCustomerID(int number)
{
	customerID = number;
}


//-------------------------------------------------------------------------------
// getFName
// returns a string containing the firstName of associated Customer
//-------------------------------------------------------------------------------
std::string Customer::getFName() const
{
	return firstName;
}


//-------------------------------------------------------------------------------
// getLName
// returns a string containing the lastName of assoicated Customer
//-------------------------------------------------------------------------------
std::string Customer::getLName() const
{
	return lastName;
}


//-------------------------------------------------------------------------------
// getCustomerID
// returns an int value containing the customerID of the associated Customer.
//-------------------------------------------------------------------------------
int Customer::getCustomerID() const
{
	return customerID;
}


//-------------------------------------------------------------------------------
// displayHistory
// outputs a list of transactions associated with the Customer. This function
// makes use of the overloaded << operator, which steps through the Customer's
// transHistory to output transactions. Transactions should consist of Returns
// and Borrows.
//-------------------------------------------------------------------------------
void Customer::displayHistory() const 
{
	cout << *this << endl;
}


//-------------------------------------------------------------------------------
// addHistory
// Adds a new string associated with a tranaction to a Customer's transHistory.
// This function returns true to indicate that the transaction is added to the 
// transHistory. 
//-------------------------------------------------------------------------------
bool Customer::addHistory(string transaction)
{
	transHistory.push_back(transaction);
	return true;
}


//-------------------------------------------------------------------------------
// hasBorrowed
// Steps through a Customer's transHistory to locate a transaction string that
// matches the provided input string.
//-------------------------------------------------------------------------------
bool Customer::hasBorrowed(string transaction)
{
	for (unsigned int i = 0; i < this->transHistory.size(); i++)
	{
		if (this->transHistory[i] == transaction)
			return true;
	}
		return false;
}

//-------------------------------------------------------------------------------
// overloaded operator<<
// Allows operator << to be used for Customer objects. Using << to output a 
// Customer class will output the Customer's name and ID, followed by a list
// of associated transactions.
// Transactions consist of strings associated with Borrows and Returns.
//-------------------------------------------------------------------------------
ostream& operator<<(ostream& outs, const Customer& rhs)
{
	outs << "Customer: " << rhs.getFName() << " " << rhs.getLName() << "  ID: " 
		 << rhs.getCustomerID() << endl;
	
	for (unsigned int i = 0; i < rhs.transHistory.size(); i++)
		outs << rhs.transHistory[i] << endl;
		
	return outs;

}