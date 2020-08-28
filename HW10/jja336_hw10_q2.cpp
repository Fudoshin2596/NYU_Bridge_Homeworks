#include<iostream>
#include<string>
using namespace std;

int* userinput(int& n);
int* findMissing(int* numPtr, int n, int& resArrSize);
void printArr(int* arr, int resArrSize);

int main()
{
  int n;
  int resArrSize = 0;

  int* numPtr = userinput(n);

  int* arr = findMissing(numPtr, n, resArrSize);

  printArr(arr, resArrSize);

  return 0;
}

int* userinput(int& n)
{
  cout << "Enter array size (n): ";
  cin >> n;
  int* numPtr = new int[n + 1];

  cout << "Input contents of array. All elements in should be in the range 0…n:\n";
  for (int i = 0; i < n; i++)
    {cin >> numPtr[i];}

  return numPtr;
}

int* findMissing(int* numPtr, int n, int& resArrSize)
{
  int max = 1;
  int* arr = new int[max];

  for (int i = 0; i < n; i++)
  {
    cout << numPtr[i] << "...." << i << endl;
    if (numPtr[i] != i)
      {arr[i] = i;}
    resArrSize++;
    if (resArrSize >= max)
      {
        max++;
        int* temp = new int[max];
        for (int i=0; i<resArrSize; i++)
          {temp[i] = arr[i];}
        delete [] arr;
        arr = temp;
      }
  }

  return arr;
}

void printArr(int* arr, int resArrSize)
{
  cout << "array of size " << resArrSize << " with contents" << endl;
  for (int z = 0; z < resArrSize; z++)
  {cout << arr[z] << " ";}
}
