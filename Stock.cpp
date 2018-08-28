#include "Stock.h"
#include "windows.h"
#include <iostream>
#include "Items.h"

using namespace std;

Stock::Stock()
{
    s = new Items [1000];
    fstream data("Stock.txt",ios::in|ios::out);
    LoadStock(data);
}
void Stock::LoadStock(fstream &data)
{
    int j = 0 ;
    string x ;
    int n ;
    double p;
    while (data>>x)
    {
        s[j].SetName(x);
        s[j].SetID();
        data>>x;
        s[j].SetType(x);
        data>>n;
        s[j].SetAvailAmount(n) ;
        data>>p ;
        s[j].SetPrice(p);
        j++;
    }
    TotalSize = j ;
    s[j].SetName("End");
}
void Stock::updateStock ()
{
    fstream data("Stock.txt",ios::in|ios::out);
    data.seekg(0, ios::beg);
    for (int i = 0 ; i < TotalSize ; i++)
    {

        data<<setw(8)<<left<<s[i].getName()<<" "<<setw(13)<<left<<s[i].getType();
        data<<" "<<setw(6)<<left<<s[i].getPrice()<<"  "<<s[i].getAvailAmount()<<endl;
    }
}
void Stock::printItems ()
{
    HANDLE hconsole ;
    hconsole =GetStdHandle(STD_OUTPUT_HANDLE);
    cout<<"ID"<<"  "<<setw(8)<<left<<"Name "<<" "<<setw(13)<<left<<"Type";
    cout<<" "<<"Price"<<"   "<<"AvailAmount"<<endl;
    for (int i = 0 ; i < TotalSize ; i++)
    {
        if (s[i].getAvailAmount()<=5)
        {
            FlushConsoleInputBuffer(hconsole);
            SetConsoleTextAttribute(hconsole,17);
            cout<<setw(2)<<right<<s[i].getID()<<"  ";
            cout<<setw(8)<<left<<s[i].getName()<<" "<<setw(13)<<left<<s[i].getType();
            cout<<" "<<setw(6)<<left<<s[i].getPrice()<<"  "<<s[i].getAvailAmount()<<endl;
        }
        else
        {
            SetConsoleTextAttribute(hconsole,7);
            cout<<setw(2)<<right<<s[i].getID()<<"  ";
            cout<<setw(8)<<left<<s[i].getName()<<" "<<setw(13)<<left<<s[i].getType();
            cout<<" "<<setw(6)<<left<<s[i].getPrice()<<"  "<<s[i].getAvailAmount()<<endl;
        }
    }
    SetConsoleTextAttribute(hconsole,7);

}
int Stock::getTotalSize()
{
    return TotalSize;
}
void Stock::incrementTotalSize()
{
    TotalSize++;
}

