//*****************************************************************************
// CustomerTable.h
// CSS 343 Assignment 4 Implementation
// Garrett Singletary, Cody Snow
// Created: December 12, 2016
// Last Modified: December 14, 2016
//
// CustomerTable implements a hash table to store Customer objects. The table
// relies on the customerID of each Customer object to perform a hash and 
// allocate a Customer to the correct location.
// This table implements double hashing to handle collisions.
//******************************************************************************

//-------------------------------------------------------------------------------
// Assumptions
// Every customer has a unique customerID
// Double hashing will eventually result in a valid storage location
//-------------------------------------------------------------------------------

#ifndef CUSTOMERTABLE_H
#define	CUSTOMERTABLE_H
#include "Customer.h"

const int TABLESIZE_SMALL = 51;													//semi-large prime table size. size grows if necessary

class CustomerTable
{
	friend ostream& operator<<(ostream& outs, const CustomerTable& rhs);

public:
	CustomerTable();
	CustomerTable(const CustomerTable& copyTable);								//copy constructor
	~CustomerTable();

	int getSize() const;														//returns current size of table
	double getCustomerCount() const;											//returns number of customers stored in table

	bool isEmpty() const;														//return true if table is empty
	void makeEmpty();															//delete all Customers from table

	bool addCustomer(Customer* customer);										//add a customer to the table
	bool deleteCustomer(int custID, Customer*& customer);
	bool retrieveCustomer(int custID, Customer*& customer);						//retrieve the customer with specified customerID
	void displayCustomers();

	CustomerTable& operator=(const CustomerTable& copyTable);					//overloaded = operator to assign one table to another table

protected:
	struct Node
	{
		Customer* customerData;
		int hashIndex;															//array element corresponding to hash value
	};

	Node** table;
	
	int size;
	double customerCount;


	bool isFound(int custID) const;												// Is customer already in table
	bool isOccupied(int& hash);
	void deleteTable();															// makeEmpty() helper
	int performHash(Customer* customer);										// default hash function
	int performDoubleHash(Customer* customer, int& collisions);					// double hash function for collisions
	void increaseTableSize();													// increases table size when customerCount >= size
};

#endif