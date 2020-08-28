#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
  srand(time(0)); //seed
  const int MAX_GUESS = 5;
  int randomNum, num_guess=0, guess;

  int uppbound = 100;
  int lowerbound = 1;

  randomNum = (rand() % uppbound) + lowerbound;
  cout << "I thought of a number between " << lowerbound <<" and "<< uppbound <<"! Try to guess it." <<endl;

  while (guess!=randomNum)
  {
    cout <<"Range: [" <<lowerbound<<","<<uppbound<<"], Number of guesses left: "<< MAX_GUESS-num_guess << endl;
    cout <<"Your guess: ";
    cin >> guess;
    if (num_guess==MAX_GUESS-1)
      {
        cout <<"Out of guesses! My number is " << randomNum;
        break;
      }
    else if (randomNum<guess)
      {
        cout <<"Wrong! My number is smaller." <<endl;
        uppbound = guess-1;
      }
    else if (randomNum>guess)
      {
        cout <<"Wrong! My number is bigger." <<endl;
        lowerbound = guess+1;
      }
    else if (randomNum==guess)
      {
        cout <<"Congrats! You guessed my number in " << num_guess+1 <<" guesses." <<endl;
      }

    num_guess++;
    cout << endl;
  }

  return 0;
}
