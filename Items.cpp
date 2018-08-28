#include "Items.h"

#include <iostream>

using namespace std;

int Items::maxID = 0 ;
Items::Items()
{
    //ctor
}
Items::Items(string a, int x, int p, string t)
{
    Name = a ;
    AvailAmount = x ;
    price = p ;
    Type=t;
    ID=++maxID;
}

void Items::SetName(string a)
{
    Name = a ;
}
void Items::SetAvailAmount(int x)
{
    AvailAmount = x ;
}
void Items::SetPrice (int x)
{
    price = x ;
}
void Items::SetID()
{
    ID = ++maxID ;
}
void Items::SetType(string t)
{
    Type = t ;
}
string Items::getName() const
{
    return Name ;
}
string Items::getType()const
{
    return Type ;
}
int Items::getAvailAmount() const
{
    return AvailAmount ;
}
double Items::getPrice () const
{
    return price ;
}
int Items::getID ()const
{
    return ID ;
}
void Items::decrementAvailableAmount(int amount)
{
    AvailAmount-=amount;
}
