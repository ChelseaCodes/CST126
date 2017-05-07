/*************************************************************
* Author:		Chelsea Christison
* Filename:		card.cpp
* Date Created:	2/23/2017
* Modifications: 
*	3.3 - overloaded binary operators. not working
*	3.6 - fixed binary ++ operator overloads. Signature needed
*		  to be added to .h, outside of class definition
*	3.8 - card class now displays itself using ASCII, rather 
*		  than main doing the display. 
*		  
**************************************************************/
#include "card.h"

Card::Card(): m_rank(ACE), m_suit(SPADES)
{}
 
Card::Card(Rank rank, Suit suit): m_rank(rank), m_suit(suit)
{}

void Card::Display() const
{
	const char * ranktext[] = { "Ace", "Deuce", "Trey", "Four", "Five",
		"Six", "Seven", "Eight", "Nine", "Ten",
		"Jack", "Queen", "King" };
	const char * suittext[] = { "Spades","Hearts","Clubs","Diamonds" };

	cout << ranktext[m_rank - 1] << " OF " << suittext[m_suit] << endl; 
}

/**********************************************************************
* Purpose: This function handles the printing and formatting of cards
*	to the console. Will print red text on black background for cards
*	with suit Spades or Clubs, and prints black text on red background
*	for cards with suit Hearts or Diamonds. Also prints the ASCII suit
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     X	-	 x coordinate position for printing ASCII card art to console
*     Y	-	 y coordinate position for printing ASCII card art to console
*
* Postcondition:
*      changes the X and Y coordinates for placing the console print
*      cursor where the next card should be printed.
*
************************************************************************/
void Card::PrintCard(int& X, int& Y)
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD cursor;

	//begin at X, Y
	cursor.X = X;
	cursor.Y = Y++;
	SetConsoleCursorPosition(output, cursor);

	//Hearts and Diamonds will be printed black text on red background
	if (m_suit == Card::HEARTS || m_suit == Card::DIAMONDS)
		SetConsoleTextAttribute(output, 192);
	//Spades and Clubs will be red text on black background 
	else
		SetConsoleTextAttribute(output, 12);

	//print the top of the card 
	PrintTop();

	//move cursor
	SetCursor(output, cursor, X, Y++);

	//print first m_rank
	PrintFirstRank();

	//move cursor
	SetCursor(output, cursor, X, Y++);

	//print first fill
	for (int i(0); i < 3; i++)
	{
		PrintFill();
		SetCursor(output, cursor, X, Y++);
	}
	//print suit
	PrintSuit();

	//move cursor
	SetCursor(output, cursor, X, Y++);

	//print second fill
	for (int i(0); i < 3; i++)
	{
		PrintFill();
		SetCursor(output, cursor, X, Y++);
	}

	//print second m_rank
	PrintSecondRank();

	//move cursor
	SetCursor(output, cursor, X, Y++);

	//print bottom
	PrintBottom();

	//reset output 
	SetConsoleTextAttribute(output, 15);
}

void Card::SetRank(Rank r)
{
	m_rank = r; 
}

void Card::SetSuit(Suit s)
{
	m_suit = s;
}

Card::Rank Card::GetRank() const
{
	return m_rank;
}

Card::Suit Card::GetSuit() const
{
	return m_suit;
}

Card::~Card()
{
}

/**********************************************************************
* Purpose: This function sets the cursor for console using the X and Y
*	values passed.
*
* Stipulations:
*	  Caller must specify X and Y values on where to set the position
*
* Precondition:
*     X	 - x coord. on console
*     Y	 - y coord. on console
*
* Postcondition:
*     sets cursor to position passed
*
************************************************************************/
void Card::SetCursor(HANDLE hStdout, COORD cursor, int X, int Y)
{
	cursor.X = X;
	cursor.Y = Y;
	SetConsoleCursorPosition(hStdout, cursor);
}

/**********************************************************************
* Purpose: This function prints the top portion of the ASCII card
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      output to console
*
************************************************************************/
void Card::PrintTop()
{
	char topLeftCorner = static_cast<char>(201);
	char topRightCorner = static_cast<char>(187);
	char horizontal = static_cast<char>(205);

	cout << topLeftCorner;

	for (int i = 0; i < 11; i++)
		cout << horizontal;

	cout << topRightCorner;
}

/**********************************************************************
* Purpose: This function prints the rank at the top of the ASCII card,
*	and prints a J, Q or K instead of 11, 12 or 13.
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      output to console
*
************************************************************************/
void Card::PrintFirstRank()
{
	char vertical = static_cast<char>(186);
	char letter = '\0';
	if (m_rank > 10)
	{
		switch (m_rank)
		{
		case JACK:
		{
			letter = 'J';
			break;
		}
		case QUEEN:
		{
			letter = 'Q';
			break;
		}
		case KING:
		{
			letter = 'K';
			break;
		}
		default:;
		}

		cout << vertical << setw(11) << setfill('.') << left << letter
			<< vertical;
	}
	else
	{
		cout << vertical << setw(11) << setfill('.') << left << m_rank
			<< vertical;
	}

	//resets the console output 
	cout << right;
}

/**********************************************************************
* Purpose: This function prints the filler portion of the ASCII card,
*	adding length
*
* Stipulations:
*	prints only one line. Caller must use a loop to print add length
*	to ASCII card
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      output to console
*
************************************************************************/
void Card::PrintFill()
{
	char vertical = static_cast<char>(186);
	cout << vertical << setw(12) << vertical;
}

/**********************************************************************
* Purpose: This function prints the suit int the middle of the
*	ASCII card, using the ASCII characters
*
* Stipulations:
*	  If user is on Windows 10, must configure console settings to use
*	  Legacy characters to see the suits.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      output to console
*
************************************************************************/
void Card::PrintSuit()
{
	char vertical = static_cast<char>(186);

	cout << vertical << setw(6) << setfill('.')
		<< static_cast<char>(m_suit) << setw(6) << vertical;
}

/**********************************************************************
* Purpose: This function prints the rank at the bottom right of the
*	ASCII card, translating ranks to J, Q, or K when applicable
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      output to console
*
************************************************************************/
void Card::PrintSecondRank()
{
	char vertical = static_cast<char>(186);
	char letter = '\0';

	if (m_rank > 10)
	{
		switch (m_rank)
		{
		case JACK:
		{
			letter = 'J';
			break;
		}
		case QUEEN:
		{
			letter = 'Q';
			break;
		}
		case KING:
		{
			letter = 'K';
			break;
		}
		default:;
		}

		cout << vertical << setw(11) << setfill('.')
			<< letter << vertical;
	}
	else
	{
		cout << vertical << setw(11) << setfill('.')
			<< m_rank << vertical;
	}
}

/**********************************************************************
* Purpose: This function prints the bottom portion of the ASCII card
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     no preconditions
*
* Postcondition:
*      output to console
*
************************************************************************/
void Card::PrintBottom()
{
	char bottomLeftCorner = static_cast<char>(200);
	char bottomRightCorner = static_cast<char>(188);
	char horizontal = static_cast<char>(205);

	cout << bottomLeftCorner;

	for (int i = 0; i < 11; i++)
		cout << horizontal;

	cout << bottomRightCorner;
}

/**********************************************************************
* Purpose: This function overloads the binary "++" Suit enumerator 
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     rs - suit to be post incremented 
*
* Postcondition:
*      increments rs, but returns the old value first(post increment)
*
************************************************************************/
Card::Suit operator++(Card::Suit& rs, int)
{
	Card::Suit old = rs;
	rs = Card::Suit(rs + 1);
	return old;
}

/**********************************************************************
* Purpose: This function overloads the binary "++" Rank enumerator
*
* Stipulations:
*	  No stipulations.
*
* Precondition:
*     rs - rank to be post incremented 
*
* Postcondition:
*      increments rs, but returns the old value first(post increment)
*
************************************************************************/
Card::Rank operator++(Card::Rank& rs, int)
{
	Card::Rank old = rs;
	rs = Card::Rank(rs + 1);
	return old;
}