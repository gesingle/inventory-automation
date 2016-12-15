//
// Created by Cody Snow on 12/01/2016
// Last Modified 12/12/2016 -> added operator>> and display functions
//

#include "customer.h"

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

void Customer::displayHistory() const // change to outstream
{
    cout << *this << endl;
}

bool Customer::addHistory(string transaction)
{
    transHistory.push_back(transaction);
    return true;
}

bool Customer::hasBorrowed(string title)
{
    for (unsigned int i = 0; i < this->transHistory.size(); i++)
    {
        if (this->transHistory.at(i) == title)
            return true;
    }
    return false;
}


ostream& operator<<(ostream& outs, const Customer& rhs)
{
    outs << "Customer: " << rhs.getFName() << " " << rhs.getLName() << "  ID: " << rhs.getCustomerID() << endl;
    for (unsigned int i = 0; i < rhs.transHistory.size(); i++)
        outs << "   " << rhs.transHistory[i] << endl;

    return outs;

}