#ifndef ITEMS_H
#define ITEMS_H

#include <iostream>

using namespace std;


class Items
{
private:
    string Name ;
    string Type ;
    int ID,AvailAmount;
    double price;
    static int maxID ;
public:
    Items();
    Items(string, int, int, string);
    void SetName(string );
    void SetAvailAmount(int );
    void SetPrice (int );
    void SetID();
    void SetType(string );
    string getName() const ;
    string getType()const;
    int getAvailAmount() const ;
    double getPrice () const;
    int getID ()const;
    void decrementAvailableAmount(int );
};

#endif // ITEMS_H
