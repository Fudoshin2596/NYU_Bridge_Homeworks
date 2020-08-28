#include <iostream>
using namespace std;

int main()
{
  const int FLOOR_ROUND = 1;
  const int CEILING_ROUND = 2;
  const int ROUND = 3;

  int choice;
  float num, remiander;

  cout << "Please enter a Real number:" << endl;
  cin >> num;
  cout << "Choose your rounding method:" << endl;
  cout << "1. Floor round" << endl;
  cout << "2. Ceiling round" << endl;
  cout << "3. Round to the nearest whole number" << endl;
  cin >> choice;

  remiander =  (num - (int)num) * 10;

  switch(choice)
  {
    case 1:
      cout << (int)num / 1;
      break;
    case 2:
      {cout << (int)num + 1;}
      break;
    case 3:
      if (remiander < 5)
        { cout << (int)num; }
      else { cout << (int)num + 1;}
      break;
    default:
      break;
  }

  return 0;
}
