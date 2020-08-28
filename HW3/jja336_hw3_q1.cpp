#include <iostream>
using namespace std;

int main()
{
  double item1price, item2price, taxrate, pretax_total, final_price;
  char clubcard;

  cout << "Enter price of first item: ";
  cin >> item1price;
  cout << "Enter price of second item: ";
  cin >> item2price;
  cout << "Does customer have a club card? (Y/N): ";
  cin >> clubcard;
  cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
  cin >> taxrate;

  if (item1price < item2price)
    {pretax_total = (item1price*0.5) + item2price;}
  else {pretax_total = (item2price*0.5) + item1price;}

  if ((clubcard == 'Y') || (clubcard == 'y'))
    {pretax_total *= (0.9);}

  final_price = pretax_total * (1 + taxrate/100);

  cout << "Base price: " << (item1price + item2price) << endl;
  cout << "Price after discounts: " << pretax_total << endl;
  cout << "Total price: " << final_price << endl;

  return 0;
}
