/*************************************************************
* Author:		Chelsea Christison
* Filename:		TPE 12.21.cpp
* Date Created:	01/30/2017
* Modifications:
*************************************************************
*
* Lab/Assignment: Team Programming Exercise 12.21
*
* Overview:
*	 This program creates a dynamic ragged array of
*    strings as determined by the delimiter. For
*    example, the cString "C++: Learn by Doing" will
*    produce an array of four strings if the delimiter
*    is a space.
*
* Input:
*    The pointer that will point to the array of cStrings. By Ref.
*    A pointer to the string to be tokenized. By Val.
*    A character that represents the delimiter. By Val.
*
* Output:
*	 The output of this program will be the data inside the
*	 str_array, or a console statment saying the delimiter
*	 was not found
************************************************************/
#define _CRTDBG_MAP_ALLOC

#include<iostream>
using std::cout;
using std::cin; 
using std::endl;

#include<crtdbg.h>

//function declarations 
char * GetString(); 
char GetDelimiter(); 
int StrToArray(char **& str_array, char * str, char delimiter);
int SearchFor(char * str, char delimiter, int index); 
void AddStr(char **& str_array, char buffer[], int count); 
void Display(char ** str_array, int count);
void FreeMem(char **& str_array, int & count);

const int MAX(25); 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	char ** str_array = 0;	//null pointer array 
	int str_num(0); 

	char * str = GetString();	//get the string from console 

	char delimiter = GetDelimiter();	//get the delimiter 

	str_num = StrToArray(str_array, str, delimiter); 

	delete[] str; 

	if(str_num == 0)
		cout << "delimiter was not found in string" << endl; 
	else
		Display(str_array, str_num);
		

	FreeMem(str_array, str_num); 

	return 0; 
}

/**********************************************************************
* Purpose: This function recieves string input from console 
*
* Precondition:
*     no preconditions, called at beginning of main 
*
* Postcondition:
*     returns the char * input 
************************************************************************/
char * GetString()
{
	char * str = 0; 
	char buffer[MAX] = { '\0' }; 

	cout << "Please enter a string to be tokenized: "; 
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, MAX);
	cin.clear();
	cout << endl;

	str = new char[strlen(buffer) + 1];
	strcpy(str, buffer); 
	//will need to delete this in main 

	return str;
}

/**********************************************************************
* Purpose: This function recieves delimiter char from console 
*
* Precondition:
*     no preconditions, called after getting string 
*
* Postcondition:
*     returns a char with delimiter - even space
************************************************************************/
char GetDelimiter()
{
	char delimiter = '\0'; 

	cout << "Please enter delimiter character: "; 
	delimiter = cin.get();		//.get() allows space to be a delimiter

	return delimiter;
}

/**************************************************************
* Purpose: This function creates a dynamic ragged array of
*          strings as determined by the delimiter. For
*          example, the cString "C++: Learn by Doing" will
*          produce an array of four strings if the delimiter
*          is a space.
*
* Pre-Conditions: The pointer to the array will be null.
*                 The cString will be null terminated.
*                 The delimiter will be a valid character but
*                     is not guaranteed to be in the cString.
*
* Post-Conditions: The pointer to the array will either be a
*                     valid address or null if there were no
*                     instances of the delimiter found.
*                  If there aren’t any instances of the delimiter
*                     found, the function will return 0, otherwise
*                     the number of cStrings in the array.
**************************************************************/
int StrToArray(char **& str_array, char * str, char delimiter)
{
	int str_num(0); 
	int index(0); 
	int str_len = strlen(str); 
	int start(0); //where to start in str for copying 

	char upperdelim = toupper(delimiter); 
	char lowerdelim = tolower(delimiter); 

	bool found(false); 
	bool finalloop(false); //bool to represent if all of str has been combed for delimiter 
	bool done(false); 

	//first call will send in index of 0; 
	index = SearchFor(str, delimiter, index);

	if (index < str_len)
		found = true;

	if (str[index] == '\0')
		done = true;
	
	//loop until done 
	while (done == false)
	{
		//index will be pointing to where delimiter is inside str
		if (found || finalloop)
		{
			char buffer[MAX] = { '\0' };	//will reinstantiate every loop 
			found = false;
			int i(0); 

			while (start < index)	
				buffer[i++] = str[start++];
			
			buffer[i] = '\0';

			//add
			AddStr(str_array, buffer, str_num);	
			//increments
			str_num++; 
			index++;
			start++; 

			//pass index back into search to find next delim
			if (finalloop == false)
				index = SearchFor(str, delimiter, index);
			else
				done = true; //now we are done 
			
			//str is at null - the end of the string
			if (str[index] == '\0')
				finalloop = true;	//one more loop to add rest of string 
			else
				found = true; 
		}
	}

	return str_num;
}

/**********************************************************************
* Purpose: Searches through string to find index of delimiter
*
* Precondition:
*     str	-	contains string to be searched 
*	  delimiter	- contains what to be searching for 
*	  index	-	holds value of last index. first call it will be 0.
*				another call it could be a different number 
*
* Postcondition:
*      Returns index integer of where next delimiter is, or if none found
*			will return the length of the string
************************************************************************/
int SearchFor(char * str, char delimiter, int index)
{
	int str_len = strlen(str);
	char upperdelim = toupper(delimiter);
	char lowerdelim = tolower(delimiter);
	bool found(false);

	 //first look to see if delimiter is in array
	while (index < str_len && found == false)
	{
		//if it's found 
		if (str[index] == lowerdelim || str[index] == upperdelim)
		{
			found = true;
		}
		else
			index++;	//otherwise traverse
	}
	return index;
}

/**********************************************************************
* Purpose: This function adds tokenized strings to str_array 
*
* Precondition:
*     str_array	-	Passed in with or without information inside
*	  buffer[]	-	char array containing tokenized string 
*	  count		-	int representing how many elements there are in array 
*
* Postcondition:
*      modifies the str_array to add another element 
************************************************************************/
void AddStr(char **& str_array, char buffer[], int count)
{
	char ** temp = new char *[count + 1];	//declare temp + 1 
	for (int i(0); i < count; i++)
	{
		temp[i] = str_array[i];	//copy up to new element
	}
	temp[count] = new char[strlen(buffer) + 1];	//add at new element 
	strcpy(temp[count], buffer);

	delete[] str_array;		//delete
	str_array = temp;		//reassign 
}

/**********************************************************************
* Purpose: loops through str_array to display to console
*
* Precondition:
*     str_array	- filled with information 
*	  count		- how many elements there are in str_array
*
* Postcondition:
*      outputs array to console
************************************************************************/
void Display(char ** str_array, int count)
{
	cout << "Tokenized array:\n"; 
	for (int i(0); i < count; i++)
	{
		cout << str_array[i] << endl; 
	}
}

/**********************************************************************
* Purpose: Frees memory in str_array that was allocated in AddStr()
*
* Precondition:
*	  str_array  -	ragged array with memory to be deleted 
*	  count	-	count for how many elements are inside array
*
* Postcondition:
*      modifies both array and resets count.
************************************************************************/
void FreeMem(char **& str_array, int & count)
{
	//loop through array 
	for (int i(0); i < count; ++i)
	{
		delete[] str_array[i];	//free inside data 
	}
	delete[] str_array;	//delete array 
	count = 0;		//reset counter 
}
