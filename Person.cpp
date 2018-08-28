#include "Person.h"

#include <iostream>

using namespace std;

Person::Person()
{
    //ctor
}

Person::~Person()
{
    //dtor
}


string Person::getName() const
{
    return name;
}
string Person::getAdress() const
{
    return adress;
}
void Person::setName(string a)
{
    name = a;
}
void Person::setAdress(string a)
{
    adress=a;
}
