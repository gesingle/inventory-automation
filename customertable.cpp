//*****************************************************************************
// CustomerTable.cpp
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

#include "customertable.h"


//-------------------------------------------------------------------------------
// constructor
// Builds a CustomerTable with default size TABLESIZE_SMALL, and assigns
// every node to NULL.
//-------------------------------------------------------------------------------
CustomerTable::CustomerTable()
{
    size = TABLESIZE_SMALL; //default size
    table = new Node*[size];

    for (int i = 0; i < size; i++)
        table[i] = NULL;
    customerCount = 0;
}


//-------------------------------------------------------------------------------
// copy constructor
// Builds a new CustomerTable with default size TABLESIZE_SMALL, and assigns
// every node to NULL. Makes use of overloaded = operator to set new
// CustomerTable equal to the provided copy CustomerTable.
//-------------------------------------------------------------------------------
CustomerTable::CustomerTable(const CustomerTable& copy)
{
    table = NULL;
    size = TABLESIZE_SMALL;

    table = new Node*[size];

    for (int i = 0; i < size; i++)
        table[i] = NULL;

    *this = copy; //overloaded =
}


//-------------------------------------------------------------------------------
// destructor
// Uses helper function deleteTable() to delete CustomerTable and set to NULL
//-------------------------------------------------------------------------------
CustomerTable::~CustomerTable()
{
    deleteTable();
}


//-------------------------------------------------------------------------------
// getSize
// returns an int value containing the size of the associated CustomerTable
//-------------------------------------------------------------------------------
int CustomerTable::getSize() const
{
    return size;
}


//-------------------------------------------------------------------------------
// getCustomerCount
// returns a double value containing the number of Customers stored in the
// current CustomerTable.
//-------------------------------------------------------------------------------
double CustomerTable::getCustomerCount() const
{
    return customerCount;
}


//-------------------------------------------------------------------------------
// isEmpty
// returns a boolean value indicating if the CustomerTable is empty.
// CustomerTable is empty if customerCount is zero.
//-------------------------------------------------------------------------------
bool CustomerTable::isEmpty() const
{
    if (customerCount == 0)
        return true;
    else
        return false;
}

//-------------------------------------------------------------------------------
// makeEmpty
// utilizes helper function deleteTable() to delete all Customers and set the
// CustomerTable to NULL. The CustomerTable is then reset to default size and
// all elements are assigned to NULL.
//-------------------------------------------------------------------------------
void CustomerTable::makeEmpty()
{
    deleteTable();
    size = TABLESIZE_SMALL;
    table = new Node*[size];

    for (int i = 0; i < size; i++)
        table[i] = NULL;

    customerCount = 0;
}


//-------------------------------------------------------------------------------
// deleteTable
// steps through the current CustomerTable and assigns each element to NULL.
// deletes CustomerTable and assigns to NULL.
//-------------------------------------------------------------------------------
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


//-------------------------------------------------------------------------------
// addCustomer
// adds a new Customer object to the CustomerTable. This function uses the
// customerID of the new Customer to determine a default hash. The location
// associated with the default hash value is checked for collisions, and a
// double hash is repeatedly called while collisions occur.
// The new Customer object is stored in the first location that does not result
// in a collision.
// If the addition of a new Customer object caused the CustomerTable to become
// too full, CustomerTable size is increased.
//-------------------------------------------------------------------------------
bool CustomerTable::addCustomer(Customer* newCustomer)
{
    int collisions = 0;
    bool isAdded = false;

    Node* newNode = new Node;
    newNode->customerData = newCustomer;

    int hash = performHash(newCustomer);

    if (table[hash] == NULL) //insert customer
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

    if ((customerCount / size) >= 0.75) //likelihood of collisions is inefficient
    {
        increaseTableSize();
    }

    return isAdded;
}


//-------------------------------------------------------------------------------
// performHash
// performs a default hash using the customerID and the current CustomerTable
// size
//-------------------------------------------------------------------------------
int CustomerTable::performHash(Customer* newCustomer) //default single hash
{
    int custID = newCustomer->getCustomerID();
    return (custID % size);
}


//-------------------------------------------------------------------------------
// performDoubleHash
// if the default hash results in a collision, this function performs double
// hashing recursively until a collision does not occur.
// isOccupied() is used to determine if the CustomerTable element associated
// with the double hash is already occupied by a Customer object.
//-------------------------------------------------------------------------------
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


//-------------------------------------------------------------------------------
// isOccupied
// Returns a boolean value to indicate if the current CustomerTable element
// is occupied by a Customer object.
//-------------------------------------------------------------------------------
bool CustomerTable::isOccupied(int& hash)
{
    if (table[hash] != NULL)
        return true;
    else
        return false;
}


//-------------------------------------------------------------------------------
// isFound
// Returns a boolean value indicating if the custID is already present in the
// CustomerTable.
//-------------------------------------------------------------------------------
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


//-------------------------------------------------------------------------------
// increaseTableSize
// Increases the current CustomerTable size to allow for more efficient hashing.
//-------------------------------------------------------------------------------
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

//-------------------------------------------------------------------------------
// retrieveCustomer
// Searches the current CustomerTable for custID. If custID is found, assigns
// cust with the Customer object stored at that location. Function returns
// a boolean to indicate if the custID was found in the CustomerTable.
//-------------------------------------------------------------------------------
bool CustomerTable::retrieveCustomer(int custID, Customer*& cust)
{
    int hash = custID % size;
    bool isFound = false;

    Node* temp = NULL;

    if (table[hash] == NULL || table[hash]->customerData->getCustomerID() != custID) //look at every element to check for customerID
    {
        for (int i = 0; i < size; i++)
        {
            temp = table[i];

            if (temp != NULL)
            {
                if (temp->customerData->getCustomerID() == custID)
                {
                    cust = temp->customerData;
                    isFound = true;
                    break;
                }
            }
        }
    }
    else if (table[hash] == NULL || table[hash]->customerData->getCustomerID() == custID) //base case, default single hash location
    {
        cust = table[hash]->customerData;
        isFound = true;
    }

    delete temp;
    temp = NULL;

    return isFound;
}


//-------------------------------------------------------------------------------
// deleteCustomer
// Searches the current CustomerTable to locate the specified custID. If found,
// assigns cust with the Customer object at the location. The Customer object
// is removed from the CustomerTable and a boolean is returned to indicate if the
// Customer was found and removed.
//-------------------------------------------------------------------------------
bool CustomerTable::deleteCustomer(int custID, Customer*& cust)
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
                cust = temp->customerData;
                isFound = true;
                break;
            }
        }
    }

    else if (table[hash]->customerData->getCustomerID() == custID) //base case, default single hash location
    {
        cust = table[hash]->customerData;
        isFound = true;
    }

    delete temp->customerData;
    temp->customerData = NULL;
    delete temp;
    temp = NULL;

    customerCount--;

    return isFound;
}


//-------------------------------------------------------------------------------
// overloaded operator =
// allows operator = to be used to assign one CustomerTable to another
// CustomerTable.
//-------------------------------------------------------------------------------
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
                table[i] = temp;
            }
        }
    }
    return *this;
}


//-------------------------------------------------------------------------------
// displayCustomers
// Utilizes the overloaded << operator to output data associated with every
// Customer object located within the CustomerTable.
//-------------------------------------------------------------------------------
void CustomerTable::displayCustomers()
{
    cout << *this << endl;
}


//-------------------------------------------------------------------------------
// operator<<
// Overloads << operator to define how << behaves with CustomerTables. First
// name, last name, and customerID will be displayed for every Customer in the
// CustomerTable.
//-------------------------------------------------------------------------------
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