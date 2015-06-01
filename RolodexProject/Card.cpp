// Implimentation file for class Card

#include "Card.h"


//****************************************************************************
// Default Constructor initializes private member variables to an empty      *
// string.                                                                   *
//****************************************************************************

 Card::Card()
	: m_sFirstName( " " ), m_sLastName( " " ), m_sOccupation( " " ), 
	  m_sAddress( " " ), m_sPhoneNumber( " " )
{
	// Empty 
}


//****************************************************************************
// Constructor initializes private member variables.                         *
//****************************************************************************

 Card::Card( const  string &rFirstName, const  string &rLastName, const string &rOccupation, 
			const string &rAddress, const string &rphoneNumber )
	: m_sFirstName( rFirstName ), m_sLastName( rLastName ), m_sOccupation( rOccupation ), 
	  m_sAddress( rAddress ), m_sPhoneNumber( rphoneNumber )
{
	// Empty 
}


//****************************************************************************
// Definition of function setFirstName 					                     *
// Recieves a reference to a string as an argument.  Stores the string into  *
// the data member m_sFirstName.                                             *
//****************************************************************************
 
 void Card::setFirstName( string &sFirstName ) 
 { m_sFirstName = sFirstName; }


//****************************************************************************
// Definition of Card member function setLastName 			                 *
// Recieves a reference to a string as an argument.  Stores the string into  *
// the data member m_sLastName.                                              *
//****************************************************************************

 void Card::setLastName( string &sLastName )
 { m_sLastName = sLastName; }


//****************************************************************************
// Definition of Card member function setOccupation					         *
// Recieves a reference to a string as an argument.  Stores the string into  *
// the data member m_sOccupation.                                            *
//****************************************************************************

 void Card::setOccupation( string &sOccupation )
 { m_sOccupation = sOccupation; }


//****************************************************************************
// Definition of Card member function setAddress 					         *
// Recieves a reference to a string as an argument.  Stores the string into  *
// the data member m_sAddress.                                               *
//****************************************************************************

 void Card::setAddress( string &sAddress )
 { m_sAddress = sAddress; }


//****************************************************************************
// Definition of Card member function setPhoneNumber                         *
// Recieves a reference to a string as an argument.  Stores the string into  *
// the data member m_sPhoneNumber.                                           *
//****************************************************************************

 void Card::setPhoneNumber( string &sPhoneNumber )
 { m_sPhoneNumber = sPhoneNumber; }


//****************************************************************************
// Definition of Card member function getFirstName 					         *
// Returns the data member m_sFirstName.                                     *
//****************************************************************************

string Card::getFirstName() const
{ return m_sFirstName; }


//****************************************************************************
// Definition of Card member function getLastName 					         *
// Returns the data member m_sLastName.                                      *
//****************************************************************************

string Card::getLastName() const
{ return m_sLastName; }


//****************************************************************************
// Definition of Card member function getOccupation					         *
// Returns the data member m_sOccupation.                                    *
//****************************************************************************

string Card::getOccupation() const
{ return m_sOccupation; }


//****************************************************************************
// Definition of Card member function getAddress					         *
// Returns the data member m_sAddress.                                       *
//****************************************************************************

string Card::getAddress() const
{ return m_sAddress; }


//****************************************************************************
// Definition of Card member function getPhoneNumber				         *
// Returns the data member m_sPhoneNumber.                                   *
//****************************************************************************

string Card::getPhoneNumber() const
{ return m_sPhoneNumber; }


//****************************************************************************
// Definition of Card member function showCard					             *
// Dispalys the data members in columns.                                     *
//****************************************************************************

void Card::showCard( ostream &output ) const
{

	output << left << setw(13) << m_sFirstName << right << output.fill(' ') << setw(5) << left << setw(15) << m_sLastName 
		   << right << output.fill(' ') << setw(5) << left << setw(25) << m_sOccupation
		   << right << output.fill(' ') << setw(5) << left << setw(50) << m_sAddress 
		   << right << output.fill(' ') << setw(5) << left << setw(8) << m_sPhoneNumber << endl;
}



