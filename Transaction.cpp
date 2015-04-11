#include "Transaction.h"
using namespace std;



void Transaction::setTranType(string tranType)
{
tType=tranType;
}


void Transaction::setTranAmount(double tranAmount)
{
tAmount=tranAmount;
}

string Transaction::getTranType() const
{
return(tType);
}


double Transaction::getTranAmount() const
{
return(tAmount);
}


/*
void Transaction::addTransaction(Transaction tPtr,string tranType,double tranAmount,int acctNum)
{
for(int index=0;index<max_tran;index++)
{
tPtr[index].setTranType(tranType);
tPtr[index].setTranAmount(tranAmount);
}
}
*/
