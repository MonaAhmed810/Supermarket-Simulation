#include "ShoppingItem.h"

#include <iostream>

using namespace std;

void ShoppingItem::setName(string a)
{
    Name = a;
}
void ShoppingItem::setAmount(int x)
{
    amount = x;
}
string ShoppingItem::getName() const
{
    return Name;
}
int ShoppingItem::getAmount() const
{
    return amount;
}
