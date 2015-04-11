#ifndef NAME_H_INCLUDED
#define NAME_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Name
{
private:
string first;
string last;
public:
//Constructors
/* Name default constructor:
* Input:
*  none
* Process:
*  sets object's data members to default values
* Output:
*  object's data members are set
*/


Name()
{
first="";
last="";
}


/* Name constructor 2 - accepts 2 arguments:
* Input:
*  firstname - contestants first name
*  lastname - contestants last name
* Process:
*  sets the member variable first = firstname
*  sets the member variable last = lastname
* Output:
*  object's data members are set
*/


Name(string firstname,string lastname)
{
first=firstname;
last=lastname;
setFirstname("");
setLastname("");
}


// mutators (or setter member functions)
void setFirstname(string);
void setLastname(string);

// accessors (or getter member functions)
string getFirstname() const;
string getLastname() const;

};
#endif // NAME_H_INCLUDED
