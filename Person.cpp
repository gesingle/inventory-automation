//*****************************************************************************
// Person.cpp
// CSS 343 Assignment 4 Implementation
// Garrett Singletary, Cody Snow
// Created: December 01, 2016
// Last Modified: December 14, 2016
//
// Implements Person class functions
//******************************************************************************

#include "Person.h"
using namespace std;

//-------------------------------------------------------------------------------
// default constructor
// Instantiates a Person object with empty strings for first and last name.
//-------------------------------------------------------------------------------
Person::Person()
{
	firstName = "";
	lastName = "";
}


//-------------------------------------------------------------------------------
// default destructor
//-------------------------------------------------------------------------------
Person::~Person()
{
}


//-------------------------------------------------------------------------------
// constructor
// Instantiates a Person object data members with provided string names.
//-------------------------------------------------------------------------------
Person::Person(string first, string last)
{
	firstName = first;
	lastName = last;
}


//-------------------------------------------------------------------------------
// getFName
// returns a string containing the first name of the associated Person.
//-------------------------------------------------------------------------------
string Person::getFName()
{
	return firstName;
}


//-------------------------------------------------------------------------------
// setFName
// Assigns Person firstname with the provided string name.
//-------------------------------------------------------------------------------
void Person::setFName(string name)
{
	firstName = name;
}


//-------------------------------------------------------------------------------
// getLName
// returns a string containing the last name of the associated Person.
//-------------------------------------------------------------------------------
string Person::getLName()
{
	return lastName;
}


//-------------------------------------------------------------------------------
// setLName
// Assigns Person lastname with the provided string name.
//-------------------------------------------------------------------------------
void Person::setLName(string name)
{
	lastName = name;
}