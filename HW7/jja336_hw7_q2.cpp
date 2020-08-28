#include <iostream>
#include <cmath>
using namespace std;

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs);
//The function takes as an input a positive integer num (≥ 2), and updates two output
// parameters with the number of num's proper divisors and their sum.

bool isPerfect(int num, int outSumDivs);
//This functions is given positive integer num (≥ 2), and determines if it is perfect number or not.

int main() {
    int num;
    int outCountDivs, outSumDivs;

    cout<<"Please enter a positive integer, num greater than or equal to 2: "<<endl;
    cin>>num;

    for (int j = 2; j <= num; j++)
    {
      analyzeDividors(j, outCountDivs, outSumDivs);

    // cout<<"The number of "<< num <<"'s proper divisors are: "<<outCountDivs<<endl;

      if (isPerfect(j, outSumDivs) == 1)
        cout << j << " is a perfect number" <<endl;
    }
    // cout <<"The sum of the proper divisors are: "<<outSumDivs<<endl;

    return 0;
}

void analyzeDividors(int num, int& outCountDivs, int& outSumDivs)
{
    outCountDivs = -1;
    outSumDivs = num * -1;

    for (int i = 1; i <= sqrt(num); i++)
    {
      if ((num % i == 0) & (((num / i) * i) == num))
      {
        outCountDivs += 2;
        outSumDivs += (i + (num / i));
      }
    }
}

bool isPerfect(int num, int outSumDivs)
{
  if (num == outSumDivs)
    return true;
  else {return false;}
}
