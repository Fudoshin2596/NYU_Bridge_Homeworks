#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void printShiftedTriangle(int n, int m, string symbol);
//Print an n-line triangle, filled with symbol characters, shifted m spaces from the left
// margin.

void printPineTree(int n, string symbol);
//It prints a sequence of n triangles of increasing sizes (the smallest triangle is a 2-line
//triangle), which form the shape of a pine tree. The triangles are filled with the symbol
//character.

int main()
{
  int n , m;
  string symbol="";

  cout << "Enter an numbner n for the amount of lines in the triangle,"
       << " followed by a number m for how many spaces from the left margin "
       << "it will be shifted and a symbol to use, such that ( n, m, symbol)."
       << endl;
  cin >> n
      >> m
      >> symbol;
  printShiftedTriangle(n, m, symbol);

  printPineTree(n, symbol);

  return 0;
}

void printShiftedTriangle(int n, int m, string symbol)
{
  int lineCount, symbolCount, maxsymbol;
  string leftmargin ="", space="", numOfSymbol;

  maxsymbol = 1;
  for(lineCount = n-1; lineCount >= 0; lineCount--)
    {
      for(symbolCount = maxsymbol; symbolCount <= 2 * (n - 1) + 1; symbolCount++)
          leftmargin = string(m,' ');
          space = string(lineCount,' ');
          cout << leftmargin << space;
          for (int k = 0; k < maxsymbol; k++)
            {cout << symbol;}
          cout << space;
      maxsymbol+=2;
      cout<<endl;
    }
}

void printPineTree(int n, string symbol)
{

}
