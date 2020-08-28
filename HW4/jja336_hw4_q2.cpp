#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
  const int I=1,  V=5,  X=10,  L=50,  C=100,  D=500,  M=1000;
  int num, placeholder, limit_one = 1, limit_four = 4;
  string roman = "";

  cout << "Enter decimal number:" << endl;
  cin >> num;
  placeholder = num;

  while (num > 0)
    {
      if ((num % M) < num)
          roman += string(num / M, 'M');
          num -= (num / M) * M;
            if ((num % D) < num)
                roman += string(limit_one, 'D');
                num -= (num / D) * D;
                if ((num % C) < num)
                    roman += string(min(limit_four, (num / C)), 'C');
                    num -= (num / C) * C;
                    if ((num % L) < num)
                        roman += string(limit_one, 'L');
                        num -= (num / L) * L;
                        if ((num % X) < num)
                            roman += string(min(limit_four, (num / X)), 'X');
                            num -= (num / X) * X;
                            if ((num % V) < num)
                                roman += string(limit_one, 'V');
                                num -= (num / V) * V;
                                if ((num % I) < num)
                                    roman += string(min(limit_four, (num / I)), 'I');
                                    num -= (num / I) * I;
    }

  cout << placeholder << " is " << roman;

  return 0;
}
