/*************************************************************
* Author:		Chelsea Christison
* Filename:		PE1 - cStringMenu.cpp
* Date Created:	1.27.2017
* Modifications:	1.27.2017 - created shell of program 
*  	2.1.2017 - added first five functions of menu*			   
*	2.2.2017 - added the last six functions. Format
*			   the output to look nicer
*	2.3.2017 - added in header comments, and function comments.
*			   also reformatted Menu's case statment to call 
*			   respective functions, rather than perform cstring 
*			   functions in case block. 
*	2.3.2017 - redid above due to TFS error, and rewrote all 
*			   commenting and program modifications. 
*
* Lab/Assignment: Chapter 12 Programming Exercise 
*
* Overview:
*	This program manipulates cstrings based on a menu. User
*	selects menu option, and is able to input a cstring to 
*	manipulate based on the menu option selected: 
*
*			 1. Get a string
*			 2. Copy a string
*			 3. Concatinate two strings
*			 4. Find length of a string 
*			 5. Find a substring in a string
*			 6. Reverse a string 
*			 7. Compare two strings 
*			 8. Delete part of a string
*			 9. Add a string into a string 
*			10. Create a substring out of a string
*			11.	Find the index of a substring in a string 
*			12. Exit program 
*
* Input:
*	The input will consist of a maximim of two strings, and 
*	ocassionally, for some menu options, user will enter 
*	numbers. 
*
* Output:
*	The output of this program will the result of the 
*	cstring manipulation, based on the menu option selected
*	Example of selection of Copy a string: 
*
*		Enter String 1: hello world
*
*		Copying "hello world" into string 2
*
*		String 2: hello world
*
************************************************************/
#define _CRTDBG_MAP_ALLOC

#include<iostream>
using std::cout;
using std::cin; 
using std::endl; 

#include<iomanip>
using std::setw;
using std::left;

#include<crtdbg.h>

//cString menu
void Menu(); 
void CaseGetString(char * cStr1);
void CaseStringLength(char * cStr1); 
void CaseStringCopy(char * cStr1, char * cStr2); 
void CaseStringCatination(char * cStr1, char * cStr2, char * cReturn); 
void CaseStringString(char * cStr1, char * cStr2, char * cReturn); 
void CaseStringReverse(char * cStr1, char * cReturn); 
void CaseStringCompare(char * cStr1, char * cStr2); 
void CaseStringDelete(char * cStr1, char * cStr2, char * cReturn); 
void CaseStringAdd(char * cStr1, char * cStr2, char * cReturn); 
void CaseSubString(char * cStr1); 
void CaseSubStringIndex(char * cStr1, char * cStr2); 

//cString functions
char * cStrGet(); 
int	cStrLen(const char * cStr); 
char * cStrCpy(char * dest, const char * src);
char * cStrCat(char * dest, const char * src); 
char * cStrStr(char * str, const char * sub); 
char * cStrRev(char * str); 
int cStricmp(const char * s1, const char * s2); 
char * cStrDelete(char * str, int start, int count); 
char * cStrAdd(char * str, char * add, int start); 
char * cSubStr(char * str, int start, int count); 
int cSubIndex(char * str, char * sub); 

//displays
void Refresh(int lines); 

//consts
const int BUFF_MAX(60);
const int SCRN(25);
const int MENU(10);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Menu(); 

	return 0; 
}

/**********************************************************************
* Purpose: This function displays a menu and directs the user input 
*	to respective functions. 
*
* Precondition:
*   no inputs
*
* Postcondition:
*   modifies cStr1, cStr2 and cReturn depending on what menu option 
*	was chosen 
*
************************************************************************/
void Menu()
{
	int in(0);

	cout << "Welcome to the cString Menu:" << endl;
	do
	{
		cout << setw(30) << left << "Menu:" << endl
		 	<< setw(20) << left << " 1. cStrGet"	<< setw(30) << left << "Input a string and output to console" << endl
			<< setw(20) << left << " 2. cStrCpy"	<< setw(30) << left << "Get a copy of a string" << endl
			<< setw(20) << left << " 3. cStrCat"	<< setw(30) << left << "Concatinate a string onto another" << endl
			<< setw(20) << left << " 4. cStrLen"	<< setw(30) << left << "Get the length of a string" << endl
			<< setw(20) << left << " 5. cStrStr"	<< setw(30) << left << "Get where a string starts in another string" << endl
			<< setw(20) << left << " 6. cStrRev"	<< setw(30) << left << "Reverse a string" << endl
			<< setw(20) << left << " 7. cStriCmp"	<< setw(30) << left << "Compare two strings" << endl
			<< setw(20) << left << " 8. cStrDelete" << setw(30) << left << "Delete a portion of a string" << endl
			<< setw(20) << left << " 9. cStrInsert" << setw(30) << left << "Insert a string into a string" << endl
			<< setw(20) << left << "10. cSubStr"	<< setw(30) << left << "Get a string from another string" << endl
			<< setw(20) << left << "11. cSubIndex"	<< setw(30) << left << "Get the index where a string begins inside another string" << endl
			<< setw(20) << left << "12. EXIT";

		Refresh(MENU);
		cout << "Please enter a menu option: ";
		cin >> in;
		cin.clear();
		//handle errors - stay in this loop until 
		//correct input is received
		if (in < 1 || in > 12 )
		{
			do
			{
				cout << "Please enter correct input.\n";
				cin >> in;

			} while (in < 1 || in > 12 );
		}

		//max of three char *s used in entire program 
		char * cStr1 = 0;
		char * cStr2 = 0;
		char * cReturn = 0; 

		switch (in)
		{
			case 1:	//get
			{
				CaseGetString(cStr1); 
				break; 
			}
			case 2:	//copy
			{
				CaseStringCopy(cStr1, cStr2); 
				break;
			}
			case 3:	//cat
			{
				CaseStringCatination(cStr1, cStr2, cReturn); 
				break;
			}
			case 4:	//length
			{
				CaseStringLength(cStr1); 
				break;
			}
			case 5:	//substr
			{
				CaseStringString(cStr1, cStr2, cReturn); 
				break;
			}
			case 6:	//reverse
			{
				CaseStringReverse(cStr1, cReturn); 
				break;
			}
			case 7:	//compare
			{
				CaseStringCompare(cStr1, cStr2); 
				break;
			}
			case 8:	//delete
			{
				CaseStringDelete(cStr1, cStr2, cReturn); 
				break;
			}
			case 9:	//insert
			{
				CaseStringAdd(cStr1, cStr2, cReturn); 
				break;
			}
			case 10: //substr
			{
				CaseSubString(cStr1); 
				break;
			}
			case 11: //index of substr 
			{
				CaseSubStringIndex(cStr1, cStr2); 
				break;
			}
			case 12: //exit
			{
				cout << "Exiting the Program!" << endl; 
				system("pause"); 
				break;
			}
			default:
				break;
		}
	} while (in != 12);
}

/**********************************************************************
* Purpose: This function calls cStrGet(), handles prompts to the user 
*	and frees memory allocated by cStrGet();
*
* Precondition:
*     cStr1  -    must be null 
*
* Postcondition:
*     modifies cStr1 to have the userinput from console
*
************************************************************************/
void CaseGetString(char * cStr1)
{
	Refresh(SCRN);
	cout << "Enter a string: ";
	cStr1 = cStrGet();

	cout << "You entered '"
		 << cStr1 << "' " << endl;

	delete[] cStr1;

	system("Pause");
	cout << endl;
}

/**********************************************************************
* Purpose: This function calls cStrLen(), handles prompts to the user,
*	and frees memory. 
*
* Precondition:
*     cStr1  -  must be null 
*
* Postcondition:
*      Modifies cStr1
*
************************************************************************/
void CaseStringLength(char * cStr1)
{
	Refresh(SCRN);
	int length(0);
	cout << "Let's find the length of this string: ";
	cStr1 = cStrGet();

	length = cStrLen(cStr1);
	cout << "\nLength: " << length << endl;

	delete[] cStr1;

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cStrCpy(), handles prompts to the user
*	allocates and frees memory where applicable. 
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null 
*
* Postcondition:
*    Modifies cStr2
*
************************************************************************/
void CaseStringCopy(char * cStr1, char * cStr2)
{
	Refresh(SCRN);
	cout << "Enter String 1: ";
	cStr1 = cStrGet();

	cout << "\nCopying "<< cStr1 << " into string 2" << endl;

	cStr2 = new char[cStrLen(cStr1) + 1];
	cStr2 = cStrCpy(cStr2, cStr1);

	cout << "String 2: " << cStr2 << endl;

	delete[] cStr1;
	delete[] cStr2;

	system("Pause");
	cout << endl;
}

/**********************************************************************
* Purpose: This function calls cStrCat(), handles prompts to the user,
*	and frees memory where applicable 
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null
*	cReturn  -  must be null 
*
* Postcondition:
*    Modifies cReturn 
*
************************************************************************/
void CaseStringCatination(char * cStr1, char * cStr2, char * cReturn)
{
	Refresh(SCRN);
	cout << "Let's concat two strings!\nEnter string 1: ";
	cStr1 = cStrGet();
	cout << "\nstring 2: ";
	cStr2 = cStrGet();

	cReturn = cStrCat(cStr1, cStr2);	//return is cstr1, and was deleted in here
	cout << "\nConcatinated string: " << cReturn << endl;

	delete[] cStr2;
	delete[] cReturn; 

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cStrStr(), handles prompts to the user, 
*	handles return to find all instances of the string, and frees 
*	memory where applicable. 
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null
*	cReturn  -  must be null 
*
* Postcondition:
*    Modifies cReturn
*
************************************************************************/
void CaseStringString(char * cStr1, char * cStr2, char * cReturn)
{
	Refresh(SCRN);
	cout << "Let's find a string in a string\n"
		<< "String: ";
	cStr1 = cStrGet();

	cout << "\nString to locate: ";
	cStr2 = cStrGet();

	

	cout << "\nLocating substring..." << endl;

	if (cStrStr(cStr1, cStr2) == nullptr)
		cout << cStr2 << " not found\n" << endl;
	else
	{
		cReturn = cStr1;
		while (cReturn = cStrStr(cReturn, cStr2))
		{
			cout << "Found '" << cStr2 << "' starting at '"
				<< cReturn << "'\n";
			cReturn++;
		}
	}

	delete[] cStr1;
	delete[] cStr2;
	delete[] cReturn; 

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cStrRev(), handles prompts to the user, 
*	and frees memory where applicable 
*
* Precondition:
*   cStr1  -  must be null
*	cReturn  -  must be null
*
* Postcondition:
*    Modifies cReturn
*
************************************************************************/
void CaseStringReverse(char * cStr1, char * cReturn)
{
	Refresh(SCRN);
	cout << "Let's reverse this string: ";
	cStr1 = cStrGet();

	cReturn = cStrRev(cStr1);
	cout << "\nReversed: " << cReturn << endl;

	delete[] cStr1;
	delete[] cReturn;

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cStriCmp(), handles prompts to the 
*	user, interprets the return value from cStriCmp(), and frees 
*	memory where applicable 
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null
*
* Postcondition:
*    Interprets the return value of cStriCmp()
*
************************************************************************/
void CaseStringCompare(char * cStr1, char * cStr2)
{
	Refresh(SCRN);
	cout << "Let's compare strings\nString 1: ";
	cStr1 = cStrGet();
	cout << "\nString 2: ";
	cStr2 = cStrGet();

	if (cStricmp(cStr1, cStr2) < 0)
	{
		cout << "'" << cStr1 << "' comes before '"
			<< cStr2 << "'" << endl;
	}
	else if (cStricmp(cStr1, cStr2) > 0)
	{
		cout << "'" << cStr2 << "' goes before '"
			<< cStr1 << "'" << endl;
	}
	else
	{
		cout << "'" << cStr1 << "' is the same as '"
			<< cStr2 << "'" << endl;
	}

	delete[] cStr1;
	delete[] cStr2;

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cStrDelete(), handles prompts to the 
*	user, handles nullptr return, and frees memory where applicable
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null
*	cReturn - must be null
*
* Postcondition:
*    Modifies cReturn
*
************************************************************************/
void CaseStringDelete(char * cStr1, char * cStr2, char * cReturn)
{
	int s(0);	//start
	int c(0);	//count

	Refresh(SCRN);
	cout << "Let's delete a portion of this string: ";
	cStr1 = cStrGet();

	cout << "\nStart deleting at position (number): ";
	cin >> s;

	cout << "\nHow many characters to delete: ";
	cin >> c;

	cReturn = cStrDelete(cStr1, s, c);

	if (cReturn != nullptr)
	{
		cout << "\nAfter deleting: " << cReturn << endl;
		delete[] cReturn;
	}
	
	delete[] cStr1;

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cStrAdd(), handles prompts to the user,
*	handles nullptr return, and frees memory where applicable 
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null
*   cReturn  -  must be null
*
* Postcondition:
*    Modifies cReturn
*
************************************************************************/
void CaseStringAdd(char * cStr1, char * cStr2, char * cReturn)
{
	int s(0);	//start

	Refresh(SCRN);
	cout << "Let's insert a string into this one: ";
	cStr1 = cStrGet();

	cout << "\nString to insert: ";
	cStr2 = cStrGet();

	cout << "\nBegin insert at position (number): ";
	cin >> s;

	cReturn = cStrAdd(cStr1, cStr2, s);

	if (cReturn != nullptr)
		cout << "After insert: " << cReturn << endl;

	delete[] cStr1;
	delete[] cStr2;
	delete[] cReturn;

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cSubStr(), handles prompts to the user, 
*	and frees memory where applicable 
*
* Precondition:
*   cStr1  -  must be null
*	cReturn  -  must be null
*
* Postcondition:
*    Modifies cReturn
*
************************************************************************/
void CaseSubString(char * cStr1)
{
	int s(0);	//start
	int c(0);	//count

	Refresh(SCRN);
	cout << "Let's create a substring out of this string: ";
	cStr1 = cStrGet();

	cout << "\nStart substring at: ";
	cin >> s;

	cout << "\nHow many characters is substring: ";
	cin >> c;

	cStr1 = cSubStr(cStr1, s, c);
	cout << "Substring: " << cStr1 << endl;

	delete[] cStr1;

	system("pause");
}

/**********************************************************************
* Purpose: This function calls cSubIndex(), handles prompts to the 
*	user, handles return value interpretation, and frees memory where 
*	applicable
*
* Precondition:
*   cStr1  -  must be null
*	cStr2  -  must be null
*
* Postcondition:
*   Output if string was found, and where. or if not found - that it 
*	wasnt found
*
************************************************************************/
void CaseSubStringIndex(char * cStr1, char * cStr2)
{
	int i(0);	//index 
	cout << "Let me find the index of a substring in this string: ";
	cStr1 = cStrGet();

	cout << "\nSubstring to find: ";
	cStr2 = cStrGet();

	i = cSubIndex(cStr1, cStr2);

	if (i > 0)
	{
		cout << "'" << cStr2 << "' was found in '"
			<< cStr1 << "' at index " << i << endl;
	}
	else
	{
		cout << "'" << cStr2 << "' was NOT found in '"
			<< cStr1 << "'" << endl;
	}

	delete[] cStr1;
	delete[] cStr2;

	system("pause");
}

/**********************************************************************
* Purpose: This function gets userinput from console, and returns the 
*	input 
*
* Stipulations: 
*	Function assumes caller has prompted user for input 
*	Caller must delete allocated memory
*
* Precondition:
*   Can be called at any time
*
* Postcondition:
*    Modifies cStr, and returns
*
************************************************************************/
char * cStrGet()
{
	char * cStr = 0; 
	char buffer[BUFF_MAX] = { '\0' };

	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFF_MAX);
	cin.clear();
	cout << endl;

	cStr = new char[cStrLen(buffer) + 1];	//memleak - delete where appropriate 
	cStrCpy(cStr, buffer);

	return cStr; 
}

/**********************************************************************
* Purpose: This function finds the length of the cstring passed 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*
* Precondition:
*   cStr  -  user defined cstring, not null
*
* Postcondition:
*    returns the count of characters in cStr
*
************************************************************************/
int cStrLen(const char * cStr)
{
	int count(0);

	while (*cStr != '\0')
	{
		count++;
		cStr++; 
	}
	return count;
}

/**********************************************************************
* Purpose: This function takes user input cstring, and copies it into 
*	a separate char pointer variable 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Function assumes memory was allocated for dest cstring 
*
* Precondition:
*   dest  -  must be null
*	src  -  user defined cstring, can't be null - CAN be empty ""
*
* Postcondition:
*    Modifies dest and returns it 
*
************************************************************************/
char * cStrCpy(char * dest, const char * src)
{
	for (int i(0); i < (cStrLen(src) + 1); i++)
	{
		*(dest + i) = *(src + i);
	}
	
	return dest; 
}

/**********************************************************************
* Purpose: This function takes user input cstrings and concatinates 
*	the second cstring to the first cstring. 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Caller must free memory allocated
*
* Precondition:
*   dest  -  user defined, can't be null 
*	src  -  user defined, can't be null - CAN be empty ""
*
* Postcondition:
*    Modifies dest and returns it
*
************************************************************************/
char * cStrCat(char * dest, const char * src)
{
	char buff[BUFF_MAX] = { '\0' };
	int index(0);
	int total(0);

	index = cStrLen(dest);				//if strlen didn't count null, +1
	total = cStrLen(dest) + cStrLen(src) + 1;

	cStrCpy(buff, dest);

	//copy after index, the second cstring
	for (int i(0); index < total; i++, index++)
	{
		buff[index] = *(src + i); 
	}

	delete[] dest;
	
	dest = new char[cStrLen(buff) + 1];	//need to delete
	cStrCpy(dest, buff); 
	src = nullptr; 

	return dest;
}

/**********************************************************************
* Purpose: This function takes user input cstrings, and searches the 
*	first cstring for the existance of the second cstring. Returns 
*	a pointer to where the second cstring is found inside the first. 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*
* Precondition:
*   cstr  - user defined, can't be null
*	sub -  user defined, cstring to search for, can't be null 
*
* Postcondition:
*    Modifies a copy of cstr, and returns the address it points to 
*	Will return nullptr if string input is nullptr, or if sub cstring 
*	wasn't found 
*
************************************************************************/
char * cStrStr(char * cstr, const char * sub)
{
	if (cstr == nullptr || sub == nullptr)
		return nullptr; 

	char * str = cstr; 

	while (*str)
	{
		const char * strloop = str;
		const char * subloop = sub;

		//increment while they're equal and not null 
		while (*strloop && *subloop && (*strloop == *subloop))
		{
			strloop++;
			subloop++;
		}
		//if sub is at null, return str - where it starts 
		if (*subloop == '\0')
			return str; 
			
		str++; 
	}

	return nullptr; 
}

/**********************************************************************
* Purpose: This function takes user input and reverses the given 
*	cstring. 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Caller must free memory allocated
*
* Precondition:
*   str  -  user defined, can't be null
*
* Postcondition:
*    Returns rev, the reversed cstring 
*
************************************************************************/
char * cStrRev(char * str)
{
	char * rev = new char[cStrLen(str) + 1];
	int strlength = cStrLen(str); 
	int end = strlength - 1;
	int index(0); 
	
	//copy into rev, starting at end of str 
	for (; index < strlength; index++, end--)
	{
		*(rev + index) = *(str + end); 
	}

	*(rev + index) = '\0';

	return rev; 
}

/**********************************************************************
* Purpose: This function takes user input cstrings, and compares them 
*	with disregard to case. Returns the difference between the compared
*	ascii values. 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Caller must free memory allocated
*
* Precondition:
*   s1  -  user defined, can't be null - can be empty 
*	s2 -  user defined, can't be null - can be empty 
*
* Postcondition:
*    Returns the difference between ascii values contained in cstrings
*	> 0 if string 1 > string 2
*	< 0 if string 2 > string 1
*	0 if both are equal 
*
************************************************************************/
int cStricmp(const char * s1, const char * s2)
{
	//need to create temp ptrs to manipulate
	char * ts1 = new char[cStrLen(s1) + 1];
	char * ts2 = new char[cStrLen(s2) + 1]; 

	//since manipulating temp ptrs, need these 
	//to be able to delete the memory allocated
	//above. Stores the begnning address of both
	char * del1 = 0;	
	char * del2 = 0; 

	//loops used for for loops below 
	//difference stores ascii difference
	//between the temp ptrs - wherever
	//they point to. 
	int loop1 = cStrLen(s1); 
	int loop2 = cStrLen(s2);
	int difference(0); 

		
	//fist loop to make temp s1 have lowercase s1 
	for (int i(0); i < loop1; i++)
	{
		char c = *(s1 + i);

		if(c < 97)
			c += 32;
		//c = tolower(c);
		*(ts1 + i) = c; 
	}
	*(ts1 + loop1) = '\0';
	del1 = ts1;		//store address 

	//second loop to make temp s2 have lowercase s2
	for (int i(0); i < loop2; i++)
	{
		char c = *(s2 + i); 

		if (c < 97)
			c += 32;
		//c = tolower(c); 
		*(ts2 + i) = c;
	}
	*(ts2 + loop2) = '\0';
	del2 = ts2;		//store address 

	//while ts1 isn't null, and they're equal
	//traverse until they aren't. This leaves 
	//them pointing to different chars
	//otherwise both will be pointing to null
	while (*ts1 && *ts1 == *ts2)
	{
		ts1++;
		ts2++;
	}

	//if pointing to different chars, int will
	//hold a negative or positive value.
	//if both are pointing to null, they were the
	//same string, int will be 0;
	difference = *ts1 - *ts2; 
	delete[] del1; 
	delete[] del2; 
	
	return difference;
}

/**********************************************************************
* Purpose: This function takes user input cstring, and deletes a portion
*	based on the user defined start position, and number of characters.
*	Returns the chunked cstring 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Caller must free memory allocated
*
* Precondition:
*   str  -  user defined, can't be null, or less than 1 char
*	start  -  user defined, needs to be greater than -1
*	count  -  user defined, greater than 0
*
* Postcondition:
*    Returns nStr, str after the deletion 
*
************************************************************************/
char * cStrDelete(char * str, int start, int count)
{
	//handle wrong inputs 
	if (cStrLen(str) < 1)
	{
		cout << "Your string is empty!" << endl; 
		return nullptr; 
	}

	int nStrCount = cStrLen(str) - count;		
	char * nStr = new char[nStrCount + 1];	//will need to delete 
	int nIndex(0);	//new string index
	int sIndex(0);	//passed string index 

	//copy into new cstring, up to start 
	for (int i(0); i < start; i++)
	{
		*(nStr + nIndex) = *(str + sIndex);
		nIndex++; 
		sIndex++; 
	}
	sIndex += count; 

	//copy into new cstring, after count
	while (*(str + sIndex))
	{
		*(nStr + nIndex) = *(str + sIndex); 
		nIndex++; 
		sIndex++; 
	}
	*(nStr + nIndex) = '\0';
		
	return nStr; 
}

/**********************************************************************
* Purpose: This function takes user input cstrings, and adds the  
*	additional cstring to the first cstring at the user defined 
*	position. Returns the modified cString.  Handles case where user 
*	tried to add after null. 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Caller must free memory allocated
*
* Precondition:
*   str  -  user defined, can't be null, or less than 1 char
*	add  -  user defined, can't be null, or less than 1 char
*	start  -  user defined, greater than 0
*
* Postcondition:
*    Returns nStr, str after the addition
*	can return nullptr if Start begins past null 
*
************************************************************************/
char * cStrAdd(char * str, char * add, int start)
{
	if (start > cStrLen(str) - 1)
	{
		cout << "How about use cStrCat to append"
			<< " to the end of '" << str
			<< "'?" << endl; 
		return nullptr; 
	}

	int nStrCount = cStrLen(str) + cStrLen(add); 
	char * nStr = new char[nStrCount + 1]; 
	int nIndex(0); 
	int sIndex(0); 

	//copies into new cstring, the beginning of str
	for (int i(0); i <= start; i++)
	{
		*(nStr + nIndex) = *(str + sIndex); 
		nIndex++; 
		sIndex++; 
	}
	
	//copy the additional cstring
	while (*add)
	{
		*(nStr + nIndex) = *add;
		nIndex++;
		add++;
	}

	//copy the rest of str into the new cstring 
	while (*(str + sIndex))
	{
		*(nStr + nIndex) = *(str + sIndex); 
		nIndex++; 
		sIndex++; 
	}
	*(nStr + nIndex) = '\0';

	return nStr; 
}

/**********************************************************************
* Purpose: This function takes user input cstring, and modifies it 
*	to create a substring. Substring is created at user defined 
*	start position, for x amount of characters.
*
* Stipulations:
*	Function assumes caller has prompted user for input
*	Caller must free memory allocated
*
* Precondition:
*   str  -  user defined, can't be null, or less than 1 char
*	start  -  user defined, greater tha -1
*	count  -  user defined, greater than -1
*
* Postcondition:
*    Returns modified str
*
************************************************************************/
char * cSubStr(char * str, int start, int count)
{
	//char * sub = new char[count + 1];	//will need to delete 
	char buff[BUFF_MAX] = { '\0' };

	int sIndex(0); 

	for (int i(0); i < count; i++)
	{
		buff[sIndex] = *(str + start); 
		sIndex++; 
		start++; 
	}
	buff[sIndex] = '\0';

	delete[] str; 
	str = new char[cStrLen(buff) + 1]; 
	cStrCpy(str, buff); 
	
	return str;
}

/**********************************************************************
* Purpose: This function takes user input cstrings, and searches 
*	first cstring for the second cstring. if found, returns the index 
*	where subcstring is in the first cstring 
*
* Stipulations:
*	Function assumes caller has prompted user for input
*
* Precondition:
*   str  -  user defined, can't be null, or less than 1 char
*	sub  -  user defined, can't be null, or less than 1 char
*
* Postcondition:
*    Returns stIn, can return -1 if either cstrings are null
*
************************************************************************/
int cSubIndex(char * str, char * sub)
{
	int stIn(0); 
	int suIn(0); 

	if (*str == '\0' || *sub == '\0')
		return -1; 

	//while str isn't null 
	while (*(str + stIn))
	{
		suIn = 0;
		//increment while both are equal
		while (*(str + stIn) == *(sub + suIn))
		{
			stIn++;
			suIn++;
		}
		if (*(sub + suIn) == '\0')
		{
			int index = cStrLen(str) - suIn ;
			return --index; //cStrLen counts null, so -1
		}

		stIn++;
	}

	return 0;
}

/**********************************************************************
* Purpose: This function outputs newline for the given linecount 
*
* Precondition:
*   lines  -  user defined, positive number only 
*
* Postcondition:
*    outputs to console, new lines and a following endl to "refresh" 
*	the look of the console for easier readability and usability of 
*	the cString Menu.
*
************************************************************************/
void Refresh(int lines)
{
	for (int i(0); i < lines; i++)
	{
		cout << '\n';
	}
	cout << endl; 
}