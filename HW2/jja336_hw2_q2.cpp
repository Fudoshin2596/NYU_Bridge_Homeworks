#include <iostream>
using namespace std;

int main()
{
  const double QUARTER = 0.25, DIME = 0.10, NICKEL = 0.05, PENNY = 0.01;
  int quarters, dimes, nickels, pennies, dollars, cents;
  double value;

  cout << "Please enter your amount in the format of dollars and cents separated by a space: " << endl;
  cin >> dollars;
  cin >> cents;
  cout << dollars << " dollars and " << cents << " cents are:" << endl;

  value = dollars + cents/100.0;
  quarters = value/QUARTER;
  value -= quarters * QUARTER;
  dimes = value/DIME;
  value -= dimes * DIME;
  nickels = value/NICKEL;
  value -= nickels * NICKEL;
  pennies = value/PENNY;

  cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies";

  return 0;
}
