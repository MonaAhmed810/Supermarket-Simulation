#include <iostream>
#include <fstream>
#include "Stock.h"
#include "Administrator.h"
#include "Customer.h"

using namespace std;

int main()
{
    Stock stock;
    Administrator admin(stock);
    while(true)
    {
        cout<<"Press 1 to Enter as admin, 2 to Enter as customer, and 0 to end the program:";
        int reply;
        cin>>reply;
        if(reply==0)
        {
            stock.updateStock();
            return 0 ;
        }

        else if(reply==1)
        {
            while(true)
            {
                char x;
                admin.Options();
                cout<<"Do you want to do another operation? ENTER (Y) for YES, (N) for NO"<<endl;
                cin>>x;
                while (x!='Y' && x!='y' && x!='N' && x!='n')
                {
                    cout<<"Please enter A vaild input\n";
                    cin>>x;
                }
                if(x=='N' || x=='n') break;
            }
        }
        else if(reply==2)
        {
            cout<<"Plz enter number of customers:";
            int x;
            cin>>x;
            Customer *c;
            c=new Customer[x];
            for(int i=0; i<x; i++)
            {
                cout<<"PLz select from the following menu the items that Cust."<<i+1<<" bought:\n";
                c[i].BuyItems(stock);
                cout<<"Total receipt for Cust."<<i+1<<" is "<<c[i].GetTotal()<<" L.E"<<endl;
                admin.UpdateListOfCustomers(c[i]);
            }
        }
        else cout<<"Enter a valid number"<<endl;

    }
    return 0;
}
