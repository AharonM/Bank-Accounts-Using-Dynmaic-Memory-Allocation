#include <iostream>
#include <string>
#include <fstream>

#include "Account.h"
#include "Bank.h"

using namespace std;



/* Bank member function setAccount():
 * Input:
 * acct_num - Account number
 * acct_type - Account type(Checking,Savings,CD)
 * acct_balance - Account Balance
 * Process:
 * uses account[count].setAccountNumber() to set the Accounts number
 * uses account[count].setAccountType() to set the Accounts type
 * uses account[count].setBalance() to set the Accounts Balance
 * Output:
 * none
 */


void Bank::setAccount(int count,int acct_num,string acct_type,double acct_balance,string firstname,string lastname,int sosec_num)
{
new Account*[count];
account[count]->setDepositor(firstname,lastname,sosec_num);
account[count]->setAccountNumber(acct_num);
account[count]->setAccountType(acct_type);
account[count]->setBalance(acct_balance);
//getAccount(count)->setStatus(acct_num);
return;
}

/* Bank member function setNumberOfAccounts:
 * Input:
 *  num_accts - number of accounts currently active in the bank
 * Process:
 *  sets the value for member variable num_accts
 * Output:
 *  none
 */

void Bank::setNumberOfAccounts(int num_accts)
{
numAccts=num_accts;
}




/* Bank member function getAccount:
 * Input:
 *  index - incrementing value that searches the account array
 * Process:
 *  retrieves the value of member variable account[]
 * Output:
 *  returns the account array value of index
*/


Account* Bank::getAccount(int index)
{
Account *yPtr= account[index];
return (yPtr);
}

/* Bank member function getNumberOfAccounts:
 * Input:
 * numAccts - number of accounts currently active in the bank
 * Process:
 *  retrieves the value of member variable numAccts
 * Output:
 *  returns the number of accounts
*/


int Bank::getNumberOfAccounts() const
{
return(numAccts);
}




/* Function findBalance:
* Input:
*  outfile - reference to output file
* Process:
*  Prompts for the requested account
*  calls getNumberOfAccounts() to get the number of accounts
*  Calls findAccount() to see if the account exists
* Output:
*  If the account exists, the balance is printed
*  Otherwise, an error message is printed
*/


void Bank::findBalance(ofstream &outfile)
{
int requested_account;
int index;

cout << endl << "Enter the account number: ";
cin >> requested_account;           //prompt for account number

int numAccts= getNumberOfAccounts();

index = findAccount(account, numAccts, requested_account);
if (index == -1)                              //invalid account
{
outfile << endl << "Transaction Requested: Balance Inquiry" <<endl;
outfile << "Error: Account number " << requested_account;
outfile << " does not exist\n";
}
else                                                 //valid account
{
outfile << endl << "Transaction Requested: Balance Inquiry" <<endl;
outfile << "Account Number: " << requested_account << endl;
outfile << "Current Balance: $" << account[index]->getBalance() <<endl;
}
}




/* Function findAccount:
* Input:
*  account - array of customers information which contains:
first and last name,social security,account number, type and balance.
* numAccts - number of active accounts
* requested_account - the account which the user entered to find
* Process:
* Performs a linear search on the account[] array while calling
* getAccountNumber() to get different account numbers to compare
* with the requested account
* Output:
*  If found, the index of the requested account is returned
*  Otherwise, returns -1
*/


int Bank::findAccount(Account *account[], int numAccts, int requested_account)
{
for (int index = 0; index < numAccts; index++)
if (account[index]->getAccountNumber() == requested_account)
return index;
return -1;
}




/* Function account_info:
* Input:
*  numAccts - number of active accounts
*  sosec_num - social security number of the account to be displayed
*  outfile - reference to output file
* Process:
*  Prompts for the social security number of the holder of the account
to be displayed
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account doesn't exist an error message is printed
*  Otherwise it displays the following information of the account:
first and last name,social security,account number, type and balance.
*/


void Bank::account_info(ofstream &outfile)
{
int sosec_num;
int index;

cout << "Enter your social security number: ";
cin >> sosec_num;                       //prompt for SS#

int numAccts=getNumberOfAccounts();
index = findAccountSSN(account, numAccts , sosec_num);

if (index == -1)                       //invalid account
{
outfile << "\nTransaction Requested: Account Info\n";
outfile << "Error: An account with the social security: ";
outfile << sosec_num << " does not exist" << endl;
}
else                                  //valid account
{
//account= new Account*[index];
outfile << endl <<"Transaction Requested: Account Info"<< endl;
outfile << "First \tLast \tSocial Security Account# Type\tBalance\n";
outfile << account[index]->getDepositor().getName().getFirstname();
outfile << "\t" << account[index]->getDepositor().getName().getLastname();
outfile << "\t"<< account[index]->getDepositor().getSSN();
outfile << "\t"<< account[index]->getAccountNumber();
outfile << "\t"<< account[index]->getAccountType();
outfile << "\t$"<< account[index]->getBalance();
outfile << endl;
}
}




/* Function account_info:
* Input:
*  numAccts - number of active accounts
*  sosec_num - social security number of the account to be displayed
*  outfile - reference to output file
* Process:
*  Prompts for the social security number of the holder of the account
to be displayed
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account doesn't exist an error message is printed
*  Otherwise it displays the following information of the account:
first and last name,social security,account number, type and balance.
*/


void Bank::account_infoHist(ofstream &outfile)
{
int sosec_num;
int index;

cout << "Enter your social security number: ";
cin >> sosec_num;                       //prompt for SS#

int numAccts=getNumberOfAccounts();
index = findAccountSSN(account, numAccts , sosec_num);

if (index == -1)                       //invalid account
{
outfile << "\nTransaction Requested: Account Info\n";
outfile << "Error: An account with the social security: ";
outfile << sosec_num << " does not exist" << endl;
}
else                                  //valid account
{
outfile << endl <<"Transaction Requested: Account Info"<< endl;
outfile << "First \tLast \tSocial Security Account# Type\tBalance\n";
outfile << account[index]->getDepositor().getName().getFirstname();
outfile << "\t" << account[index]->getDepositor().getName().getLastname();
outfile << "\t"<< account[index]->getDepositor().getSSN();
outfile << "\t"<< account[index]->getAccountNumber();
outfile << "\t"<< account[index]->getAccountType();
outfile << "\t$"<< account[index]->getBalance();
outfile << "\n\nTransaction History:\n";
outfile << "Type \tAmount\n";

outfile << account[index]->getTransaction(index).getTranType()<< "\t";
outfile << account[index]->getTransaction(index).getTranAmount();
outfile << endl;

}
}








/* Function findAccountSSN:
* Input:
*  account - array of customers information which contains:
first and last name,social security,account number, type and balance.
* numAccts - number of active accounts
* requested_account - the account which the user entered to find
* Process:
*  Performs a linear search on the account[] array while calling
* depositor.getSSN() to get different social security numbers to
* compare with the requested account
* Output:
*  If found, the index of the requested account is returned
*  Otherwise, returns -1
*/


int Bank::findAccountSSN(Account *account[], int numAccts, int requested_account)
{
for (int index = 0; index < numAccts; index++)
if (account[index]->getDepositor().getSSN() == requested_account)
return index;
return -1;
}




/* Function Deposit:
* Input:
*  requested_account - the aacount which the user entered to
*  make a deposit in
*  outfile - reference to output file
* Process:
*  prompts for the requested account
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account doesnt exists an error message is printed
*  Otherwise it calls makeDeposit() to make the deposit
* Output:
*  none
*/


void Bank::Deposit(ofstream &outfile)
{

int requested_account,index;

cout << endl << "Enter the account number: ";
cin >> requested_account;                   //prompt for account number

int numAccts = getNumberOfAccounts();
index = findAccount(account, numAccts, requested_account);

if (index == -1)                            //invalid account
{
outfile << endl << "Transaction Requested: Deposit" << endl;
outfile << "Error: Account number " << requested_account;
outfile << " does not exist" << endl;
}
else                                        //valid account
account[index]->makeDeposit(outfile,requested_account);

}




/* Function Withdrawal:
* Input:
*  requested_account - the aacount which the user entered to
*  make a withdrawal in
*  outfile - reference to output file
* Process:
*  prompts for the requested account
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account doesnt exists an error message is printed
*  Otherwise it calls makeWithdrawal() to make the withdrawal
* Output:
*  none
*/


void Bank::Withdrawal(ofstream &outfile)
{
int requested_account,index;

cout << endl << "Enter the account number: ";         //prompt for account number
cin >> requested_account;

int numAccts = getNumberOfAccounts();
index = findAccount(account, numAccts, requested_account);
if (index == -1)                                       //invalid account
{
outfile << endl << "Transaction Requested: Withdrawal" << endl;
outfile << "Error: Account number " << requested_account;
outfile << " does not exist" << endl;
}
else                                                    //valid account
account[index]->makeWithdrawal(outfile,requested_account);

}




/* Function openAccount:
* Input:
*  num_accts - number of active accounts
*  new_acctnum - number of the users requested new account
*  outfile - reference to output file
* Process:
*  Prompts for the requested new account number
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account exists an error message is printed
*  Otherwise it creates a new account with an initial balance of 0
*  calls setNumberOfAccounts() to set a new value for numAccts
* Output:
*  For a valid account creation the new account list and balances is printed
*/


bool Bank::openAccount(ofstream &outfile)
{
int new_acctnum;
int index;
int sosec_num;
string firstname;
string lastname;
string acct_type;
string type="Account Creation";
double open_deposit;

//prompt for account number
cout << endl << "Enter a new account number: ";
cin >> new_acctnum;

int numAccts=getNumberOfAccounts();
index = findAccount(account, numAccts, new_acctnum);

if (index == -1)                                   //valid request
{
//Entering info for new account
cout << endl << "Enter Your first name followed by your last name: ";
cin >> firstname >> lastname;
cout << endl << "Enter your social security number: ";
cin >> sosec_num;
cout << endl <<"Enter the account type(Checking,Savings or CD): ";
cin >> acct_type;
cout << endl<< "Enter initial opening deposit: ";
cin >>open_deposit;

//displaying entered info
outfile << endl << "Transaction Requested: Creating a new account\n" ;
outfile << "New account number: " << new_acctnum <<endl;
outfile << "First Name: " << firstname <<endl;
outfile << "Last Name: "  << lastname <<endl;
outfile << "Social security(last 4): xxx-xx-"<<sosec_num % 10000;
outfile << "\nAccount Type: " << acct_type;
outfile << "\nInitial Balance: $" << open_deposit <<endl;

//creating a new account
index=numAccts++;
new Account*[index];
account[index]->setAccountNumber(new_acctnum);
account[index]->getDepositor().getName().setFirstname(firstname);
account[index]->getDepositor().getName().setLastname(lastname);
account[index]->getDepositor().setSSN(sosec_num);
account[index]->setAccountType(acct_type);
account[index]->setBalance(open_deposit);
account[index]->setTransaction(type,open_deposit);
account[index]->setStatus(true);
}
else                                                    //invalid request
{
outfile << endl << "Transaction Requested: Creating a new account\n";
outfile << "Account number requested: " << new_acctnum <<endl;
outfile<< "Error: Account number already exists." <<endl;
}
setNumberOfAccounts(numAccts);
return numAccts;
}




/* Function closeAccount:
* Input:
*  numAccts - number of active accounts
*  requested_account - number of the account to be deleted
*  outfile - reference to output file
* Process:
*  Prompts for the requested account number to be deleted
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account doesn't exist an error message is printed
*  Otherwise it deletes the requested account
*  calls setNumberOfAccounts() to set a new value for numAccts
* Output:
*  Prints the new account list and balances
*/


bool Bank::closeAccount(ofstream &outfile)
{
int index,requested_account;
double amount=0.0;
string type="Account Closing";
cout << endl << "Enter the account number you wish to close: ";    //prompt for account number
cin >> requested_account;

int numAccts=getNumberOfAccounts();
index = findAccount(account, numAccts, requested_account);
if (index == -1)                                        //invalid account
{
outfile << "Transaction Requested: Account Closing\n";
outfile << "Error: Account number: " << requested_account;
outfile << " does not exist" << endl;
}
else if(account[index]->getBalance()>0.00)               //invalid account
{
outfile << "\nTransaction Requested: Account Closing\n";
outfile << "Error: Account number: " << requested_account;
outfile << " has money on it, please withdraw it and then close the account\n";
}
else                                                    //valid account
{
outfile << endl << "Transaction Requested: Account Closing" ;
outfile << endl << "Account number to be closed:";
outfile << requested_account << endl;

for (int j = index; j < numAccts - 1; j++)         //closing requested account
{
account[j]->setAccountNumber(account[j+1]->getAccountNumber());
account[j]->getDepositor().getName().setFirstname(account[j+1]->getDepositor().getName().getFirstname());
account[j]->getDepositor().getName().setLastname(account[j+1]->getDepositor().getName().getLastname());
account[j]->getDepositor().setSSN(account[j+1]->getDepositor().getSSN());
account[j]->setAccountType(account[j+1]->getAccountType());
account[j]->setBalance(account[j+1]->getBalance());
}
account[index]->setTransaction(type,amount);
account[index]->setStatus(false);
numAccts--;
}
setNumberOfAccounts(numAccts);
return numAccts;
}










bool Bank::reopenAccount(ofstream &outfile)
{
int index,requested_account;
double amount=0.0;
string type="Account Reopening";
cout << endl << "Enter the account number you wish to Reopen: ";    //prompt for account number
cin >> requested_account;

int numAccts=getNumberOfAccounts();
index = findAccount(account, numAccts, requested_account);
if (index == -1)                                        //invalid account
{
outfile << "Transaction Requested: Account Reopening\n";
outfile << "Error: Account number: " << requested_account;
outfile << " does not exist" << endl;
}
else if(account[index]->getBalance()>0.00)               //invalid account
{
outfile << "\nTransaction Requested: Account Reopening\n";
outfile << "Error: Account number: " << requested_account;
outfile << " is already open\n";
}
else                                                    //valid account
{
outfile << endl << "Transaction Requested: Account Reopening" ;
outfile << endl << "Account number to be Reopened:";
outfile << requested_account << endl;
numAccts++;

for (int j = index; j > 0; j--)         //Reopening requested account
{
account[j]->setAccountNumber(account[j-1]->getAccountNumber());
account[j]->getDepositor().getName().setFirstname(account[j-1]->getDepositor().getName().getFirstname());
account[j]->getDepositor().getName().setLastname(account[j-1]->getDepositor().getName().getLastname());
account[j]->getDepositor().setSSN(account[j-1]->getDepositor().getSSN());
account[j]->setAccountType(account[j-1]->getAccountType());
account[j]->setBalance(account[j-1]->getBalance());
}
account[index]->setTransaction(type,amount);
account[index]->setStatus(true);
}
setNumberOfAccounts(numAccts);
return numAccts;
}



/* Function closeAccount:
* Input:
*  numAccts - number of active accounts
*  requested_account - number of the account to be deleted
*  outfile - reference to output file
* Process:
*  Prompts for the requested account number to be deleted
*  calls getNumberOfAccounts() to get numAccts
*  Calls findAccount() to see if the account exists
*  If the account doesn't exist an error message is printed
*  Otherwise it deletes the requested account
*  calls setNumberOfAccounts() to set a new value for numAccts
* Output:
*  Prints the new account list and balances
*/


bool Bank::deleteAccount(ofstream &outfile)
{
int index,requested_account;
string type="Account Deletion";
double amount= 0.0;
cout << endl << "Enter the account number you wish to delete: ";    //prompt for account number
cin >> requested_account;

int numAccts=getNumberOfAccounts();
index = findAccount(account, numAccts, requested_account);
int jTemp= index;
if (index == -1)                                        //invalid account
{
outfile << "Transaction Requested: Account Deletion\n";
outfile << "Error: Account number: " << requested_account;
outfile << " does not exist" << endl;
}
else if(account[index]->getBalance()>0.00)               //invalid account
{
outfile << "\nTransaction Requested: Account Deletion\n";
outfile << "Error: Account number: " << requested_account;
outfile << " has money on it, please withdraw it and then close the account\n";
}
else                                                    //valid account
{
outfile << endl << "Transaction Requested: Account Deletion" ;
outfile << endl << "Account number to be deleted:";
outfile << requested_account << endl;

for (int j = index; j < numAccts - 1; j++)         //deleting requested account
{
account[j]->setAccountNumber(account[j+1]->getAccountNumber());
account[j]->getDepositor().getName().setFirstname(account[j+1]->getDepositor().getName().getFirstname());
account[j]->getDepositor().getName().setLastname(account[j+1]->getDepositor().getName().getLastname());
account[j]->getDepositor().setSSN(account[j+1]->getDepositor().getSSN());
account[j]->setAccountType(account[j+1]->getAccountType());
account[j]->setBalance(account[j+1]->getBalance());

jTemp =+1;
cout<<endl<<jTemp;
}
account[jTemp]->setAccountNumber(0);
account[jTemp]->setAccountType(0);
account[jTemp]->setBalance(0);
account[jTemp]->getDepositor().setSSN(0);
account[jTemp]->getDepositor().getName().setFirstname(" ");
account[jTemp]->getDepositor().getName().setLastname(" ");
delete [] account;
numAccts--;
account[index]->setTransaction(type,amount);
}
setNumberOfAccounts(numAccts);
return numAccts;
}

