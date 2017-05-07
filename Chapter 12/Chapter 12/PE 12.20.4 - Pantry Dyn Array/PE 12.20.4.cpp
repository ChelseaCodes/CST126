/*************************************************************
* Author:		Chelsea Christison
* Filename:		PE 12.20.4.cpp
* Date Created:	01/26/2017
* Modifications:	
*************************************************************
*
* Lab/Assignment: Programming Exercise 12.20.4 
*
* Overview:
*	 This program creates a dynamic ragged array of 
*    strings as determined by the delimiter. For 
*    example, the cString "C++: Learn by Doing" will 
*    produce an array of four strings if the delimiter
*    is a space.
*
* Parameters: 
*	The pointer that will point to the array of cStrings. By Ref.
*   A pointer to the string to be tokenized. By Val.
*   A character that represents the delimiter. By Val.
*
* Output:
*	The output of this program will be the data inside the 
*	str_array, or a console statment saying the delimiter
*	was not found
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include<iostream>
using std::cout;
using std::endl;
using std::cin;

#include<iomanip>
using std::setw;
using std::left; 

#include<fstream>
using std::ofstream;
using std::ifstream;

#include<crtdbg.h>

//Function Declarations SS
void ReadFile(char **& Pantry);
void DisplayMenu(char **& Pantry, char **& Rec, int linecount); 
char * GetInput(); 
void Add(char **& Pantry, char * ing);
bool Search(char ** Pantry, char * target);
void Edit(char **& Pantry, char * target); 
void Remove(char **& Pantry, char * rmv); 
void Save(char ** Pantry); 
void Display(char ** Pantry); 
int ReadRecipe(char **& rec);
char * RecipeParse(char cstr[]); 
void RecAdd(char **& Rec, char * line, int & linecount); 
void RecipeSearch(char ** Pantry, char ** rec, int linecount); 
void FreeMem(char **& array, int & count);

//Globals
int ing_count(0);	//would be passes to every function otherwise
const int MAX(60);  //max char length 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Variables needed
	char ** Pantry = 0;		//Pantry dynamic array
	char ** Rec = 0;		//Recipe dynamic array 
		
	ReadFile(Pantry);							//read in file, and insert 

	int linecount = ReadRecipe(Rec);			//read in Recipe, and insert
	
	DisplayMenu(Pantry, Rec, linecount);		//pass both arrays into menu display
					
	FreeMem(Pantry,	ing_count);					//free the memory in Pantry 
	FreeMem(Rec, linecount);					//free the memory in Recipe 

	return 0; 
}
/**********************************************************************
* Purpose: This function reads the input data of Pantry.txt 
*
* Precondition:
*     Pantry - set to null before pass 
*
* Postcondition:
*      modifies the Pantry array to be filled 
************************************************************************/
void ReadFile(char **& Pantry)
{
	ifstream DataIn("pantry.txt");
	char * in = 0; 
	char buff[MAX] = { '\0' };

	while (DataIn.is_open())
	{
		while (DataIn.good())
		{
			while (!DataIn.eof())
			{
				DataIn.getline(buff, MAX); 

				in = new char[strlen(buff) + 1]; 
				strcpy(in, buff); 

				//insert into array
				Add(Pantry, in); 

				delete[] in; 
			}
			DataIn.close(); 
		}
	}
}
/**********************************************************************
* Purpose: This function Displays menu and directs user input through 
*	a switch. 
*
* Precondition:
*     Pantry - already filled. Passed in by reference since some options
*			will need to change the array: Delete(), Add(), and Edit()
*
* Postcondition:
*      Manipulates Pantry array with most options, and Recipe when user
*			wants to compare Recipe array to whats in the Pantry. 
************************************************************************/
void DisplayMenu(char **& Pantry, char **& Rec, int linecount)
{
	int in(0);
	char * cInput = 0; 

	cout << "Welcome to Chelsea's Pantry" << endl;
	do
	{		
		cout << "Menu:\n"
			<< "1. Add item\n"
			<< "2. Remove item\n"
			<< "3. Search pantry\n"
			<< "4. Edit item\n"
			<< "5. Save Pantry to file\n"
			<< "6. Display all items in Pantry\n"
			<< "7. Recipe check!\n"
			<< "8. EXIT\n" << endl; 
		cin >> in; 
		cin.clear(); 
		//handle errors - stay in this loop until 
		//correct input is received
		if (in < 1 || in > 8)
		{
			do
			{
				cout << "Please enter correct input.\n"; 
				cin >> in; 
			} while (in < 1 || in > 8);
		}	 

		switch (in)
		{	
			//Add
			case 1:
			{
				cout << "Add -" << setw(15) << left << " Let's stock up!\n"
					 << endl; 

				cInput = GetInput(); 
				Add(Pantry, cInput); 

				delete[] cInput;	//free memory from GetInput()

				cout << "I placed it on the top shelf!\n" << endl;
				break;
			}
			//Remove
			case 2:
			{
				cout << "Remove -" << setw(15) << left
					 << " Are we making something tonight?\n"
					 << endl; 

				cInput = GetInput();
				Remove(Pantry, cInput);

				delete[] cInput;	//free memory from GetInput()
				break;
			}
			//Search
			case 3:
			{
				cout << "Search -" << setw(15) << left
					<< " Why can't you go look yourself?\n"
					<< endl; 

				cInput = GetInput();
				if (Search(Pantry, cInput))
				{
					cout << "I found the "
						<< cInput << " you were looking for...\n"
						<< "Can I have some of what you're cookin'?\n"
						<< endl;
				}

				delete[] cInput;	//free memory from GetInput()
				break; 
			}
			//Edit
			case 4:
			{
				cout << "Edit" << setw(15) << left
					<< "I knew that pasta was actually gluten free.\nSMH\n";

				cInput = GetInput();
				Edit(Pantry, cInput);

				cout << "I just Sharpie'd over the original name.\n" << endl; 
				delete[] cInput;	//free memory from GetInput()
				break; 
			}
			//Save
			case 5:
			{
				cout << "Save -" << setw(15) << left
					 << "Oh, now I need to write this down again?\n"
					 << endl; 

				Save(Pantry); 
				break; 
			}
			//Display
			case 6:
			{
				cout << "Display -" << setw(15) << left
					 << "Guess what's in your pantry?\n"
					 << "Oh wait! You can't! Here:\n"
					 << endl; 

				Display(Pantry); 
				break; 
			}
			//Recipe search
			case 7: 
			{
				RecipeSearch(Pantry, Rec, linecount); 
				break; 
			}
			//Exit
			case 8: 
			{
				cout << "Closing Program" << endl; 
				return; 
				break; 
			}
			default:
				cout << "Error: Invalid input." << endl;
				break;
		}
	} while (in != 8); 
}

/**********************************************************************
* Purpose: This function recieves input from the console 
*
* Precondition:
*     no preconditions, called when input is needed from the user 
*
* Postcondition:
*     returns input from the buffer.
************************************************************************/
char * GetInput()
{
	char buff[MAX] = { '\0' };
	char * input = 0;

	
	cout << "Please enter an item/ingredient: "; 
	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buff, MAX);
	cin.clear();
	cout << endl; 

	input = new char[strlen(buff) + 1]; 
	strcpy(input, buff); 

	return input; 
}

/**********************************************************************
* Purpose: This function adds information to the Pantry array 
*
* Precondition:
*     Pantry	-	Passed in with or without information inside
*	  ing		-	ingredient word pointer passed in to be added 
*
* Postcondition:
*      modifies the Pantry array to have the word added.
************************************************************************/
void Add(char **& Pantry, char * ing)
{	
	char ** temp = 0;	//store array 

	//make room for one more elem
	temp = new char *[ing_count + 1]; 

	//copy all data		
	for (int i(0); i < ing_count; ++i)
	{
		temp[i] = Pantry[i]; 
	}

	//add the newest data
	temp[ing_count] = new char[strlen(ing) + 1]; 
	strcpy(temp[ing_count], ing); 

	ing_count++;	//update counter 

	delete[] Pantry; 
	Pantry = temp;	//update array 
}

/**********************************************************************
* Purpose: Searches through the Pantry array for the given target 
*
* Precondition:
*     Pantry	-	already filled 
*	  Target	-	char * of target to be found in Pantry
*
* Postcondition:
*      Returns boolean value that represents if value was found or not
************************************************************************/
bool Search(char ** Pantry, char * target)
{
	//assume not found 
	bool found(false); 

	for (int i(0); i < ing_count; ++i)
	{
		if (stricmp(Pantry[i], target) == 0)
		{
			found = true; 
		}
	}
	//literally - if not found 
	if (!found)
		cout << "I couldn't find " << target << "... :(\n"
			 << endl; 

	return found;
}

/**********************************************************************
* Purpose: Searches through the Pantry array for the given target, and 
*		user is able to edit the target - if found 
*
* Precondition:
*     Pantry	-	already filled
*	  Target	-	char * of target to be found in Pantry, and edited 
*
* Postcondition:
*      modifies target inside Pantry array. Calling Search(). 
************************************************************************/
void Edit(char **& Pantry, char * target)
{ 
	int index(0); //loop counter
	char * edit = 0; 

	if (Search(Pantry, target))
	{
		while (stricmp(Pantry[index], target) != 0)
		{
			index++; 
		}
		//breaks out of loop where item to be edited is

		cout << "Editing " << target;
		delete[] Pantry[index]; //delete previous data 

		edit = GetInput();	//get what the user wants to input 
		strcpy(Pantry[index], edit); //Save back into file 
	}
}

/**********************************************************************
* Purpose: Searches through the Pantry array for the given target, 
*		and user can delete the value if found 
*
* Precondition:
*     Pantry	-	already filled
*	  rmv	-	char * of target to be removed
*
* Postcondition:
*      deleted the item to be removed, and modifies the Pantry array
************************************************************************/
void Remove(char **& Pantry, char * rmv)
{
	char ** temp = 0;	//to store array 
	int index(0);		//tab on rmv variable
	bool loop(true);	//looping boolean 

	//If search found the unwanted item 
	if (Search(Pantry, rmv))
	{
		temp = new char *[ing_count - 1];	//create an array one LESS than needed 

		int i(0); 
		while (loop && (i < ing_count))
		{
			if (stricmp(Pantry[i], rmv) == 0)	//found the ing to rmv
			{
				delete[] Pantry[i];	//delete ing
				ing_count--;		//update count
				index = i;			//set index
				loop = false;		//break out of loop
			}
			else
				temp[i] = Pantry[i];	//traverse normally 
			i++;
		}

		//copied up to index 
		while (index < (ing_count))
		{
			//skip unwanted item ( + 1) 
			temp[index] = Pantry[index + 1];
			index++; 
		}

		delete[] Pantry;
		Pantry = temp;
	}
	else
		cout << "Must be dark in here, can't find what you want :(\n" << endl; 

}

/**********************************************************************
* Purpose: Opens the Pantry.txt file, and writes the Pantry array back
*		to it. Overwriting what was inside. 
*
* Precondition:
*     Pantry	-	already filled
*
* Postcondition:
*      changes Pantry file to have the updated array. 
************************************************************************/
void Save(char ** Pantry)
{
	//open file for output
	ofstream DataOut("pantry.txt"); 

	//loop through array and place into file - WILL 
	//overwrite previous contents 
	if (DataOut.is_open())
	{
		DataOut << "Chelsea's Pantry!" << endl;
		for (int i(0); i < ing_count; ++i)
		{
			DataOut << Pantry[i] << endl;
		}
	}
	DataOut.close(); 

	cout << "I'll remember this next time you visit\n" << endl; 
}

/**********************************************************************
* Purpose: loops through pantry array to display to console 
*
* Precondition:
*     Pantry	-	already filled
*
* Postcondition:
*      outputs array to console
************************************************************************/
void Display(char ** Pantry)
{
	//loop through and display contents of array 
	cout << "\nDisplaying all ingredients in your Pantry!\n" << endl; 
	for (int i(0); i < ing_count; ++i)
	{
		cout << setw(10) << left << Pantry[i] << endl;
	}
	cout << endl;
}

/**********************************************************************
* Purpose: Reads in from Recipe.txt  
*
* Precondition:
*     Rec	-	comes in empty
* Postcondition:
*      returns how many elements are in Rec array
*
************************************************************************/
int ReadRecipe(char **& Rec)
{
	ifstream DataIn("Recipe.txt");

	char * in = 0;
	char buff[MAX] = { '\0' };
	int linecount(0); 

	while (DataIn.is_open())
	{
		while (DataIn.good())
		{
			while (!DataIn.eof())
			{
				DataIn.getline(buff, MAX);

				in = RecipeParse(buff);

				RecAdd(Rec, in, linecount);	//calls add function - which will create a recipe line array 

				delete[] in; 
			}
			DataIn.close();
		}
	}
	return linecount; 
}

/**********************************************************************
* Purpose: Searches through an array for an ingredient between '<' and 
*	'>' and returns a char * of this ingredient 
*
* Precondition:
*     cstr[]	-	array that holds string of recipe 
*
* Postcondition:
*      returns a char * to the parsed ingredient
************************************************************************/
char * RecipeParse(char cstr[])
{
	char * ing = 0;
	char ingbuf[MAX] = { '\0' };
	int ing_count(0); 
	int i(0);
	bool found(false); 
	
	while (i < strlen(cstr))
	{
		while (cstr[i] != '<' && i < strlen(cstr))
			i++;

		if (cstr[i++] == '<')
		{
			found = true;
			while (cstr[i] != '>')
			{
				ingbuf[ing_count++] = cstr[i++]; 
			}
			ingbuf[ing_count] = '\0'; 
		}
	}

	if (found)
	{
		ing = new char[strlen(ingbuf) + 1];
		strcpy(ing, ingbuf); 
	}

	return ing; 
}
/**********************************************************************
* Purpose: Takes in pointer to ingredient, and adds into dynamic Recipe
*	array 
*
* Precondition:
*     Rec	-	reference array, ready to take in new ingredient 
*	  line	-	char * of ingredient to be added
*	  linecount -	counter of how many words in array 
*
* Postcondition:
*      modifies recipe array 
************************************************************************/
void RecAdd(char **& Rec, char * line, int & linecount)
{
	char ** temp = 0;	//store array 

	//make room for one more elem
	temp = new char *[linecount + 1];

	//copy all data 
	for (int i(0); i < linecount; ++i)
	{
		temp[i] = Rec[i];
	}

	//add the newest data
	temp[linecount] = new char[strlen(line) + 1];
	strcpy(temp[linecount], line);

	linecount++;	//update counter 

	delete[] Rec;
	Rec = temp;	//update array 
}

/**********************************************************************
* Purpose: Loops through recipe array, and for every word it calls
*		pantry search to check if the ingredient is in stock. 
*
* Precondition:
*     Pantry	-	Pantry array which will be passed to Search()
*	  Rec	-	Recipe array with ingredients 
*	  linecount -	counter of how many words in array
*
* Postcondition:
*      console output on what you do/dont have in the pantry 
************************************************************************/
void RecipeSearch(char ** Pantry, char ** rec, int linecount)
{
	//loop through recipe array and send each char [] to Search
	int i(0); 

	while (i < linecount)
	{
		if (Search(Pantry, rec[i]))
		{
			cout << "You have " << rec[i]
				<< " in stock! Let's get cookin'\n"
				<< endl;
		}
		else
			cout << "Time to shop for " << rec[i] <<"\n"<< endl; 

		i++; 
	}
}

/**********************************************************************
* Purpose: Frees memory in array passed in, looping for the count
*
* Precondition:
*	  array  -	array with memory to be freed 
*	  count	-	count for how many elements are inside array 
*
* Postcondition:
*      modifies both array and resets count. 
************************************************************************/
void FreeMem(char **& array, int & count)
{
	//loop through array 
	for (int i(0); i < count; ++i)
	{
		delete[] array[i];	//free inside data 
	}
	delete[] array;	//delete array 
	count = 0;		//reset counter 
}
