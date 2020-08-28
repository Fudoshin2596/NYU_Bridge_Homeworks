#include<iostream>
#include<string>
#include<vector>
using namespace std;

string sentence, unique_chars, delimiters(",.'\" ");
int count = 0; //assuming all sentences end with a period
vector<int> letter(26);

void get_counts(vector<int> letter, string sentence, int count);
// fill a vector with unique chars in sentence

int main(){
  cout << "Please enter a line of text:" << endl;
  getline(cin, sentence);

  get_counts(letter, sentence, count);

  return 0;
}

void get_counts(vector<int> letter, string sentence, int count)
{
  for (int i = 0; i < sentence.length(); i++)
    {
      if (delimiters.find(sentence[i]) != string::npos)
        count++;
      else if ((unique_chars.find(tolower(sentence[i])) == string::npos) & (delimiters.find(sentence[i]) == string::npos))
        letter[tolower(sentence[i])-97]++;
    }
    cout << count << "    words" << endl;
    for (int i = 0; i < letter.size(); i++)
      {
        if (letter[i] > 0)
          cout << letter[i] << "    " << static_cast<char>(i+97) << endl;;
      }
}
