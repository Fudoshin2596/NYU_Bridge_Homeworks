#include <iostream>
#include <cmath>
using namespace std;

int main()
{
  double a, b, c, discriminant, sol1, sol2;

  cout << "Please enter value of a:";
  cin >> a;
  cout << "Please enter value of b:";
  cin >> b;
  cout << "Please enter value of c:";
  cin >> c;

  discriminant = b*b - 4*a*c;

  if ((a == 0) && (b == 0) && (c == 0))
    {
      cout << "This equation has an infinite number of solutions ";
    }
  else if ((a == 0) && (b == 0) && (c != 0))
    {
      cout << "This equation has no solutions ";
    }
  else if (discriminant < 0)
    {
      cout << "This equation has no real solutions";
    }
  else if (discriminant == 0)
    {
      sol1 = (-b + sqrt(discriminant)) / (2*a);
      cout << "This equation has one real solution x=" << sol1;
    }
  else if (discriminant > 1)
    {
      sol1 = (-b + sqrt(discriminant)) / (2*a);
      sol2 = (-b - sqrt(discriminant)) / (2*a);
      cout << "This equation has two single real solutions x= "<< sol1 <<" and "<< sol2;
    }

  return 0;
}
