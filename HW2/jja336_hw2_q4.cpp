#include <iostream>
using namespace std;

int main()
{
  int num1, num2;

  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);

  cout << "Please enter two positive integers, separated by a space:" << endl;
  cin >> num1 >> num2;
  cout << num1 << " + " << num2 << " = " << (num1 + num2) << endl;
  cout << num1 << " - " << num2 << " = " << (num1 - num2) << endl;
  cout << num1 << " * " << num2 << " = " << (num1 * num2) << endl;
  cout << num1 << " / " << num2 << " = " << ((1.0 * num1) / num2) << endl;
  cout << num1 << " div " << num2 << " = " << (num1 / num2) << endl;
  cout << num1 << " mod " << num2 << " = " << (num1 % num2) << endl;

  return 0;
}
