#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"

using namespace std;



/* Account member function setAccountNumber:
 * Input:
 *  acct_num - number of the account that was read in the array
 * Process:
 *  sets the member variable num=acct_num
 * Output:
 *  none
 */


void Account::setAccountNumber(int acct_num)
{
num=acct_num;
return;
}




/* Account member function setAccountType:
 * Input:
 * acct_type - Account type(Checking,Savings,CD)
 * Process:
 *  sets the member variable type=acct_type
 * Output:
 *  none
 */


void Account::setAccountType(string acct_type)
{
type=acct_type;
return;
}


/* Account member function setBalance:
 * Input:
 * acct_balance - Account Balance
 * Process:
 *  sets the member variable balance=acct_balance
 * Output:
 *  none
 */


void Account::setBalance(double acct_balance)
{
balance=acct_balance;
return;
}



void Account::setStatus(bool acct_status)
{
status=acct_status;
return;
}


/* Account member function setDepositor:
 * Input:
 *  sosec_num - object's social security number
 *  firstname - object's first name
 *  lastname - object's last name
 * Process:
 *  calls depositor.setSSN() and depositor.setName()
 * Output:
 *  none
 */

void Account::setDepositor(string firstname,string lastname,int sosec_num)
{
getDepositor().setSSN(sosec_num);
getDepositor().setName(firstname,lastname);
return;
}





void Account::setTransaction(string tranType,double tranAmount)
{
tPtr = new Transaction[max_tran];

for(int index=0;index<max_tran;index++)
{
tPtr[index].setTranType(tranType);
tPtr[index].setTranAmount(tranAmount);
}
return;
}



/* Account member function getAccountNumber:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable num
 * Output:
 *  returns a reference to the accounts number
*/


int Account::getAccountNumber() const
{
return(num);
}


/* Account member function getAccountType:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable type
 * Output:
 *  returns a reference to the accounts type
*/


string Account::getAccountType()const
{
return(type);
}


/* Account member function getBalance:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable balance
 * Output:
 *  returns a reference to the accounts balance
*/


double Account::getBalance() const
{
return(balance);
}





bool Account::getStatus() const
{
return(status);
}

/* Account member function getDepositor:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable depositor
 * Output:
 *  returns a reference to the accounts depositor
*/


Depositor Account::getDepositor() const
{
return(depositor);
}

Transaction Account::getTransaction(int index) const
{
return(tPtr[index]);
}

/* Account member function makeDeposit:
* Input:
*  requested_account - the account which the user entered to
*  make a deposit in
*  outfile - reference to output file
* Process:
* prompts for the amount to deposit
*If the amount is valid, it makes the deposit and prints the new balance
*  Otherwise, an error message is printed
* Output:
*  For a valid deposit, the deposit transaction is printed
*  Otherwise, an error message is printed
*/


void Account::makeDeposit(ofstream &outfile,int requested_account)
{
double amount_to_deposit;
string type="Deposit";
cout << "Enter amount to deposit: ";         //prompt for amount to deposit
cin >> amount_to_deposit;

if (amount_to_deposit <= 0.00)              //invalid amount to deposit
{
outfile << endl << "Transaction Requested: Deposit" << endl;
outfile << "Account Number: " << requested_account << endl;
outfile << "Error: " << amount_to_deposit;
outfile << " is an invalid amount" << endl;
}
else                                                //valid deposit
{
outfile << endl << "Transaction Requested: Deposit" << endl;
outfile << "Account Number: " << requested_account << endl;
outfile << "Old Balance: $" <<getBalance()  << endl;
outfile << "Amount to Deposit: $" << amount_to_deposit << endl;
setBalance(getBalance()  + amount_to_deposit);      //make the deposit
outfile << "New Balance: $" << getBalance() << endl;

setTransaction(type,amount_to_deposit);
}
}




/* Account member function makeWithdrawal:
* Input:
*  requested_account - the aacount which the user entered to
*  make a withdrawal in
*  outfile - reference to output file
* Process:
*  prompts for the amount to withdrawal
* If the amount is valid, it makes the withdrawal
* and prints the new balance
* if there is insufficient funds for withdrawal, an error message
* is printed
* Output:
*  For a valid withdrawal, the withdrawal transaction is printed
*  Otherwise, an error message is printed
*/


bool Account::makeWithdrawal(ofstream &outfile,int requested_account)
{
double amount_to_withdrawal;
string type="Withdrawal";

cout << "Enter amount to withdrawal: ";                //prompt for amount to withdrawal
cin >> amount_to_withdrawal;

if (amount_to_withdrawal  >  getBalance())       //invalid amount to withdrawal
{
outfile << endl << "Transaction Requested: Withdrawal" << endl;
outfile << "Account Number: " << requested_account << endl;
outfile << "Error: " << " insufficient funds" << endl;
}
else if (amount_to_withdrawal <=  0.00)
{
outfile << endl << "Transaction Requested: Withdrawal" << endl;
outfile << "Account Number: " << requested_account << endl;
outfile << "Error: " << amount_to_withdrawal;
outfile << " is an invalid amount" << endl;
}
else                                                //valid withdrawal
{
outfile << endl << "Transaction Requested: withdrawal" << endl;
outfile << "Account Number: " << requested_account << endl;
outfile << "Old Balance: $" << getBalance() << endl;
outfile << "Amount to withdrawal: $" << amount_to_withdrawal << endl;
setBalance(getBalance() - amount_to_withdrawal);      //make the withdrawal
outfile << "New Balance: $" << getBalance() << endl;

setTransaction(type,amount_to_withdrawal);
}
return true;
}
