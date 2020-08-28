#include <iostream>
#include<cmath>
using namespace std;

int main()
{
  const double KG = 0.453592, METER = 0.0254;
  double weight, height, bmi;

  cout << "Please enter weight (in pounds):";
  cin >> weight;
  cout << "Please enter height (in inches):";
  cin >> height;

  bmi = (weight*KG)/((height*METER)*(height*METER));

  if (bmi < 18.5)
     {cout << "The weight status is: Underweight";}
  else if ((bmi >= 18.5) && (bmi < 25.0))
     {cout << "The weight status is: Normal";}
  else if ((bmi >= 25.0) && (bmi < 30))
    { cout << "The weight status is: Overweight";}
  else { cout << "The weight status is: Obese";}

  return 0;
}
