//
// Created by Cody Snow on 12/01/2016
//

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Person.h"
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
    bool hasBorrowed(string title);

private:
    int customerID;
    vector<string> transHistory;
};


#endif
