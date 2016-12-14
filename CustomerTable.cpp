//		
// Created by Cody Snow on 12/12/16.
// Last Modified 12/13/16 (added operator<< and display function, implemented double hash
//

#include "CustomerTable.h"

CustomerTable::CustomerTable()
{
	size = TABLESIZE_SMALL; //default size
	table = new Node*[size];

	for (int i = 0; i < size; i++)
		table[i] = NULL;
}

CustomerTable::CustomerTable(const CustomerTable& copy) //copy constructor, make a deep copy of 'copy' table
{
	table = NULL;
	size = TABLESIZE_SMALL;
	
	table = new Node*[size];

	for (int i = 0; i < size; i++)
		table[i] = NULL;

	*this = copy;
}

CustomerTable::~CustomerTable()
{
	deleteTable();
}

int CustomerTable::getSize() const
{
	return size;
}

double CustomerTable::getCustomerCount() const
{
	return customerCount;
}

bool CustomerTable::isEmpty() const
{
	if (customerCount == 0)
		return true;
	else
		return false;
}


void CustomerTable::makeEmpty()
{
	deleteTable();
	size = TABLESIZE_SMALL;
	table = new Node*[size];

	for (int i = 0; i < size; i++)
		table[i] = NULL;

	customerCount = 0;
}

void CustomerTable::deleteTable()
{
	for (int i = 0; i < size; i++)
	{
		Node* temp = table[i];

		while (temp != NULL) //delete a node from array element
		{
			delete temp->customerData;
			temp->customerData = NULL;
			delete temp;
			temp = NULL;
		}

		table[i] = NULL;
	}

	delete[] table;
	table = NULL;
}

bool CustomerTable::addCustomer(Customer* newCustomer)
{
	int collisions = 0;
	bool isAdded = false;

	Node* newNode = new Node;
	newNode->customerData = newCustomer;

	int hash = performHash(newCustomer); //change to double hash, call recursively

	if (table[hash] == NULL)
	{
		newNode->hashIndex = hash;
		table[hash] = newNode;
		customerCount++;
		isAdded = true;
	}
	else //table[hash] is occupied
	{
			collisions++;
			hash = performDoubleHash(newCustomer, collisions); //recursively double hashes until an empty hash is found

			newNode->hashIndex = hash; //assigns hashIndex with array element
			table[hash] = newNode;
			customerCount++;
			isAdded = true;
	}

	if ((customerCount / size) >= 1.0) //if # of stored customers is greater than or equal to the size, increase the size
	{
		increaseTableSize();
	}

	return isAdded;
}



int CustomerTable::performHash(Customer* newCustomer) //default single hash
{
	int custID = newCustomer->getCustomerID();
	return (custID % size);
}

int CustomerTable::performDoubleHash(Customer* newCustomer, int& collisions)
{
	bool occupied = true;
	int custID = newCustomer->getCustomerID();
	int firstHash = custID % size;
	int newMod = size - 2;
	int doubleHash = (newMod - (custID % newMod));
	doubleHash = ((firstHash + (collisions * (doubleHash))) % size);

	occupied = isOccupied(doubleHash);

	if (occupied == true)
	{
		collisions++;
		return performDoubleHash(newCustomer, collisions);
	}
	else
		return doubleHash;
}

bool CustomerTable::isOccupied(int& hash)
{
	if (table[hash] != NULL)
		return true;
	else
		return false;
}


//checks to see if target customer is already in the table
bool CustomerTable::isFound(int custID) const
{
	int hash = custID % size;
	bool returnVal = false;
	Node* temp = NULL;

	if (table[hash]->customerData->getCustomerID() != custID) //look at every element to check check for customerID
	{
		for (int i = 0; i < size; i++)
		{
			temp = table[i];

			if (temp->customerData->getCustomerID() == custID)
			{
				returnVal = true;
			}
		}
	}

	else if (table[hash]->customerData->getCustomerID() == custID) //base case, default single hash location
	{
		returnVal = true;
	}

	delete temp->customerData;
	temp->customerData = NULL;
	delete temp;
	temp = NULL;

	return returnVal;
}

void CustomerTable::increaseTableSize()
{
	int tableSize = (size * 2) - 1; //maintains odds, less collisions

	Node** newTable = new Node*[tableSize]; 

	for (int i = 0; i < tableSize; i++)
		newTable[i] = NULL;

	for (int i = 0; i < tableSize; i++)
	{
		Node* temp = table[i];
		while (temp != NULL)
		{
			Node* newNode = new Node;
			newNode->customerData = temp->customerData;
			newNode->hashIndex = temp->hashIndex;

			//int hash = newNode->hashIndex % tableSize;
			newTable[temp->hashIndex] = newNode;

			delete temp;
			temp = NULL;
		}

		table[i] = NULL;
	}

	delete[] table;
	table = newTable;
	size = tableSize;

	//delete newTable?
}


bool CustomerTable::retrieveCustomer(int custID, Customer& cust)
{
	int hash = custID % size;
	bool isFound = false;

	Node* temp = NULL;
	
	if (table[hash] == NULL || table[hash]->customerData->getCustomerID() != custID) //look at every element to check check for customerID
	{
		for (int i = 0; i < size; i++)
		{
			temp = table[i];

			if (temp != NULL)
			{
				if (temp->customerData->getCustomerID() == custID)
				{
					cust = *temp->customerData;
					isFound = true;
					break;
				}
			}
		}
	}


	else if (table[hash] == NULL || table[hash]->customerData->getCustomerID() == custID) //base case, default single hash location
	{
		cust = *table[hash]->customerData;
		isFound = true;
	}

	delete temp;
	temp = NULL;

	return isFound;
}


bool CustomerTable::deleteCustomer(int custID, Customer& cust) //needs update 
{
	int hash = custID % size;
	bool isFound = false;

	Node* temp = NULL;

	if (table[hash]->customerData->getCustomerID() != custID) //look at every element to check check for customerID
	{
		for (int i = 0; i < size; i++)
		{
			temp = table[i];

			if (temp->customerData->getCustomerID() == custID)
			{
				cust = *temp->customerData;
				isFound = true;
				break;
			}
		}
	}

	else if (table[hash]->customerData->getCustomerID() == custID) //base case, default single hash location
	{
		cust = *table[hash]->customerData;
		isFound = true;
	}

	delete temp->customerData;
	temp->customerData = NULL;
	delete temp;
	temp = NULL;

	customerCount--;

	return isFound;
}


/*
CustomerTable& CustomerTable::operator=(const CustomerTable& copyTable)
{
	if (this != &copyTable)
	{
		deleteTable();
		size = copyTable.size;
		customerCount = copyTable.customerCount;
		table = new Node*[size];

		for (int i = 0; i < size; i++)
			table[i] = NULL;

		for (int i = 0; i < size; i++)
		{
			if (copyTable.table[i] != NULL)
			{
				Node* temp = copyTable.table[i];
				Node* head = new Node;
				Customer* cust = new Customer;
				head->hashIndex = temp->hashIndex;
				//head->next = NULL;
				*cust = *temp->customerData;
				head->customerData = cust;
				table[i] = head;
				//temp = temp->next;

				while (temp != NULL)
				{
					Node* newNode = new Node;
					cust = new Customer;
				//	newNode->next = NULL;
					*cust = *temp->customerData;
					newNode->customerData = cust;
					newNode-> hashIndex = temp->hashIndex;
				//	temp = temp->next;
				//	head = head->next;
				}
			}
		}
	}
	return *this;
}*/

void CustomerTable::displayCustomers()
{
	cout << *this << endl;
}

ostream& operator<<(ostream& outs, const CustomerTable& rhs)
{
	for (int i = 0; i < rhs.size; i++)
	{
		if (rhs.table[i] != NULL)
		{
			outs << i << " " << rhs.table[i]->customerData->getFName() << " "
				<< rhs.table[i]->customerData->getLName() << " "
				<< rhs.table[i]->customerData->getCustomerID() << endl;
		}
	}
	return outs;
}