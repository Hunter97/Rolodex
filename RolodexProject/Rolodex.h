// Specification file for class Rolodex
// The Rolodex class mimics the operation of a Rolodex.  The class makes use of a multimap STL container class to generate a
// list of Rolodex cards made up of Card objects (from class Card).  The STL multimap inserts data as a pair, a key and a value
// and returns an iterator to the data.  The list is sorted alphabetically by key when data is added to the multimap.   
// The multimap also allows for the insertion of duplicate keys. These methods, plus several others, allow the class Rolodex to 
// mimic the operation of an actual Rolodex.  
// The Rolodex class maintains a collection of Card objects with the STL multimap.  The class Card provides data that makes up an 
// a Rolodex card.  The key for each Roldex card is the Card object's last name data member.  Just like a real Rolodex, each
// card is indexed by the contacts last name.  
// The value data for each Rolodex card is the Card object itself.  The Card object data members include a persons contact information.
// Having the entire Card object as the value, simulates an actual Rolodex card, that would contain a persons name, address, occupation,
// and telephone number.  All the individual string data and card formatting (for displaying a Card) is located within the class Card.  
// The class Rolodex simply provides the methods to navigate the Rolodex once all the Card members are added.  The Rolodex's
// cards can be accessed as a entire list and displayed to the user, or individually (if needed).  The Rolodex class allows a client to  
// create methods that can add, modify, search, flip, get, remove, and show each Card object contained within the Rolodex. 


#ifndef ROLODEX_H
#define ROLODEX_H
#include "Card.h"
#include <iostream>
#include <map>
#include <iterator>
#include <string>
using std::multimap;
using std::iterator;
using std::string;
using std::pair;
using std::ostream;
using std::allocator;
using std::less;

// Define names for multimap and multimap iterator
typedef multimap< string, Card, less<string> > rolodexCards;
typedef multimap< string, Card >::iterator rolodexIterator;


class Rolodex
{

public:
	Rolodex (){}
	~Rolodex(){}
	void addCard( Card &cTemp );		// Inserts a Card object into multimap
	
	Card getCard();						// Returns an iterator that points to current card in Rolodex
	void removeCard();					// Removes the current card from Rolodex
	Card flipCard();					// Flips to the next card in Rolodex
	bool searchCard( string & );		// Searches Rolodex for a last name or closest match
	void showRolodex( ostream & );		// Displays data members of Card obj
	int getSize();						// Returns the size of the Rolodex
	
private:
	rolodexCards m_myRolodex;			// Rolodex multimap object
	rolodexIterator m_iActiveCard;		// Iterator the points to current card in Rolodex
	void shuffleRolodex( string & );	// Sorts common last names by first name
};


#endif