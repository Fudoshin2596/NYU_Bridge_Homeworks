#include <iostream>
using namespace std;

int main()
{
    const double QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, PENNY = 0.01;
    int quarters, dimes, nickels, pennies, dollars, cents;
    double sum;

    cout<<"Please enter number of coins:"<<endl;
    cout<<"# of quarters: ";
    cin>>quarters;
    cout<<"# of dimes: ";
    cin>>dimes;
    cout<<"# of nickels: ";
    cin>>nickels;
    cout<<"# of pennies: ";
    cin>>pennies;
    cout<<"\n";
    sum = (quarters*QUARTER) + (dimes*DIME) + (nickels*NICKEL) + (pennies*PENNY);
    dollars = (sum);
    cents = ((sum - dollars)*100.0);

    cout<<"The total is "<<dollars<< " dollars and "<<cents<<" cents"<<endl;

    return 0;
}
