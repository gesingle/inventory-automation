#include "Person.h"
#include <string>

using namespace std;


Person::Person() {
    firstName = " ";
    lastName = " ";
}

Person::~Person() {
}

Person::Person(string first, string last) {
    firstName = first;
    lastName = last;
}

string Person::getFName() {
    return firstName;
}

void Person::setFName(string name) {
    firstName = name;
}

string Person::getLName() {
    return lastName;
}

void Person::setLName(string name) {
    lastName = name;
}