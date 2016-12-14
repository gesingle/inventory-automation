#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include "string.h"

using namespace std;

class Person {

public:
    Person();
    ~Person()
    {
        //intentionally blank
    }
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
