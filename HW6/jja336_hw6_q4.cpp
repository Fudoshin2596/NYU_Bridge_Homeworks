#include <iostream>
#include <cmath>
using namespace std;

void printDivisors(int num);
//This function is given a positive integer num, and prints all of num’s divisors in an ascending
//order, separated by a space.

int main()
{
  int num;

  cout << "Please enter a positive integer >= 2: ";
  cin >> num;
  printDivisors(num);

  return 0;
}

void printDivisors(int num)
{
  for (int i=1; i<=num; i++)
  {
    if (num % i == 0)
      cout << i << " ";
  }
}
