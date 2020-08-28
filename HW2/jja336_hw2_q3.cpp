#include <iostream>
using namespace std;

int main()
{
  const int MINUTESINDAY = 1440, MINUTESINHOUR = 60;
  int johndays, johnhours, johnminutes, billdays, billhours, billminutes, total_time_in_minutes, totaldays, totalminutes, totalhours;

  cout << "Please enter the number of days John has worked: ";
  cin >> johndays;
  cout << "Please enter the number of hours John has worked: ";
  cin >> johnhours;
  cout << "Please enter the number of minutes John has worked: ";
  cin >> johnminutes;

  cout << "\n";

  cout << "Please enter the number of days Bill has worked: ";
  cin >> billdays;
  cout << "Please enter the number of hours Bill has worked: ";
  cin >> billhours;
  cout << "Please enter the number of minutes Bill has worked: ";
  cin >> billminutes;

  total_time_in_minutes = (johndays + billdays) * MINUTESINDAY + (johnhours + billhours) * MINUTESINHOUR + (johnminutes + billminutes);
  totaldays = total_time_in_minutes/MINUTESINDAY;
  totalhours = (total_time_in_minutes % MINUTESINDAY)/MINUTESINHOUR;
  totalminutes = (total_time_in_minutes % MINUTESINDAY) % MINUTESINHOUR;

  cout << "The total time both of them worked together is: " << totaldays << " days, " << totalhours << " hours and " << totalminutes << " minutes." << endl;

  return 0;
}
