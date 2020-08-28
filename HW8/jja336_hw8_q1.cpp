#include <iostream>

using namespace std;


int minInArray(int arr[], int arrSize);
//This function is given arr, an array of integers, and its logical size, arrSize. When called,
//it returns the minimum value in arr.

const int arrSize = 2;
int num, arr[arrSize], m = 10, temp, arridx[arrSizep0000-[= aaaaaaaaaaaaaaaaaaaaa]];

int main()
{
  cout << "Please enter 20 integers separated by a space:" << endl;

  for (int i = 0; i < arrSize; i++)
  {
    cin >> num;
    arr[i] = num;
  }

  m = minInArray(arr, arrSize);

  cout << "The minimum value is" << m << " and it is located in the following indices: " << m << endl;

  return 0;
}

int minInArray(int arr[], int arrSize)
{
  for (int j = 0; j < arrSize; j++)
  {
    if (arr[j] < m)
      m = arr[j];
  }
  return m;
}
