#include "Administrator.h"
#include <windows.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Person.h"
#include "Customer.h"
#include "Stock.h"
#include "Items.h"
#include "Time.h"

using namespace std;


Administrator::Administrator(Stock &s)
{
    stock = &s ;
    ListOfCustomers=new Customer[1000];
    TotalRevenue=0;
    TotalNumOfCustomers=0;
}
void Administrator::ReportAvailableItems()
{
    stock->printItems();
}
void Administrator::AddNewItem()
{
    cout<<"Plz enter the item name, type, available units, price:"<<endl;
    string x;
    int n,j=stock->getTotalSize();
    double p;
    cin>>x;
    stock->s[j].SetName(x);
    stock->s[j].SetID();
    cin>>x;
    stock->s[j].SetType(x);
    cin>>n;
    stock->s[j].SetAvailAmount(n) ;
    cin>>p;
    stock->s[j].SetPrice(p);
    j++;
    stock->s[j].SetName("End");
    stock->incrementTotalSize();
}
void Administrator::UpdateExistingItem()
{
    cout<<"Here is the List of items"<<endl;
    stock->printItems();
    cout<<"Please Enter Item Name : "<<endl;
    string x;
    cin>>x;
    int idx=-1,n=stock->getTotalSize();
    double p;
    for(int i=0; i<n; i++)
    {
        if(stock->s[i].getName()==x)
        {
            idx=i;
            break;
        }
    }
    if (idx==-1)
    {
        cout<<"you haven't entered A valid name"<<endl;
        return;
    }
    cout<<"Enter the new available amount and the new price"<<endl;
    cin>>n;
    stock->s[idx].SetAvailAmount(n);
    cin>>p;
    stock->s[idx].SetPrice(p);

}
void Administrator::ReportTotalRevenue()
{
    Time CurrentTime;
    SYSTEMTIME t;
    GetLocalTime(&t);
    CurrentTime.setHour(t.wHour);
    CurrentTime.setMinute(t.wMinute);
    double sum=0;
    Customer done[1000];
    int j=0;
    for(int i=0; i<TotalNumOfCustomers; i++)
    {
        if(ListOfCustomers[i].getCheckOutTime()<=CurrentTime)
        {
            sum+=ListOfCustomers[i].GetTotal();
            done[j]=ListOfCustomers[i];
            j++;

        }
    }
    cout<<"Total Revenue is  "<<sum<<endl;
    for(int i=0; i<j; i++)
    {
        for(int k=0; k<j-1; k++)
        {
            if(done[k].getCheckOutTime()>done[k+1].getCheckOutTime())
            {
                Customer temp=done[k];
                done[k]=done[k+1];
                done[k+1]=temp;
            }
            else if(done[k].getCheckOutTime()==done[k+1].getCheckOutTime())
            {
                if(done[k].arrivalTime>done[k].arrivalTime)
                {
                    Customer temp=done[k];
                    done[k]=done[k+1];
                    done[k+1]=temp;

                }
            }
        }
    }
    for(int i=0; i<j; i++)
    {
        cout<<done[i].getCheckOutTime().getHour()<<":"<<done[i].getCheckOutTime().getMinute()<<endl;

    }
}
void Administrator::TotalCustomers()
{
    Time CurrentTime;
    SYSTEMTIME t;
    GetLocalTime(&t);
    CurrentTime.setHour(t.wHour);
    CurrentTime.setMinute(t.wMinute);
    int sum=0;
    for(int i=0; i<TotalNumOfCustomers; i++)
    {
        if(ListOfCustomers[i].getCheckOutTime()> CurrentTime) sum++;
    }
    cout<<"The number of Customers now are "<<sum<<endl;
}
void Administrator::MaxReceipt()
{
    Time CurrentTime;
    SYSTEMTIME t;
    GetLocalTime(&t);
    CurrentTime.setHour(t.wHour);
    CurrentTime.setMinute(t.wMinute);
    double mx=0;
    int idx = 0;
    for(int i=0; i<TotalNumOfCustomers; i++)
    {
        if(ListOfCustomers[i].getCheckOutTime()<=CurrentTime)
        {
            if (mx<ListOfCustomers[i].GetTotal())
            {
                idx=i+1;
                mx=max(mx,ListOfCustomers[i].GetTotal());
            }
        }

    }
    if(mx==0) cout<<"Customers didn't Check out"<<endl;
    else cout<<"The max Receipt is "<<mx<<" For the Customer #"<<idx<<endl;

}
void Administrator::UpdateListOfCustomers(Customer &c)
{
    ListOfCustomers[TotalNumOfCustomers] = c;
    TotalNumOfCustomers++;
}

void Administrator::Options()
{
    int reply;
    cout<<"What you want to do:\n"<<"1- ReportAvailableItems\n"<<"2- AddNewItem\n"<<"3- UpdateExistingItem\n"<<"4- ReportTotalRevenue\n"<<"5- DisplayTotalCustomers\n"<<"6- DisplayMaxReceipt\n";
    cin>>reply;
    if(reply==1) ReportAvailableItems();
    else if(reply==2) AddNewItem();
    else if(reply==3) UpdateExistingItem();
    else if(reply==4) ReportTotalRevenue();
    else if(reply==5) TotalCustomers();
    else if(reply==6) MaxReceipt();
    else
    {
        cout<<"Please enter A vaild input\n";
        Options();
    }

}

