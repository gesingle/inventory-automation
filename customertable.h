//
// Created by Garrett Singletary on 12/13/16.
//

#ifndef CUSTOMERTABLE_H
#define	CUSTOMERTABLE_H

#include <iostream>
#include "customer.h"
using namespace std;

//const int TABLESIZE = 20011; there is no point using a hash table so large that it would give every customer ID a unique spot 0-9999
const int TABLESIZE_SMALL = 51; //semi-large prime table size. table grows if necessary

class CustomerTable
{
	friend ostream& operator<<(ostream& outs, const CustomerTable& rhs);

public:
	CustomerTable();
	CustomerTable(const CustomerTable& copyTable); //copy constructor
	~CustomerTable();

	int getSize() const; //returns current size of table (table size may grow)
	double getCustomerCount() const; //returns number of customers stored in table

	bool isEmpty() const; //return true if table is empty
	void makeEmpty(); //delete all Customers from table

	bool addCustomer(Customer* customer); //add a customer to the table
	//bool retrieveCustomer(int location, Customer*& customer); //retrieve the customer at specified location
	bool deleteCustomer(int location, Customer& customer);

	void displayCustomers();
	//CustomerTable& operator=(const CustomerTable& copyTable);

protected:
	struct Node
	{
		Customer* customerData;
		int hashIndex; //array element corresponding to hash value
		//Node* next; //nodes are in an array, no need to use pointers
	};

	Node** table;

	int size;
	double customerCount;


	bool isFound(int custID) const; //checks to see if the key already contains the customer
	void deleteTable();
	int performHash(Customer* customer);
	int performDoubleHash(Customer* customer, int collisions);
	void increaseTableSize();
};

#endif
