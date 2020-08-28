#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;

int digit_to_int(char c);
//Used in the definition of the overloaded input operator >>.
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int('3') returns 3.

class Money
{
  public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns the sum of the values of amount1 and amount2.
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns amount1 minus amount2.
    friend Money operator -(const Money& amount);
    //Precondition: amount has been given a value.
    //Returns the negative of the value of amount.
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Precondition: amount1 and amount2 have been given values.
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    Money( );
    //Initializes the object so its value represents $0.00.
    double get_value() const;
    //Precondition: The calling object has been given a value.
    //Returns the amount of money recorded in the data portion of the calling object.
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
  private:
    long all_cents;
};

Money operator +(const Money& amount1, const Money& amount2)
{
  Money temp;
  temp.all_cents = amount1.all_cents + amount2.all_cents;
  return temp;
}

Money operator -(const Money& amount1, const Money& amount2)
{
  Money temp;
  temp.all_cents = amount1.all_cents - amount2.all_cents;
  return temp;
}

Money operator -(const Money& amount)
{
  Money temp;
  temp.all_cents = -amount.all_cents;
  return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
  return (amount1.all_cents == amount2.all_cents);
}

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
  char one_char, decimal_point, digit1, digit2; //digits for the amount of cents
  long dollars;
  int cents;
  bool negative; //set to true if input is negative.
  ins >> one_char;
  if (one_char == '−')
    {
      negative = true;
      ins >> one_char; //read '$'
    }
  else
    negative = false;

  //if input is legal, then one_char == '$'
  ins >> dollars >> decimal_point >> digit1 >> digit2;
  if (one_char != '$' || decimal_point != '.' || !isdigit(digit1) || !isdigit(digit2))
  {
    cout << "Error illegal form for money input\n";
    exit(1);
  }
  cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);
  amount.all_cents = dollars * 100 + cents;
  if (negative)
    amount.all_cents =- amount.all_cents;
  return ins;
}

int digit_to_int(char c)
{
  return ( static_cast<int>(c) - static_cast<int>('0') );
}

//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
  long positive_cents, dollars, cents;
  positive_cents = labs(amount.all_cents);
  dollars = positive_cents/100;
  cents = positive_cents%100;

  if (amount.all_cents < 0)
    outs << "− $" << dollars << '.';
  else
    outs << "$" << dollars << '.';

  if (cents < 10)
    outs << '0';
    outs << cents;

  return outs;
}

Money::Money(long dollars, int cents)
{
  if (dollars * cents < 0) //If one is negative and one is positive
  {
    cout << "Illegal values for dollars and cents.\n";
    exit(1);
  }
  all_cents = dollars * 100 + cents;
}

Money::Money(long dollars) : all_cents(dollars * 100){}

Money::Money() : all_cents(0){}

double Money::get_value() const
{
  return (all_cents * 0.01);
}

class Check
{
  public:
    Check(string chkNo, Money chkAmt, bool chkCashd);
    Check( );

    void setNumber(string no);
    void setAmount(Money amt);
    void setCashed(bool cashd);

    string getNumber();
    Money getAmount();
    bool getCashed();

    friend istream& operator >>(istream& ins, Check& chk);
    friend ostream& operator <<(ostream& outs, const Check& chkInfo);

  private:
    string number;
    Money amount;
    bool cashed;
};

Check::Check() : number(), amount(), cashed(false){}

Check::Check(string chkNo, Money chkAmt, bool chkCashd)
{
  number = chkNo;
  amount = chkAmt;
  cashed = chkCashd;
}

void Check::setNumber(string no)
{
  number = no;
}

void Check::setAmount(Money amt)
{
  amount = amt;
}

void Check::setCashed(bool cashd)
{
  cashed = cashd;
}

string Check::getNumber()
{
  return number;
}

Money Check::getAmount()
{
  return amount;
}

bool Check::getCashed()
{
  return cashed;
}

istream& operator >>(istream& ins, Check& chk)
{
  int cashd;
  string no;
  Money amt;

  while ( !(ins >> no) || !(ins >> amt) || !(ins >> cashd))
  {
    ins.clear();
    cin.ignore(80, '\n');
    cout << "Error illegal form of input for Check. Try again>\n";
  }
  cin.ignore(80, '\n');
  chk.number = no;
  chk.amount = amt;
  chk.cashed = cashd;
  return ins;
}

ostream& operator <<(ostream& outs, const Check& chkInfo)
{
  outs << "Check No: " << chkInfo.number << ", Amount: " << chkInfo.amount << ", ";
  if (chkInfo.cashed)
    outs << "Cashed";
  else
    outs << "Not cashed";
  return outs;
}

int main()
{
  const int size = 10;
  Check checks[size];
  int count = 0, k =0, j = 0;
  double initBal, finalBal, deposit, CheckAmts = 0, depositAmts = 0, checkCashedAmts = 0;
  double deposits[size];
  char ans;
  vector<string> uncashedChecks, cashedChecks;
  cout << " Enter intial account balance: " << endl;
  cin >> initBal;
  cout << " Enter deposit amount (max 5, -1 to stop): " << endl;
  cin >> deposit;
  while (deposit != -1 && count<size)
  {
    deposits[count] = deposit;
    count++;
    cin >> deposit;
  }

  for (int i = 0; i<count; i++)
  {
    initBal = initBal + deposits[i];
    depositAmts = depositAmts + deposits[i];
  }

  count = 0;
  do
  {
    cout << "Enter check details ( Check number (x###, i.e x100) | $ amount | if cashed or Not (1 = yes / 0 = No): " << endl;
    cin >> checks[count];
    cout << " Would you like to enter details for another check? (y/n):" << endl;
    cin >> ans;
    count++;
  }
  while ( ans == 'y' || ans == 'Y');

    for (int i = 0; i < size; i++)
    {
      double value = (checks[i].getAmount()).get_value();
      if (checks[i].getCashed())
      {
        initBal = initBal - value;
        checkCashedAmts = checkCashedAmts + value;
        cashedChecks.push_back(checks[i].getNumber());
      }
      else if (checks[i].getNumber() != "")
        uncashedChecks.push_back(checks[i].getNumber());
      CheckAmts =  CheckAmts + value;
    }

  sort(uncashedChecks.begin(), uncashedChecks.end());
  sort(cashedChecks.begin(), cashedChecks.end());

  cout << "\nThe final balance is: $" << initBal << endl;
  cout << "The total amount of deposits made: $" << depositAmts << endl;
  cout << "The total amount of all checks: $" << CheckAmts << endl;
  cout << "The total amount of all checks cashed: $" << checkCashedAmts << endl;

  if (cashedChecks.size() > 0)
  {
    cout << "The sorted list of cashed checks is:" << endl;
    for (int i = 0; i < cashedChecks.size(); i++)
      cout << cashedChecks[i] << ", ";
      cout << endl;
  }

  if (uncashedChecks.size() > 0)
  {
    cout << "The sorted list of uncashed checks is:" << endl;
    for (int i = 0; i < uncashedChecks.size(); i++)
      cout << uncashedChecks[i] << ", ";
      cout << endl;
  }

  return 0;
}
