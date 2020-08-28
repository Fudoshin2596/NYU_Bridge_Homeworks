#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  int num, count, numdigits, num_even, num_odd;
  double start_at;

  cout << " Please input a positive integer: ";
  cin >> num;


  for (int i = 2; i < num; i+=2)
  {
    // cout << "Calc based on ..." << i << endl;
    int temp = i;
    numdigits = 0;
    while (temp != 0)
    {
      temp = temp / 10;
      numdigits++;
    }
    // cout << i << " has " << numdigits <<" digits" << endl;
    start_at = pow(10.0, numdigits-1);
    // cout << "Will start in the " << start_at << "'s place" << endl;
    num_even = 0;
    num_odd = 0;
    if (start_at > 1)
    {
      int temp2 = i;
      while ((start_at > 1) && (temp2 != 0))
      {
        // cout << "Current decimal place is " << start_at << endl;
        // cout << "Cal based on i of " << temp2 << endl;
        int val = temp2 / (int)start_at;
        // cout << " Val is ..." << val << endl;
        if ((val % 2) == 0)
          {
            num_even += 1;
            // cout << " Num even at.." << num_even << endl;
          }
        if ((val % 2) > 0)
          {
            num_odd += 1;
            // cout << " Num odd at.." << num_odd << endl;
          }
        // cout << "Current decimal place is " << start_at << endl;
        temp2 -= start_at;
        start_at /= 10;
        // cout << "Decremented to decimal place of " << start_at << endl;
      }
      // cout << "Out of While loop!" << endl;
      if (num_even > num_odd)
        {cout << i << endl;}
    }
    else {cout << i << endl;}
  }

  return 0;
}
