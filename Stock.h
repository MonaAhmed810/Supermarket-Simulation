#ifndef STOCK_H
#define STOCK_H

#include <iostream>
#include "Items.h"
#include <fstream>
#include <iomanip>

using namespace std;

class Stock
{
private:
    int TotalSize;
public:
    Items *s;
    Stock();
    void LoadStock(fstream &);
    void updateStock ();
    void printItems ();
    int getTotalSize();
    void incrementTotalSize();


};

#endif
