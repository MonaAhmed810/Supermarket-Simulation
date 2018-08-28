#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "Time.h"
#include "Person.h"
#include "ShoppingItem.h"
#include "Stock.h"

using namespace std;

class Customer : public Person
{
private:
    int ID;
    double receipt;
    static int maxID;

    Time shoppingDuration;
    Time checkOutTime;
    ShoppingItem *shoppingList;
public:
    Time arrivalTime;
    Customer();
    void calculateArrivalTime();
    void calculateShoppingDuration();
    void calculateCheckOutTime();
    void BuyItems(Stock &);
    Time getCheckOutTime();
    double GetTotal ();

};

#endif // CUSTOMER_H
