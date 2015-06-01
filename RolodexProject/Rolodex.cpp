// Implimentation file for class Rolodex

#include "Card.h"
#include "Rolodex.h"


//****************************************************************************
// Definition of Rolodex member function addCard			                 *
// Recieves a reference to a Card obj as an argument. Saves the Card obj's   *
// last name as the key.  Then inserts the key and the Card obj into the     *
// Rolodex (in alphabetical order by key) and sets the data member           *
// m_iActiveCard to point to this card, which is now the active card in the  *
// list.  The function then calls shuffleRolodex private member function to  *
//  search for common last names and re-sort these cards by first name.      *
//****************************************************************************

void Rolodex::addCard( Card &cMyCard )
{
	string sLastName = cMyCard.getLastName();    // Rolodex key; holds Card obj's last name 

	// Insert key and Card obj (value) into next location in Rolodex.  Set m_iActiveCard to point to its location
	m_iActiveCard = m_myRolodex.insert( pair< string, Card >( sLastName, cMyCard ) );	

	// Call shuffleRolodex to check for multiple keys & then sort these entries by first name
	shuffleRolodex( sLastName );

} // End Roldex::addCard


//****************************************************************************
// Definition of Rolodex private member function shuffleRolodex		         *
// Recieves a reference to a string (the active key) as an argument.  The    *
// function loops through each entry in Rolodex and compares each key to the *
// active key.  If a matching key is found, the first name in the active     *
// Card and the first name of matching Card are compared.  If first name in  *
// active Card is alphabetically lower, then the matching Card is erased     *
// from the Rolodex and re-inserted after the active Card.  This continues 	 *
// until all Cards with matching keys are checked against the active Card.   *
//****************************************************************************

void Rolodex::shuffleRolodex( string &sLastName )
{
	rolodexIterator iLowerLimit, iTemp, iAllCards;	// Iterators to point to Rolodex Cards

	iAllCards = m_myRolodex.begin();				// Set iterator to beginning of multimap

	// Check each key in Rolodex to active key
	// If a match is found, compare the first names in Card obj's against each other
	// If first name of active card is lower than matching card, erase the matching
	// card from list and re-insert the card after the active card.
	// Continue this way until all cards are checked and all matches are tested
	while ( iAllCards != m_myRolodex.end() ) 
	{
		iLowerLimit = m_myRolodex.lower_bound( sLastName );		// Check for a match

		// Test first name of match against active Cards first name; erase/re-insert if higher than active Card
		if ( m_iActiveCard->second.getFirstName() < iLowerLimit->second.getFirstName() )  
		{	
			iTemp = iLowerLimit;				// Save iterator of matching Card into a temp location
			string sName = iTemp->first;		// Store key for temp iterator

			Card cTest ( iTemp->second.getFirstName(), iTemp->second.getLastName(), iTemp->second.getOccupation(),  // Save match to a Card
						iTemp->second.getAddress(), iTemp->second.getPhoneNumber() );

			m_myRolodex.erase( iTemp );		// Erase match from Rolodex

			iAllCards = m_myRolodex.insert( pair<string, Card>( sName, cTest) );	// Re-insert matching Card into Rolodex
		}
		else // Keys do not match, increment to next card & check again
			++iAllCards;

	} // Continue until the end of the Rolodex

} // End shuffleRolodex


//****************************************************************************
// Definition of Rolodex member function getCard			                 *
// Returns a copy of the active Card within Rolodex.                         *
//****************************************************************************

Card Rolodex::getCard()
{ return m_iActiveCard->second; }


//****************************************************************************
// Definition of Rolodex member function removeCard			                 *
// Removes the active Card from the Rolodex and increments the data member   *
// iterator (active iterator) to the next Rolodex Card.  This is done by     *
// calling the member function Rolodex flipCard.                             *
//****************************************************************************

void Rolodex::removeCard()
{
	rolodexIterator iCurrentCard = m_iActiveCard;	// Temp itorator, set equal to active iterator

	flipCard();	// Set data member interator to point to next Card in Rolodex

	// Erase the active Card from the list
	m_myRolodex.erase( iCurrentCard );

} // End removeCard


//****************************************************************************
// Definition of Rolodex member function flipCard			                 *
// Increments the data member iterator to point to the next Rolodex Card,    *
// which becomes the active Card.  If the active Card was the last Card in   *
// the Rolodex, the data member iterator is set to point to the beginning of *
// the list.  The new active Card is then returned.                          *
//****************************************************************************

Card Rolodex::flipCard()
{ 
	rolodexIterator iUpLimit;	// Iterator to point to next Rolodex Card

	// Set iterator to point to next Rolodex Card in list
	iUpLimit = m_myRolodex.upper_bound( m_iActiveCard->second.getLastName() );
	
	// If active Card is last Card, set data member iterator to point to beginning of the list, 
	// otherwise increment data member iterator
	iUpLimit == m_myRolodex.end() ? m_iActiveCard = m_myRolodex.begin() : ++m_iActiveCard;

	return m_iActiveCard->second;	// Return active Card

} // End flipCard


//****************************************************************************
// Definition of Rolodex member function searchCard			                 *
// Receives a reference to a string as an argument.  Searches each key in    *
// Rolodex for a match to the argument string.  Or finds next closest match  *
// in the list, alphabetically.  If a match, or next closest, is found, the  *
// data member iterator is set to point to match, which makes the match the  *
// new active Card and returns bMatch as true.  If no matches are found,     *
// returns bMatch as false and no changes are made to data member iterator.  *
//****************************************************************************

bool Rolodex::searchCard( string & sLastName )
{
	rolodexIterator iLowerLimit;	// Iterators to point to previous Rolodex Card
	bool bMatch = true;				// Match flag

	// Search Rolodex for a match to key, set iterator to point to the match
	rolodexIterator iAllCards = m_myRolodex.find( sLastName );	

	// Set data member iterator to point to match, if a match found
	if ( iAllCards != m_myRolodex.end() )
	{
		m_iActiveCard = iAllCards;		// Points to new active Card
		bMatch = true;
	}
	else // Test for next closest match, no exact match found
	{
		iLowerLimit = m_myRolodex.lower_bound( sLastName );		// Check for next closest match (alphabetically) within list

		if ( iLowerLimit != m_myRolodex.end() )					// Set data member iterator to next closest match, if match is found
		{	
			m_iActiveCard = iLowerLimit;	// Points to new active Card
			bMatch = true;
		}
		else // No matches were found
			bMatch = false;		
	}

	return bMatch;  // Return results of bMatch
}


//****************************************************************************
// Definition of Rolodex member function show        		                 *
// Receives an ostream as an argument.  Each Rolodex card in the Rolodex is  *
// displayed; from beginning of the list until end of the list. The class    *
// Card member function, showCard, is called at each iteration, to display   *
// the Card obj's data members.  The ostream argument is passed as a         *
// parameter to the showCard function.                                       *
//****************************************************************************

void Rolodex::showRolodex( ostream &out )
{
	// Display the Rolodex Cards, starting from the begining of the list to the end of the list
	for ( rolodexIterator iAllCards = m_myRolodex.begin(); iAllCards != m_myRolodex.end(); ++iAllCards )
	{
		iAllCards->second.showCard( out );
	}
}

int Rolodex::getSize()
{
	return m_myRolodex.size();
}


