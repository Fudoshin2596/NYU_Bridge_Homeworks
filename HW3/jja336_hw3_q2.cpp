#include <iostream>
#include <string>
using namespace std;

int main()
{
  string name, status;
  int graduation_year, current_year, gap;

  cout << "Please enter your name: ";
  cin >> name;
  cout << "Please enter your graduation year: ";
  cin >> graduation_year;
  cout << "Please enter current year: ";
  cin >> current_year;

  gap = graduation_year - current_year;

  switch(gap)
  {
    case 4:
      status = "Freshman";
      cout << name << ", you are a " << status;
      break;
    case 3:
      status = "Sophomore";
      cout << name << ", you are a " << status;
      break;
    case 2:
      status = "Junior";
      cout << name << ", you are a " << status;
      break;
    case 1:
      status = "Senior";
      cout << name << ", you are a " << status;
      break;
    default:
      if (current_year < graduation_year-4)
        {
        status = "not in college yet";
        cout << name << ", you are a " << status;
        }
      else
        {
        status = "graduated";
        cout << name << ", you have " << status;
        }
      break;
  }

  return 0;
}
