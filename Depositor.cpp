#include <string>
#include "Depositor.h"

using namespace std;


/* Depositor member function setName:
 * Input:
 *  firstname - object's first name
 *  lastname - object's last name
 * Process:
 *  calls name.setFirstname() and name.setLastname()
 * Output:
 *  none
 */


void Depositor::setName(string firstname,string lastname)
{
getName().setFirstname(firstname);
getName().setLastname(lastname);
return;
}


/* Depositor member function setSSN:
 * Input:
 *  sosec_num - accounts social security number
 * Process:
 *  sets the member variable ssn=sosec_num
 * Output:
 *  none
 */


void Depositor::setSSN(int sosec_num)
{
ssn=sosec_num;
return;
}



/* Depositor member function getName:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable name
 * Output:
 *  returns the object's name
*/


Name Depositor::getName() const
{
return(name);
}


/* Depositor member function getSSN:
 * Input:
 *  none
 * Process:
 *  retrieves the value of member variable ssn
 * Output:
 *  returns the object's ssn
*/


int  Depositor::getSSN() const
{
return(ssn);
}
