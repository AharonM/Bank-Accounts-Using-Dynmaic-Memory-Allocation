#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "Depositor.h"
#include "Transaction.h"
using namespace std;

const int max_tran=100;


class Account
{
private:
int num;
string type;
Depositor depositor;
bool status;
double balance;
//Transaction transaction[max_tran];
//Transaction *tPtr=new Transaction[max_tran];      //pointer to a dynamically allocated array of Transactions
Transaction *tPtr;

public:
//Constructors
/* Account deafult constructor:
* Input:
*  none
* Process:
*  sets object's data members to default values
* Output:
*  none
*/

Account()
{
num=0;
type="";
balance=0.00;
status=true;
}


/* Account constructor 2- accepts 3 arguments:
* Input:
* acct_num - Account number
* acct_type - Account type(Checking,Savings,CD)
* acct_balance - Account Balance
* Process:
* sets the member variable num=acct_num
* sets the member variable type=acct_type
* sets the member variable balance=acct_balance
* Output:
*  none
*/

Account(int acct_num,string acct_type,double acct_balance,bool acct_status)
{
num=acct_num;
type=acct_type;
balance=acct_balance;
status=acct_status;

}


/* Account constructor 3- accepts 1 argument:
* Input:
* account[]- account array
* Process:
* sets the arrays values to default values
* Output:
*  none
*/
Account(Account *account[])
{
int j=0;
account[j]->setAccountNumber(0);
account[j]->setAccountType(0);
account[j]->setBalance(0);
//account[j]->depositor.setSSN(0);
}


~Account()
{
delete [] tPtr;
tPtr=0;
}
//Public member functions
void makeDeposit(ofstream &,int);
bool makeWithdrawal(ofstream &,int);

// mutators (or setter member functions)
void setAccountNumber(int);
void setAccountType(string);
void setBalance(double);
void setDepositor(string,string,int);
void setStatus(bool);
void setTransaction(string ,double);

// accessors (or getter member functions)
int getAccountNumber() const;
string getAccountType() const;
double getBalance() const;
Depositor getDepositor() const;
bool getStatus() const;
Transaction getTransaction(int) const;
};


#endif // ACCOUNT_H_INCLUDED
