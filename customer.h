//*****************************************************************************
// Customer.h
// CSS 343 Assignment 4 Implementation
// Garrett Singletary, Cody Snow
// Created: December 01, 2016
// Last Modified: December 14, 2016
//
// Customer is a subclass of the Person class. Customer inherits all members
// of Parent and implements functionality for Customer specific data.
// A Customer contains additional members customerID and transHistory.
// customerID is a unique integer value that may be assigned to the Customer.
// transHistory tracks associated transactions with the specified Customer.
//******************************************************************************

//-------------------------------------------------------------------------------
// Assumptions
// Every customer has a unique customerID
//-------------------------------------------------------------------------------

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "person.h"

#include <iostream>
#include <string>
#include <vector>

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

    // Transaction History Functions
    void displayHistory() const;
    bool addHistory(string transaction);  //add a borrow or return transaction string to customer's history
    bool hasBorrowed(string transaction); //compare the transaction string to transactions in customer's history

private:
    int customerID;
    vector<string> transHistory;
};


#endif