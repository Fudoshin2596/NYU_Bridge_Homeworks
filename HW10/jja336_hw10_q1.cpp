#include<iostream>
#include<string>
using namespace std;

string *createWordsArray(string sentence, int& outWordsArrSize);

void printArr(string* arr, int outWordsArrSize);

int main()
{
  string sentence;
  int outWordsArrSize = 0;

  cout << "Please enter a line of text:" << endl;
  getline(cin, sentence);

  string* arr = createWordsArray(sentence, outWordsArrSize);

  // printArr(arr, outWordsArrSize);

  return 0;
}

string *createWordsArray(string sentence, int& outWordsArrSize)
{
  int max = 1;
  string* arr = new string[max];
  string delimiter = " ", word;

  while(word != sentence)
  {
    word = sentence.substr(0,sentence.find_first_of(delimiter));
    arr[outWordsArrSize] = word;
    sentence = sentence.substr(sentence.find_first_of(delimiter) + 1);
    outWordsArrSize++;

    if (outWordsArrSize >= max)
    {
      max = max * 2;
      string* temp = new string[max];
      for (int i=0; i<outWordsArrSize; i++)
        {temp[i] = arr[i];}
      delete [] arr;
      arr = temp;
    }
  }

  return arr;
}

void printArr(string* arr, int outWordsArrSize)
{
  cout << "array of size " << outWordsArrSize << " with contents" << endl;
  for (int z = 0; z < outWordsArrSize; z++)
  {cout << arr[z] << " ";}
}
