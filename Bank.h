#ifndef BANK_H_INCLUDED
#define BANK_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>
#include "Account.h"
using namespace std;

const int MAX_NUM=100;

class Bank
{
private:
int numAccts;
Account *account[MAX_NUM];
public:
//Constructors
/* Bank default constructor:
* Input:
*  none
* Process:
*  sets object's data members to default values
* Output:
*  object's data members are set
*/

Bank()
{
 numAccts=0;
}

~Bank()
{
delete [] account;
}

void findBalance(ofstream &);
int findAccount(Account*[], int, int);
void account_info(ofstream &);
void account_infoHist(ofstream &);
int findAccountSSN(Account*[], int, int);
void Deposit(ofstream &);
void Withdrawal(ofstream &);
bool openAccount(ofstream &);
bool closeAccount(ofstream &);
bool reopenAccount(ofstream &);
bool deleteAccount(ofstream &);

// mutators (or setter member functions)
void setAccount(int,int,string,double,string,string,int);
void setNumberOfAccounts(int);

// accessors (or getter member functions)
Account* getAccount(int);
int getNumberOfAccounts() const;
};
#endif // BANK_H_INCLUDED
