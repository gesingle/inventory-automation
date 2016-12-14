//
// Created by Cody Snow on 12/12/2016
// Last Modified 12/13/2016 -> adjusted table Nodes for double hashing
//

#ifndef CUSTOMERTABLE_H
#define	CUSTOMERTABLE_H
#include "Customer.h"


//const int TABLESIZE = 20011; there is no point using a hash table so large that it would give every customer ID a unique spot 0-9999

const int TABLESIZE_SMALL = 51;													//semi-large prime table size. table grows if necessary

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
	bool deleteCustomer(int location, Customer& customer);

	void displayCustomers();

	// unnecessary functions
	//bool retrieveCustomer(int location, Customer*& customer); //retrieve the customer at specified location
	//CustomerTable& operator=(const CustomerTable& copyTable);

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