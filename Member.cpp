/*
 * Member.cpp
 * 
 * Class Description: Models a member belonging to a Fitness Studio.
 *                    This member has the following characteristics:
 *                    name, cell phone number, email address and a credit card number.
 *                    Each member has a unique cell phone number.
 * Class Invariant: This cell phone number must have 12 digits.
 *                  This cell phone number must have the following format: XXX-XXX-XXXX.
 *                  This cell phone number cannot be modified. 
 *
 * Author: AL, Yewon Park
 */


#include <iostream>
#include <string>
#include "Member.h"
// Description: Sets the member's cell phone number - Private method
// Reflection: Why is this method not part of the public interface?
void Member::setPhone(const string aPhone)
{
   if(aPhone.length() == 12 && aPhone[3] == '-' && aPhone[7] == '-')
	{
		for(int i = 0; i < 12; i++)
		{
			if(i != 3 && i != 7)
			{
				if(aPhone[i] >= 48 && aPhone[i] <= 57)
					continue;
				else
				{
					phone = "000-000-0000";
					return;
				}	
			}
		}			
	    phone = aPhone;
	 }
	else
	    phone = "000-000-0000";
}
    
    
    
// Default Constructor
// Description: Create a member with a cell phone number of "000-000-0000". 
// Postcondition: All data members set to an empty string, 
//                except the cell phone number which is set to "000-000-0000".
Member::Member() 
{
	name = "";
	phone = "000-000-0000";
	email = "";
	creditCard = "";
}

// Parameterized Constructor
// Description: Create a member with the given cell phone number.
// Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
//                All other data members set to an empty string.
Member::Member(string aPhone)
{
	setPhone(aPhone);
	name = "";
	email = "";
	creditCard = "";    
}
	
// Parameterized Constructor
// Description: Create a member with the given name, cell phone number, email and credit card number.
// Postcondition: If aPhone does not have 12 digits, then aPhone is set to "000-000-0000".
Member::Member(string aName, string aPhone, string anEmail, string aCreditCard)
{
    name = aName;
    setPhone(aPhone);
    email = anEmail;
    creditCard = aCreditCard;
}

// Getters and setters
// Description: Returns member's name.
string Member::getName() const
{
	return name;
}

// Description: Returns member's phone.
string Member::getPhone() const
{
	return phone;
}
// Description: Returns member's email.
string Member::getEmail() const
{	
	return email;
}
// Description: Returns member's credit card.
string Member::getCreditCard() const
{
	return creditCard;
}

// Description: Sets the member's name.
void Member::setName(const string aName)
{
	name = aName;
	return;
}

// Description: Sets the member's email.
void Member::setEmail(const string anEmail)
{
	email = anEmail;
	return;
}
// Description: Sets the member's credit card number.
void Member::setCreditCard(const string aCreditCard)
{
	creditCard = aCreditCard;
	return;
}



// Overloaded Operators
// Description: Comparison operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if both Member objects have the same cell phone number.
bool Member::operator == (const Member & rhs) {

    return this->phone == rhs.getPhone();
}
	
// Description: Greater than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is > the 
//              cell phone number of "rhs" Member object.
bool Member::operator > (const Member & rhs) {

    return this->phone > rhs.getPhone();
} 

// Description: Less than operator. Compares "this" Member object with "rhs" Member object.
//              Returns true if the cell phone number of "this" Member object is < the 
//              cell phone number of "rhs" Member object.
bool Member::operator < (const Member & rhs) {
	
    return this->phone < rhs.getPhone();
} 

// For testing purposes!
// Description: Prints the content of "this".
// Example: Louis Pace, 604-853-1423, louis@nowhere.com, 1234 5678 9098 7654 
ostream & operator<<(ostream & os, const Member & p) {
	
    os << p.name << ", " << p.phone << ", " << p.email << ", " << p.creditCard << endl;  
	     
    return os;
} 

// end of Member.cpp

