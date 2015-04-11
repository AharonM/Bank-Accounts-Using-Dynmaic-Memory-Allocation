#ifndef DEPOSITOR_H_INCLUDED
#define DEPOSITOR_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include "Name.h"
using namespace std;


class Depositor
{
private:
    int ssn;
    Name name;

public:
   void account_info(ofstream &) const;

//Constructors
/* Depositor deafult constructor - accepts 1 argument:
* Input:
*  ssn - accounts social security number
* Process:
*  sets the member variable first = firstname
*  sets the member variable last = lastname
* Output:
*  object's data members are set
*/

Depositor()
{
ssn=0;
}

/* Depositor constructor 2 :
* Input:
*  none
* Process:
*  calls setSSN() and send the value of 0
* Output:
*  none
*/

Depositor(int sosec_num)
{
ssn=sosec_num;
setSSN(0);
}

// mutators (or setter member functions)
void setSSN(int);
void setName(string,string);

// accessors (or getter member functions)
int getSSN() const;
Name getName() const;
};


#endif // DEPOSITOR_H_INCLUDED
