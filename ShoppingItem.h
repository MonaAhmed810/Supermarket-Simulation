#ifndef SHOPPINGITEM_H
#define SHOPPINGITEM_H

#include <iostream>

using namespace std;

class ShoppingItem
{
private:
    string Name;
    int amount;
public:
    void setName(string ) ;
    void setAmount(int );
    string getName() const ;
    int getAmount() const ;

};

#endif // SHOPPINGITEM_H
