#include <iostream>
#include <string>
using namespace std;

int main()
{
  int n, lineCount, starCount, maxstars;
  string space="", numOfStars;

  cout<<"Please enter a positive integer:";
  cin>>n;
  maxstars = 2 * (n - 1) + 1;
  for(lineCount = 0; lineCount < n; lineCount++)
    {
    // Top of triangle
    for(starCount = maxstars; starCount >= 1; starCount--)
      space = string(lineCount,' ');
      numOfStars = string(maxstars,'*');
      cout << space << numOfStars << space;
    maxstars-=2;
    cout<<endl;
    }

  maxstars = 1;
  for(lineCount = n-1; lineCount >= 0; lineCount--)
    {
      // Bottom of triangle
      for(starCount = maxstars; starCount <= 2 * (n - 1) + 1; starCount++)
          space = string(lineCount,' ');
          numOfStars = string(maxstars,'*');
          cout << space << numOfStars << space;
      maxstars+=2;
      cout<<endl;
    }

  return 0;
}
