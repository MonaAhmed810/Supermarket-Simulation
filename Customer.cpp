#include "Customer.h"

#include <iostream>
#include "Time.h"
#include "Person.h"
#include <windows.h>
#include <cstdlib>
#include <ctime>
#include "ShoppingItem.h"

using namespace std;

int Customer::maxID = 0;

Customer::Customer()
{
    calculateArrivalTime();
    calculateShoppingDuration();
    calculateCheckOutTime();
    ID = ++maxID ;
    receipt=0;
    shoppingList=new ShoppingItem[1000];

}
void Customer::calculateArrivalTime()
{
    SYSTEMTIME t;
    GetLocalTime(&t);
    arrivalTime.setHour(t.wHour);
    arrivalTime.setMinute(t.wMinute);

}
void Customer::calculateShoppingDuration()
{
    srand(time(0));
    shoppingDuration.setHour(rand()%4);
    srand(time(0));
    shoppingDuration.setMinute(rand()%60);
}
void Customer::calculateCheckOutTime()
{
    checkOutTime=arrivalTime+shoppingDuration;
}

void Customer::BuyItems(Stock &s)
{
    Stock *stock;
    stock=&s;
    int j=0;
    while(true)
    {
        stock->printItems();
        cout<<"Plz select the id of the item u want"<<endl;
        int choice,amount;
        cin>>choice;
        while(stock->s[choice-1].getAvailAmount()==0 || choice > maxID || choice<0)
        {
            cout<<"This item isn't avilable\n"<<"Plz select another item"<<endl;
            cin>>choice;
        }
        cout<<"Plz enter the amount u want :";
        cin>>amount;
        while (amount > stock->s[choice-1].getAvailAmount())
        {
            cout<<"Only avilable is "<<stock->s[choice-1].getAvailAmount()<<"\nPlease Enter a vaild amount or 0 to select another Item\n";
            cin>>amount;
        }
        if(amount == 0) continue;
        stock->s[choice-1].decrementAvailableAmount(amount);
        receipt+=(stock->s[choice-1].getPrice()*amount);
        shoppingList[j].setName(stock->s[choice-1].getName());
        shoppingList[j].setAmount(amount);
        j++;
        cout<<"Do you want to select another item ?"<<endl;
        string reply;
        cin>>reply;
        if(reply=="N" || reply== "n") break;
        else if (reply!="Y" && reply!="y")
        {
            cout<<"Please enter A vaild input\n"<<endl;
            continue ;
        }
    }

}
Time Customer::getCheckOutTime()
{
    return checkOutTime;
}
double Customer::GetTotal ()
{
    return receipt;
}


