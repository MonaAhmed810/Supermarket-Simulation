#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <iostream>
#include <fstream>
#include <windows.h>
#include <algorithm>
#include "Person.h"
#include "Customer.h"
#include "Stock.h"
#include "Items.h"
#include "Time.h"

using namespace std;

class Administrator : public Person
{
private:
    Stock *stock;
    Customer *ListOfCustomers;
    int TotalRevenue;
    int TotalNumOfCustomers;
public:
    Administrator(Stock& );
    void ReportAvailableItems();
    void AddNewItem();
    void UpdateExistingItem();
    void ReportTotalRevenue();
    void TotalCustomers();
    void MaxReceipt();
    void UpdateListOfCustomers(Customer &);
    void Options();

};

#endif // ADMINISTRATOR_H
