// Specification file for class Card
// Holds data for a contact card.  Allows user to initialize all the data members when a Card object
// is instantiated.  The user can set and get the data members after the object is instantiated.  Also
// will display the data memebers in a column format, that is left justified (1 row).

#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
using std::string;
using std::ostream;
using std::setw;
using std::endl;
using std::left;
using std::right;
using std::fill;
     	
class Card 
{ 
	
public:
	Card();
	Card ( const string &, const string &, const string &, const string &, const string &); // ctor
	~Card()	{}

	void setFirstName( string & );		// Set first name
	void setLastName( string & );		// Sets last name
	void setOccupation( string & );		// Sets occupation
	void setAddress( string & );		// Sets address
	void setPhoneNumber( string & );	// Sets phone number
	string getFirstName() const;		// Gets first name
	string getLastName() const;			// Gets last name
	string getAddress()const;			// Gets address
	string getOccupation() const;		// Gets occupation
	string getPhoneNumber() const;		// Gets phone number
	void showCard( ostream & ) const;	// Displays data members
	
private:
	string m_sFirstName;	// Holds first name
	string m_sLastName;		// Holds last name
	string m_sOccupation;	// Holds occupation
	string m_sAddress;		// Holds address
	string m_sPhoneNumber;	// Holds phone number
};

#endif
