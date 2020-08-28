#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main()
{
  const int BASE = 2;
  int num, placeholder, initial = 10;
  string base_two = "";

  cout << "Enter decimal number:" << endl;
  cin >> num;
  placeholder = num;

  // Not sure what power of 2 to start at so need to overshoot then modify
  while (num > pow(BASE, initial))
    {initial++;}

  // Start with min power to start with binary 1
  while (num / (pow(BASE, initial)) < 1)
    {initial--;}

  while (initial >= 0)
    {
      if ((num / pow(BASE, initial)) >= 1)
        {
          base_two += "1";
          num -= pow(BASE, initial);
        }
      else {base_two += "0";}
      initial--;
    }

  cout << "The binary representation of " << placeholder << " is " << base_two;

  return 0;
}
