/*
Name: Assignment#5: Bank Accounts-using Dynmaic Memory Allocation
Author: Aharon Mishiev
Date: 10/24/2013
Description: This program reads and stores account information
of bank customers into an of array of a class,information includes:
first and last name, social security,account number, type and balance.
Then the programs functions use the arrays and modifies them
with the users choice and returns the number of accounts and the
printout of the modified account information , all using private
member functions and setters and getters.
*/


#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>		//needed to use system() function

#include "Account.h"
#include "Bank.h"
#include "Depositor.h"
#include "Name.h"
#include "Transaction.h"

using namespace std;

const int max_accts=100;

// Function Prototypes
void read_accts(Bank &chase);
void print_accts(Bank chase,ofstream &outfile);
void menu();
void mypause(void);



int main()
{
char choice;
bool not_done = true;

Bank chase;

// open output file
//ofstream outfile("/users1/st/amishiev/Desktop/HW-5-Bank Accounts-using Dynmaic Memory Allocation/bankoutput.txt");
ofstream outfile("C:\\Users\\Ron\\Desktop\\Advanced C++\\HW-5-Bank Accounts-using Dynmaic Memory Allocation\\bankoutput.txt");

outfile.setf(ios::fixed,ios::floatfield);
outfile.precision(2);                       //set decimal precision

/* first part */
/* fill and print initial database */
read_accts(chase);
print_accts(chase,outfile);

/* second part */
/* prompts for a transaction and then */
/* call functions to process the requested transaction */
do
{
menu();
cin >> choice;
switch(choice)
{
case 'w':
case 'W':
    chase.Withdrawal(outfile);
   break;
case 'd':
case 'D':
    chase.Deposit(outfile);
    break;
case 'n':
case 'N':
    chase.openAccount(outfile);
    break;
case 'b':
case 'B':
    chase.findBalance(outfile);
    break;
case 'i':
case 'I':
    chase.account_info(outfile);
    break;
case 'h':
case 'H':
    chase.account_infoHist(outfile);
    break;
case 'c':
case 'C':
    chase.closeAccount(outfile);
    break;
case 'r':
case 'R':
    chase.reopenAccount(outfile);
    break;
case 'x':
case 'X':
    chase.deleteAccount(outfile);
    break;
case 'q':
case 'Q':
    not_done = false;
    print_accts(chase,outfile);
    break;
default:
outfile << "\n\nError: '"<< choice << "' is an invalid selection-try again\n\n";
        break;
}
// give user a chance to look at output before printing menu
mypause();
}
while (not_done);

outfile.close();                            // close output file

// system("pause");
return 0;
}




/* Function read_accts()
* Input:
*  account - array of customers information which contains:
first and last name,social security,account number, type and balance.
*  max_accts - maximum number of active accounts allowed
* Process:
*  Reads the initial database of accounts and balances
* Output:
*Fills in the initial account and balance arrays
*Returns the number of active accounts
*/


void read_accts(Bank &chase)
{
string firstname,lastname;
int sosec_num;
int acct_num;
double acct_balance;
string acct_type;

// open input file
//ifstream dbfile("/users1/st/amishiev/Desktop/HW-5-Bank Accounts-using Dynmaic Memory Allocation/myinput.txt");
ifstream dbfile("C:\\Users\\Ron\\Desktop\\Advanced C++\\HW-5-Bank Accounts-using Dynmaic Memory Allocation\\myinput.txt");



int count = 0;                          //initialize count

while (dbfile >> firstname && count < max_accts)
{
dbfile >> lastname;
dbfile >> sosec_num;
dbfile >> acct_num;
dbfile >> acct_type;
dbfile >> acct_balance;

//chase.getAccount(count).setDepositor(sosec_num,setName(firstname,lastname));

//chase.getAccount(count)->setDepositor();

chase.setAccount(count,acct_num,acct_type,acct_balance,firstname,lastname,sosec_num);

//chase.addAccount(account);
count++;
}
dbfile.close();                     // close input file
chase.setNumberOfAccounts(count);
}




/* Function print_accts:
* Input:
*  account - array of customers information which contains:
first and last name,social security,account number, type and balance.
*  num_accts - number of active accounts
*  dbfile - reference to output file
* Process:
*  Prints the database of accounts and balances
* Output:
*  Prints the database of accounts and balances
*/


void print_accts(Bank chase, ofstream &outfile)
{
//Account account;
//Depositor depositor;
//Name name;

outfile.setf(ios::fixed,ios::floatfield);
outfile.precision(2);             //set decimal precision

outfile << endl << endl;
outfile << "\t\tDatabase of Bank Accounts\n\n";
outfile << "First\tLast\tSocial Security\tAccount#\tType\t\tBalance\t\tStatus\n\n";
for (int index = 0; index < chase.getNumberOfAccounts(); index++)
{
//account=chase.getAccount(index);
//depositor=account.getDepositor();
//name=depositor.getName();

//outfile << name.getFirstname();
//outfile << "\t" << name.getLastname();
//outfile << "\t"<< depositor.getSSN();
outfile << "\t"<< chase.getAccount(index)->getAccountNumber();
outfile << "\t\t"<< chase.getAccount(index)->getAccountType();
outfile << "\t\t$"<< chase.getAccount(index)->getBalance();
outfile << endl;
}

return;
}




/* Function menu()
* Input:
*  none
* Process:
*  Prints the menu of transaction choices
* Output:
*  Prints the menu of transaction choices
*/


void menu()
{
cout << endl << endl;
cout << "Select one of the following transactions:" << endl;
cout << "\t****************************" << endl;
cout << "\t    List of Choices         " << endl;
cout << "\t****************************" << endl;
cout << "\t     W -- Withdrawal" << endl;
cout << "\t     D -- Deposit" << endl;
cout << "\t     N -- New Account" << endl;
cout << "\t     B -- Balance Inquiry" << endl;
cout << "\t     I -- Account Info" << endl;
cout << "\t     H -- Account Info plus Account Transaction History" << endl;
cout << "\t     C -- Close Account" << endl;
cout << "\t     R -- Reopen a Closed Account" << endl;
cout << "\t     X -- Delete Account Permanently" << endl;
cout << "\t     Q -- Quit" << endl;
cout << endl << "\tEnter your selection: ";
return;
}



// Function mypause()
void mypause(void)
{
system("pause");
return;
}
