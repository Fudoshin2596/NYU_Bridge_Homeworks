#include <iostream>
using namespace std;

int main()
{
  int num, sentinal = 1;

  cout << "Please enter a positive integer: ";
  cin >> num;

  cout << "This is the while loop version:" << endl;
  while (sentinal <= num)
    {
      cout << 2*sentinal << endl;
      sentinal++;
    }

  cout << "This is the for loop version:" << endl;
  for (sentinal=1; sentinal <= num; sentinal++)
    {
      cout << 2*sentinal << endl;
    }

  return 0;
}
