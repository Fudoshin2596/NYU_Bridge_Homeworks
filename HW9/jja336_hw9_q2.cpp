#include<iostream>
#include<string>
using namespace std;

void get_uniques(int numchars[], string sentence);
// fill a vector with unique chars in sentence

int main(){
  int anagram1[26], anagram2[26];
  string sentence1, sentence2;

  cout << "Please enter a line of text:" << endl;
  getline(cin, sentence1);
  cout << "Now enter another line of text:" << endl;
  getline(cin, sentence2);

  get_uniques(anagram1, sentence1);
  get_uniques(anagram2, sentence2);

  for (int i = 0; i < 26; i++)
  {
    if (anagram1[i] != anagram2[i])
      {
        cout << "Not anagram" << endl;
        return 0;
      }
  }
  cout << "Anagram" << endl;

  return 0;
}

void get_uniques(int numchars[], string sentence)
{
  for (int i = 0; i < 26; i++)
    {
      numchars[i] = 0;
      for (int i = 0; i < sentence.length(); i++)
      {
        char c = toupper(sentence[i]);
        if (isalpha(c))
        {
          int idx = static_cast<int>(c);
          int base = static_cast<int>('A');
          numchars[idx-base]++;
        }
      }
    }
}
