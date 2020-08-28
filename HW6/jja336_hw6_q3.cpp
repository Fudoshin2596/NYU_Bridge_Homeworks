#include <iostream>
using namespace std;

double eApprox(int n);
//This function is given a positive integer n, and returns an approximation of e, calculated by the
//sum of the first (n+1) addends of the infinite sum above.

int main() {
  cout.precision(30);
  for (int n = 1; n <= 15; n++)
  {
    cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
  }
  return 0;
}

double eApprox(int n)
{
  double basecase = 1, e = 1;
  for (int i=1; i<=n; i++)
  {
      basecase *= i;
      e += 1.0 / basecase;
  }
  return e;
}
