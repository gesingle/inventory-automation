//*****************************************************************************
// Person.h
// CSS 343 Assignment 4 Implementation
// Garrett Singletary, Cody Snow
// Created: December 01, 2016
// Last Modified: December 14, 2016
//
// Person is the primary class for handling person objects. A person is not
// intended to be instantiated, but provides a framework for Person subclasses
// to be implemented as required.
// The person class contains data members for first and last name, and contains
// functionality to access or assign those values.
//******************************************************************************


#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "string.h"

using namespace std;

class Person {

public:
	Person();
	~Person();
	Person(string first, string last);
	virtual string getFName();
	virtual void setFName(string name);
	virtual string getLName();
	virtual void setLName(string name);

protected:
	string firstName;
	string lastName;

};

#endif