#include <iostream>
#include <string>
using namespace std;

int main()
{
  int num, counter=1;

  cout << "Please enter a positive integer:" << endl;
  cin >> num;

  for (int a = 0; a < num; a++)
  {
      for (int i = 1; i <= num; i++)
      {cout << i*counter << "\t";}
    cout << endl;
    counter++;
  }
  
  return 0;
}
