/*************************************************************
* Author:		Chelsea Christison
* Filename:		main.cpp
* Date Created:	2.23.2017
* Modifications: 3.6 - Added in formatting for console
*
* Lab/Assignment: PE 15.13.02 - Deck of Cards
*
* Overview:
*	This program tests the Deck and Card class by displaying
*	all cards in the shuffled deck. as well as an option 
*	to display a card one by one until the end of the deck is
*	reached. 
*	
* Input:
*	Input from console for menu option chosen 
*	
*	===========  Chelsea's House of Cards ========= 
	1. Print whole deck
	2. Print one card (Press 'Enter' to display a card)
*
* Output:
*	The output of this program will be results from either 
*	option chosen above. Either the whole deck or one card
*	at a time in a 4 x 13 format until all 52 cards are 
*	displayed. Cards are formatted according to suit: 
*	Diamond and Hearts are red background with black font
*	Spade and Clubs are black background with red font
*
************************************************************/
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>  
#include <windows.h>
#include <iostream>
using std::cout;
using std::endl;
using std::cin; 

#include <iomanip>
using std::setfill;
using std::setw;
using std::left; 

#include "deck.h"

//functions 
int DisplayMenu();							//menu for output
void ProcessChoice(int user_input);			//process menu choice 
void PrintAllCards();						//Prints all 52 cards
void PrintOneAtATime();						//Prints one at a time, uses Enter to print 

//Global consts
const int COLUMNS(4);	//4 cards across
const int ROWS(12);		//12 rows long 

int main()
{  
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char again;			//used to do action again

	do
	{
		int user_choice = DisplayMenu(); 

		ProcessChoice(user_choice);

		cout << "\nReshuffle? (y/n)";
		cin >> again;

	} while (again == 'y' || again == 'Y');

	return 0;
}

/**********************************************************************
* Purpose: This function displays the menu for the user to display
*	entire deck or display one card at a time.
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions, called from main
*
* Postcondition:
*      returns the user_input
*
************************************************************************/
int DisplayMenu()
{
	int user_input(0);	//used for menu
	
	cout << "===========  Chelsea's House of Cards =========\n" << endl; 
	cout << "1. Print whole deck\n"
		<< "2. Print one card (Press 'Enter' to display a card)\n" << endl;
	cin >> user_input;

	return user_input; 	
}

/**********************************************************************
* Purpose: This function displays the menu for the user to display
*	entire deck or display one card at a time.
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions, called from main
*
* Postcondition:
*      calls PrintAllCards() or PrintOneAtATime() depending on input
*
************************************************************************/
void ProcessChoice(int user_input)
{
	switch (user_input)
	{
		case 1:
			PrintAllCards();
			break;
		case 2:
			PrintOneAtATime();
			break;
		default:;
	}
}

/**********************************************************************
* Purpose: This function prints entire shuffled deck to the console
*	using special formatting to have ASCII cards print. Clears the 
*	console screen before printing all cards
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      Cards output to console, option to reshuffle and select option
*      from menu. 
*
************************************************************************/
void PrintAllCards()
{
	Deck deck;		//create deck
	Card dealt;		//card dealt from deck
	int row(5);		//cursor position
	int X(4);		//cursor position
	int Y(0);		//cursor position
	system("cls");	//clear the screen 

	cout << "Whole Deck" << endl; 
	//Prints 4 x 13 
	for (int i(0); i < ROWS + 1; i++)
	{
		for (int j(0); j < COLUMNS; j++)
		{
			Y = row;
			dealt = deck.Deal();
			dealt.PrintCard(X, Y);
			X += 16;
		}
		row += 14;
		X = 4;
	}
}

/**********************************************************************
* Purpose: This function prints a card to the console
*	using special formatting to have ASCII cards print. Clears the
*	console screen before printing all cards. 
*
* Stipulations:
*	User should press enter to have the next card in the deck show 
*	up on console.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      Cards output to console, option to reshuffle and select option
*      from menu.
*
************************************************************************/
void PrintOneAtATime()
{
	Deck deck;		//create deck
	Card dealt;		//card dealt from deck
	int row(5);		//cursor position
	int X(4);		//cursor position
	int Y(0);		//cursor position
	system("cls");	//clear the screen 

	cout << "Press Enter to display a card" << endl;
	for (int i(0); i < ROWS + 1; i++)
	{
		for (int j(0); j < COLUMNS; j++)
		{
			cin.get();	//waits for the user to press enter
			Y = row;
			dealt = deck.Deal();
			dealt.PrintCard(X, Y);
			X += 16;
		}
		row += 14;
		X = 4;
	}
}