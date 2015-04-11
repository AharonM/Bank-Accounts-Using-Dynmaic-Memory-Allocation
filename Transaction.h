#ifndef TRANSACTION_H_INCLUDED
#define TRANSACTION_H_INCLUDED

#include <string>
using namespace std;


class Transaction
{
private:
string tType;
double tAmount;
public:

//Constructors
/* Transaction default constructor:
* Input:
*  none
* Process:
*  sets object's data members to default values
* Output:
*  object's data members are set
*/

Transaction()
{
tType=" ";
tAmount=0;
}

//void addTransaction(Transaction ,string ,double ,int );

// mutators (or setter member functions)
void setTranType(string);
void setTranAmount(double);

// accessors (or getter member functions)
string getTranType() const;
double getTranAmount() const;

};
#endif // TRANSACTION_H_INCLUDED
