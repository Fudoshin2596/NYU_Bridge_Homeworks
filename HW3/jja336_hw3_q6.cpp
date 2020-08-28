#include <iostream>
#include <string>
using namespace std;

int main()
{
  string dayofweek;
  int hours, mins, calltime;
  double time, cost;
  char delimiter;

  cout << "Please enter a time in 24-hour notation, (i.e 1:30 P.M. is 13:30):";
  cin >> hours >> delimiter >> mins;
  cout << "Please enter a day of the week as one of the following (Mo, Tu, We, Th, Fr, Sa, Su):";
  cin >> dayofweek;
  cout << "Please enter a number of minutes as a whole number:";
  cin >> calltime;

  time = hours + mins/100.0;

  if ((dayofweek == "Sa") || (dayofweek == "Su"))
    {cost = 0.15 * calltime;}
  else if ((time < 8) || (time > 6))
    {cost  = 0.25 * calltime;}
  else {cost  = 0.40 * calltime;}

  cout << "The cost of your call will be: $" << cost << endl;

  return 0;
}
