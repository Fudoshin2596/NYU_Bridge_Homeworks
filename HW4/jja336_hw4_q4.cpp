#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num, length, sentinal = -1, count=0;
  double product = 1;

  cout << "Version A) ...." << endl;
  cout << "Please enter the length of the sequence: ";
  cin >> length;
  cout << "Please enter your sequence:" << endl;
  for (int i=0; i < length; i++)
    {
      cin >> num;
      product *= num;
    }
  cout << "The geometric mean is: " << pow(product, 1.0/length) << "\n\n";

  cout << "Version B) ...." << endl;
  product = 1;
  cout << "Please enter a non-empty sequence of positive integers, each one in a separate line. End your sequence by typing -1:" << endl;
  while (num != sentinal)
    {
      cin >> num;
      if (num == sentinal)
        break;
      else
      {
        product *= num;
        count++;
      }
    }
  cout << "The geometric mean is: " << pow(product, 1.0/length) << endl;

  return 0;
}
