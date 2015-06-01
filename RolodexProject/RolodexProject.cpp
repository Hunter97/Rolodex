// Driver program for the class Rolodex.  This driver programs provides interactive commands to call functions that perform methods
// indicated by their name.  List, for example, calls the Rolodex show member function to list the entire contents of the 
// Rolodex.  The driver program tests all methods provided by the class Rolodex.

#include "Rolodex.h"
#include "Card.h"
#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <algorithm>	
#include <sstream>
using std::cout;
using std::endl;
using std::string;
using std::cin;
using std::getline;
using std::left;
using std::right;
using std::setw;
using std::stringstream;

#define add ( addCurrentCard( myRolodex ) )			// Calls addCurrentCard function
#define list ( listRolodex( myRolodex ) )			// Calls listRolodex function
#define remove ( removeCurrentCard( myRolodex ) )	// Calls removeCurrentCard function
#define view ( viewCurrentCard( myRolodex ) )		// Calls viewCurrentCard function
#define flip ( flipCurrentCard( myRolodex ) )		// Calls flipCurrentCard function
#define search ( searchRolodexCards( myRolodex ) )	// Calls searchRolodexCards function
#define modify ( modifyCurrentCard( myRolodex ) )	// Calls modifyCurrentCard function

void displayHeader( ostream & );				// Displays header for card
void listRolodex( Rolodex & );					// Displays Rolodex from beginning to end
void viewCurrentCard( Rolodex & );				// Displays the current card in Rolodex
void flipCurrentCard( Rolodex & );				// Flips current card to next card
void searchRolodexCards( Rolodex & );			// Search Rolodex for card
bool removeCurrentCard( Rolodex & );			// Removes the current card from Rolodex
void addCurrentCard( Rolodex & );				// Adds a new card to rolodex
void modifyCurrentCard( Rolodex & );			// Modifies current card in Rolodex
int getCardInformation( Card &, string & );		// Gets card information from Card class
string getUserInput( bool & );					// Change to getUserInput
int getMenuInput();								// Change to getMenuInput
bool getResponse();								// Gets yes/no response from user


int _tmain( int argc, _TCHAR* argv[] )
{
	Rolodex myRolodex;	// Rolodex object
	Card cMyCard;		// Card object
	int iter = 0;
	
	add;		// Load stored Rolodex data
	list;		// Entire current Rolodex
	search;		// Search Rolodex
	modify;		// Modify an Card
	view;		// View current Card
	search;		// Search Rolodex
	modify;		// Modify a Card
	view;		// View current card
	flip;		// Flip current Card with next Card
	list;		// Entire Rolodex

	// Flip until Joh Smyth is displayed
	do
	{
		flip;
		cMyCard = myRolodex.getCard();

	} while (cMyCard.getLastName() != "Smyth" && ++iter != myRolodex.getSize());
	
	remove;		// Remove Jon Smyth, which is current card
	view;		// View current card, should be Coors

	add;		// Matthew Williams, teacher, 69 Main St. Acton, MA. 555-9330
	view;		// View current card, should be Williams
	flip;		// Should flip to Coors
	remove;		// Remove Adolf Coors,  which is current card
	view;		// View current card should be Griffen

	add;		// Jim Butler, contractor, 33 Cedar Lane, Concord, MA, 555-8535
	view;		// Current Card, should be Butler
	
	// Flip until Alan Lupine is displayed
	iter = 0;
	do
	{
		flip;
		cMyCard = myRolodex.getCard();

	} while (cMyCard.getLastName() != "Lupine" && ++iter != myRolodex.getSize());

	modify;		// Alan Lupine - change address and phone number
	
	// Flip until Jewel Proverb is displayed
	iter = 0;
	do
	{
		flip;
		cMyCard = myRolodex.getCard();

	} while (cMyCard.getLastName() != "Proverb" && ++iter != myRolodex.getSize());

	remove;		// Remove Jewel Proverb
	view;		// View current card should be Revere

	// Flip until Jim Butler is displayed
	iter = 0;
	do
	{
		flip;
		cMyCard = myRolodex.getCard();

	} while ( cMyCard.getLastName() != "Butler" && ++iter != myRolodex.getSize() );

	add;		// Another Jim Butler, Consultant, 22 Minuteman St, Lexington, MA. 555-4422
	add;		// Dan Butler, Chauffeur, 68 Willow St, Westford, MA, 555-8493 (should sort before the Jim Butler cards)

	list;		// List entire Rolodex 
	
	system ( "pause" );		// Pause program

	return 0;
}


//****************************************************************************
// Definition of function displayHeader 								     *
// Accepts an ostream object as an argument.  The argument is used to insert *
// the header fields of a Rolodex Card to the console. Each field is left    *
// justified.																 *
//****************************************************************************

void displayHeader( ostream &output ) 
{
	// Display the fields of a Rolodex Card in columns with set widths
	output << left << setw(13) << "First:" << output.fill(' ') << setw(5) << left << setw(15) << "Last:" 
		<< right << output.fill(' ') << setw(5) << left << setw(25) << "Occupation:"
		<< right << output.fill(' ') << setw(5) << left << setw(50) << "Address:"  
		<< right << output.fill(' ') << setw(5) << "Phone:" << endl;

} // End displayHeader function


//****************************************************************************
// Definition of function listRolodex    								     *
// Accepts a refernce to a Rolodex object as an argument.  Calls Rolodex     *
// showRolodex function to display the contents of the Rolodex, from the     *
// beginning to to the end.                                                  *
//****************************************************************************

void listRolodex( Rolodex &cMyRolodex )
{
	cout << "List cards:\n";
	displayHeader( cout );				// Display Card header
	cMyRolodex.showRolodex( cout );		// Display Card objects in Rolodex
	cout << endl;

} // End listRolodex function


//****************************************************************************
// Definition of function viewCurrentCard 					                 *
// Accepts a reference to a Rolodex object as an argument. Calls Rolodex     *
// getCard function to get a copy of the active Rolodex Card. Then calls     *
// Card showCard function to display the Card.                               *
//****************************************************************************

void viewCurrentCard( Rolodex &cMyRolodex )
{
	Card cMyCard;						// Instantiate a temp Card object
	cMyCard = cMyRolodex.getCard();		// Get the active Card; set to temp Card obj
	cout << "View Current Card:\n";			
	displayHeader( cout );				// Display Card header
	cMyCard.showCard( cout );			// Display the active Card
	cout << endl;

} // End viewCurrentCard


//****************************************************************************
// Definition of function flipCurrentCard 						             *
// Accepts a reference to a Rolodex object as an argument. Calls Rolodex     *
// flipCard function to get a copy of the next Card within the Rolodex. Then *
// calls Card showCard function to displays the Card.                        *
//****************************************************************************

void flipCurrentCard( Rolodex &cMyRolodex )
{
	Card cMyCard;						// Instantiate a temp Card object
	cout << "Flip Card:\n";					
	cMyCard = cMyRolodex.flipCard();	// Get the next Card; set to temp Card obj
	displayHeader( cout );				// Display Card header
	cMyCard.showCard( cout );			// Display next Card in Rolodex
	cout << endl;

} // End flipCurrentCard


//****************************************************************************
// Definition of function searchRolodexCards             					 *
// Accepts a reference to a Rolodex object as an argument. Prompts user for  *
// a last name (or part of a last name) to search within Rolodex.  Calls     *
// Rolodex searchCard function to find a matching Card or next Card          *
// alphabetically in Rolodex.  The Rolodex Card (or next closest match) is   *
// displayed by calling viewCurrentCard.  The user is prompted if no match   *
// is found.                                                                 *
//****************************************************************************

void searchRolodexCards( Rolodex &cMyRolodex )
{
	bool bCardFound;						// Search flag 
	string::iterator iLocateFirstChar;		// String iterator, for case conversion
	string sName;							// Holds search string

	// Dispaly search criteria to user
	cout << "Search Cards:\n";
	cout << "Search for a card by last name or by a partial string of letters contained in the last name.\n";
	cout << "Search will display the card or the next card in list if name is not found.\n";
	cout << "Enter the last name (or letter) to search: ";

	cin >> sName;		// Get string to search
	 
	// Transform 1st char in user input to uppercase
	iLocateFirstChar = sName.begin();										// Set iterator to point to string container
	++iLocateFirstChar;														// Increment ptr to 2nd char, sets range to transform case
	transform ( sName.begin(), sName.end(), sName.begin(), tolower );		// Transform string to lowercase
	transform ( sName.begin(), iLocateFirstChar, sName.begin(), toupper );	// Transform case of 1st char to uppercase
	cout << endl;

	// Display the Rolodex Card if a match is found, otherwise inform user of no match
	( bCardFound = cMyRolodex.searchCard( sName ) )	 ?	viewCurrentCard( cMyRolodex ) : cout << "Card not found and no other cards exists that is alphabetically higher in the list.\n";

	cout << endl;
	cin.ignore();	// Clear keyboard buffer
	cin.clear();	// Clear cin flags

} // End searchRolodexCards


//****************************************************************************
// Definition of function removeCurrentCard function						 *
// Accepts a reference to a Rolodex object as an argument. Calls             *
// viewCurrentCard to display the active Card and prompts the user to erase  *
// the Card from the Rolodex.  The function then calls Rolodex removeCard()  *
// to remove the Card. The function returns the bool, bRmoved, as True if    *
// Card was removed; as false if Card was not removed.                       *
//****************************************************************************

bool removeCurrentCard( Rolodex &cMyRolodex )
{
	bool bRemoved = false;		// Remove flag

	// Get & display the active Card
	cout << "Remove Card:\n";
	viewCurrentCard( cMyRolodex );	

	// Prompt user to remove or keep Card
	cout << "\nSelect Yes to remove this card from list; No to cancel: ";

	// Get yes/no response from user; if yes, remove Card from Rolodex
	if ( getResponse() )			
	{	
		cMyRolodex.removeCard();									// Remove Card from Rolodex
		cout << "The card has been removed from Rolodex.\n\n";		// Inform user Card was removed
		bRemoved = true;											// Set bRemoved to true
	}
	else // If no, don't remove Card
	{
		cout << "The card was not removed from Rolodex.\n\n";		// Inform user Card was not removed
		bRemoved = false;											// Set bRemoved to false
	}

	return bRemoved;	// Returns removed or !removed

} // End removeCurrentCard


//****************************************************************************
// Definition of function addCurrentCard 							         *
// Accepts a reference to a Rolodex object as an argument.  Instantiates a   *
// new Card obj and calls getCardInformation to get/set the data for the     *
// new Card.  The Card is then added to the Rolodex by calling Rolodex       * 
// addCard.                                                                  *
//****************************************************************************

void addCurrentCard( Rolodex &cMyRolodex )
{
	static int nCounter = 0, nLoopCntr = 0;		// Holds internal/external loop counters
	bool bValidEntry = true, bContinue = true;	// Flags that indicate valid string entry and user is done entering data
	string sAddInfo = "Add";					// Holds Function label, passed into getCardInformation						

	// First addCurrentCard call from main; instantiates a group of Cards and adds the group of Cards to Rolodex (simulating a data file)
	if ( nCounter == 0 )
	{
		cMyRolodex.addCard ( Card ("Tony", "Hansen", "Writer", "12 E. St. NY, NY 33333", "555-9999" ) );
		cMyRolodex.addCard ( Card ( "Jon", "Smyth", "Computer Hardware", "CMU Computer Services Pittsburgh, PA", "555-1324") );
		cMyRolodex.addCard ( Card ( "Alonza", "Heard", "Mechanic", "123 Anyplace Ave Malden, MA", "555-5678" ) );
		cMyRolodex.addCard ( Card ( "Jen", "Reyes", "Graphic artist", "325 Oak Rd Wilmington, MA", "555-4950" ) );
		cMyRolodex.addCard ( Card ( "Alan", "Lupine", "Vet", "1 Bigelow Ave. Lawrence, MA", "555-7654" ) );
		cMyRolodex.addCard ( Card ( "Jewel", "Proverb", "Landscaper", "34 Washington St. Waltham, MA", "555-3333" ) );
		cMyRolodex.addCard ( Card ( "Paul", "Revere", "Radical Revolutionary", "45 Commonwealth Ave. Boston, MA", "555-1776" ) );
		cMyRolodex.addCard ( Card ( "Adolf", "Coors", "Beer Manufacturer", "Boston MA", "555-2337" ) );
		cMyRolodex.addCard ( Card ( "Seymour", "Papert", "Lego Professor", "MIT", "555-1111" ) );
		cMyRolodex.addCard ( Card ( "Fred", "Milton", "Sales", "12 Freedom Way Nashua, NH", "555-9981" ) );
	}

	// Second (or higher) addCurrentCard call from main; instantiates a single Card, displays AddCard menu, 
	// user enters data and Card is added to Rolodex
	if ( nCounter > 0 )
	{	
		// Prompt user and provide conditions about adding data
		cout << "Add Card:\n";
		cout << "A first name and last name are required, for other fields, enter none or not available\n";
		cout << "if this information is unknown.\n\n"; 

		// Instantiate a Card obj
		// Call getCardInformation to display menu & to set/get data for Card obj
		// When done is selected, verify all fields contain valid string data (not empty)
		// If data is valid, add Card to Rolodex by calling Rolodex addCard
		// Continue until user data is valid or user cancels routine
		do
		{
			Card cMyCard;												// Instantiate a Card object
			bValidEntry = true;											// User data is valid until proven invalid
			nLoopCntr = getCardInformation( cMyCard, sAddInfo );		// Dispalay menu & get/set card data from user

			// User is done entering data, check menu selection, and add Card to Rolodex 
			// Exit if cancel was selected or if done was first choice 
			if ( nLoopCntr > 1 )							
			{												
				cout << endl;								

				// Test each data field against an empty string
				// If empty (invalid), prompt user and set bValidEntry flag to false
				if ( cMyCard.getFirstName() == " " )		// Test first name
				{											
					cout << "No first name entered.\n";		
					bValidEntry = false;					
				}											
				if ( cMyCard.getLastName() == " " )			// Test last name
				{										
					cout << "No Last name entered.\n";		
					bValidEntry = false;
				}
				if ( cMyCard.getOccupation() == " " )		// Test occupation	
				{
					cout << "No occupation entered.\n";		
					bValidEntry = false;
				}
				if ( cMyCard.getAddress() == " " )			// Test address
				{
					cout << "No address entered.\n";		
					bValidEntry = false;
				}
				if ( cMyCard.getPhoneNumber() == " " )		// Test phone number
				{
					cout << "No phone number entered.\n";	
					bValidEntry = false;
				}
				
				// Add Card data to Rolodex if all data fields are valid
				if ( bValidEntry )
				{
					// Add Card to Rolodex; use string data stored into temp Card obj
					cMyRolodex.addCard( Card ( cMyCard.getFirstName(), cMyCard.getLastName(), cMyCard.getOccupation(), 
					cMyCard.getAddress(), cMyCard.getPhoneNumber() ) );
					cout << "\nThe card has been entered into the Rolodex\n\n";		// Prompt user Card was added to Rolodex
				}
				else // Found an empty data field, prompt user and ask if should continue
				{	
					cout << "The card is missing information; select yes & re-enter information or no to cancel entry; ";
					bContinue = getResponse();		// Get the users Yes/No response

					// Exit function if "no" and prompt user 
					if ( !bContinue )				
						cout << "The card entry was cancelled, no information was entered into list.\n";
					else // Continue function if "yes" (returns to beginning of loop)
						nLoopCntr = 0;	// Reset loop counter
				} 
			}
			else // User chose cancel (or done as first choice), exit function and prompt user
			{		
				cout << "\nAdd card was cancelled, no information was entered into list.\n";
				bContinue = false;		// Do not continue
			}	

		} while ( bContinue && !bValidEntry );		// Start over; data was invalid & user decided to continue
	}												 
													
	cout << endl;									
	++nCounter;		// Keep track of addCurrentCard calls from main

} // End addCurrentCard function


//****************************************************************************
// Definition of function modifyCurrentCard         						 *
// Accepts a reference to a Rolodex object as an argument.  Calls            *
// viewCurrentCard to get a copy of the active Card.  Instantiates a temp    *
// Card obj and stores copy of active Card into this Card obj. The getCard-  *
// Information function is called to prompt the user to modify the active    *
// Card.  The modified values are saved to the temp Card.  When complete,    * 
// the active Card is erased from the Rolodex and the temp Card is added to  *
// Rolodex and set as the active Card.                                       *
//****************************************************************************

void modifyCurrentCard( Rolodex &cMyRolodex )
{
	int nLoopCntr = 0;				// Loop counter
	bool bCardErased = false;		// Remove Card flag
	string sModInfo = "Modify";		// Holds menu identifyer

	// Prompt user to modify Card data
	cout << "Modify Card:\n";
	cout << "Update the information for the card below:\n";

	viewCurrentCard( cMyRolodex );	// View the active Card (Card to be modified)

	Card cMyCard = cMyRolodex.getCard();	// Get active Card

	// Call getCardInformation to dispalay menu & get/set changes to Card, return when done or cancelled
	nLoopCntr = getCardInformation( cMyCard, sModInfo );

	// Call removeCurrentCard, if done was not 1st menu choice
	if ( nLoopCntr > 1 )			
	{
		cout << "\nBefore updating, the original card needs to be removed.\n";	// Prompt user to remove active Card
		bCardErased = removeCurrentCard( cMyRolodex );							// Remove active Card, set erased flag
	}

	// Add temp Card to Rolodex, if active Card was removed
	if ( bCardErased )
	{
		cMyRolodex.addCard( Card ( cMyCard.getFirstName(), cMyCard.getLastName(), cMyCard.getOccupation(), 
		cMyCard.getAddress(), cMyCard.getPhoneNumber() ) );
		cout << "The original card has been updated with the new information\n";  // Prompt user modifications were added
	}
	else // User chose not to remove active card; modifications not added; prompt user
		cout << "\nExiting without making changes to the card\n";

	cout << endl;

} // End modifyCurrentCard function


//****************************************************************************
// Definition of function getCardInformation						         *
// Accepts a reference to a Card object and a reference to a string object   *
// as arguments. Prompts the user for data and stores the data into the Card *
// object.  The string argument identifies the purpose, to add or to modify, *
// the Card object.  An int is returned which indicates the user is done or  * 
// has cancelled.                                                            *
//****************************************************************************

int getCardInformation( Card &cMyCard, string &sMenuType )
{
	int nMenuNumber = 0, nEntered = 0, nLoopCntr = 0;	// Loop & menu counters
	bool bNotDone = true, bToUpper = true;				// Done/Cancelled flag, case flag
	string	sToModify;									// Holds string entered by user

	// Display the menu to the user.  
	// Display Card data members; based on menu selection & if called from modifyCurrentCard
	// Get the data from the user, display entry/ask for confirmation, and set Card obj data
	// Continue to get/set data for Card obj until user is done or has cancelled process.
	do
	{
		// Display menu list, sMenuType identifies add or modify
		cout << "Select from the list below to " << sMenuType << " a card\n";	
		cout << "1. " << sMenuType << " First Name\n";
		cout << "2. " << sMenuType << " Last Name\n";
		cout << "3. " << sMenuType << " Occupation\n";
		cout << "4. " << sMenuType << " Address\n";
		cout << "5. " << sMenuType << " Phone Number\n";
		cout << "6. Done\n";
		cout << "7. Cancel changes\n";

		nMenuNumber = getMenuInput();	// Get menu selection

		// Set data members within Card obj, which member to set depends on menu selection
		switch( nMenuNumber )
		{
			case 1	:	// Set first name within Card object
						if ( sMenuType == "Modify" )			// Display Card data if called from modifyCurrentCard
							cout << "\nThis field contains: " << cMyCard.getFirstName() << endl;
						bToUpper = true;						// Flag to set 1st char to uppercase
						sToModify = getUserInput( bToUpper );	// Get data from user, set first character to uppercase
						cMyCard.setFirstName( sToModify );		// Set first name inside Card object	
						break;									// The following cases use same logic
							
			case 2	:	// Set last name within Card object
						if ( sMenuType == "Modify" )
							cout << "\nThis field contains: " << cMyCard.getLastName() << endl;
						bToUpper = true;
						sToModify = getUserInput( bToUpper );
						cMyCard.setLastName( sToModify );
						break;

			case 3	:	// Set occupation within Card object
						if ( sMenuType == "Modify" )
							cout << "\nThis field contains: " << cMyCard.getOccupation() << endl;
						bToUpper = true;
						sToModify = getUserInput( bToUpper );
						cMyCard.setOccupation( sToModify );
						break;

			case 4	:	// Set address within Card object
						if ( sMenuType == "Modify" )
							cout << "\nThis field contains: " << cMyCard.getAddress() << endl;
						bToUpper = false;						// Do not convert case
						sToModify = getUserInput( bToUpper );	// Get data from user, do not set case
						cMyCard.setAddress( sToModify );
						break;

			case 5	:	// Set phone number within Card object
						if ( sMenuType == "Modify" )
							 cout << "\nThis field contains: " << cMyCard.getPhoneNumber() << endl;
						bToUpper = false;
						sToModify = getUserInput( bToUpper );
						cMyCard.setPhoneNumber( sToModify );
						break;

			case 6 :	// Set bNotDone flag to false when done is selected
						bNotDone = false;
						break;

			case 7 :	// Set bNotDone flag to false when cancelled is selected
						nLoopCntr = -1;			// Reset loop cntr inside addCurrentCard
						bNotDone = false;
						break;

			default:	// Some unknown & unexpected condition occured, will cause loop to cancel
						cout << "A problem occured with data entry, the function will exit\n";
						nLoopCntr = -1;
						bNotDone = false;
						break;
		} // End switch

		++nLoopCntr;	// Loop counter

	} while ( bNotDone );	// Continue until user selects done or cancel from menu

	return nLoopCntr;		// Return done or cancel

} // End getCardInformation function


//****************************************************************************
// Definition of function getUserInput function							     *
// Accepts a reference to a bool as an argument.  Prompts user to enter      *
// string data.  Validates the user did not enter an empty string.  Sets the *
// case of the 1st char to uppercase; except address string. Displays string *
// to user and prompts if correct.  If correct, the user input is returned.  * 
//****************************************************************************

string getUserInput( bool &bToUpper )
{
	string sGetData;		// Holds input from user
	bool bResponse;			// Response flag, yes = true
	
	// Prompt user to enter the string data
	cout << "\nPlease enter the new information for the card: ";

	// Get user input data, validate string is not empty, set 1st char to uppercase,
	// display string back to user, promt if correct, & get response.
	// Do again if data is was not entered correctly (answers no).
	do
	{
		cin.clear();					// Clear cin flags
		getline( cin, sGetData );		// Get data

		// Validate string, if empty, promt for data, continue ask/get until valid
		while ( sGetData == "" )
		{
			cout << "Invalid entry, please re-enter.\n";
			cin.clear();
			getline( cin, sGetData );
		}

		// Set 1st char in string to uppercase (except address data)
		if ( bToUpper )
		{
			string::iterator iLocateFirstChar;												// Iterator to point to string container
			iLocateFirstChar = sGetData.begin();											// Set iterator to point to string container
			++iLocateFirstChar;																// Increment to 2nd char
			transform ( sGetData.begin(), sGetData.end(), sGetData.begin(), tolower );		// Transform string to lowercase
			transform ( sGetData.begin(), iLocateFirstChar, sGetData.begin(), toupper );	// Transform 1st char to uppercase
		}

		cout << "\nYou entered: " << sGetData  << endl;					// Display string to user
		cout << "If correct, enter Yes, if incorrect enter No: ";		// Ask if data was entered correctly
		bResponse = getResponse();										// Get/validate user response

		// If data was not entered correctly, request to re-enter data
		if ( !bResponse )
			cout << "Please re-enter changes: "; 

	} while ( !bResponse );		// Continue prompt/get data until entry is correct

	return sGetData;	// Return data entry when correct

} // End getUserInput


//*******************************************************************
//	Definition of function validateInput.							*
//	This function gets the users menu input and verifies the input 	*
//	is within the range of 1 thru 7. If outside this range, the		*
//	user is asked to enter number again.  If valid, the function	*
//	returns the users input.										*
//*******************************************************************

int getMenuInput()
{
	string sResponse;		// Holds use input
	int nEntry = 0;			// Holds menu selection

	// Get user input as a string, convert to int, validate to be within menu range (1 to 7)
	// Continue until the response is valid (between 1 & 7)
	while ( nEntry < 1 || nEntry > 7 ) 
	{
		cin.clear();							// Clear cin flags
		getline( cin, sResponse );				// Get response from user
		stringstream myStream( sResponse );		// Instantiate a stringstream; set to user response

		if ( myStream >> nEntry )				// Convert string to int and test
		{
			if ( nEntry > 0 && nEntry < 8 )		// Valid entry is within range
				break;							// Escape while loop; string is within range
		}
		cout << "Invalid input, please try again: ";
	}

	return nEntry;	// Return menu selection

} // End validateInput


//****************************************************************************
// Definition of function geResponse   					                     *
// Gets a Yes/No response from user.  Validates the response by comparing    *
// the string input to string "yes" and "no".  If neither, user is prompted  *
// to re-enter response.  If valid, the functoin returns true for yes and    *
// false for no.                                                             * 
//****************************************************************************

bool getResponse()
{
	string sResponse;		// Holds users response
	bool bValid = true;		// Response flag; true = yes

	// Get user input, validate string is yes or no, set valid flag depending on response
	// Do again if response is invalid
	do
	{
		cin.clear();				// Clear cin flags
		getline( cin, sResponse );	// Get Resposne
		transform ( sResponse.begin(), sResponse.end(), sResponse.begin(), tolower );	// Transform string to lowercase

		if ( sResponse.compare( "yes" ) == 0 )		// Set bValid to true if "yes"
			bValid = true;
		else if ( sResponse.compare( "no" ) == 0 )	// break if "no"; set bValid to false
		{
			bValid = false;
			break;	// Escape do/while loop; valid response
		}
		else // Invalid response, promt to re-enter and set bValid flag to false
		{
			bValid = false;
			cout << "Invalid response; please enter Yes or No: ";
		}

	} while ( !bValid );		// Continue unitl response is valid

	cout << endl;

	return bValid;	// Return response

} // End getResponse
