/*************************************************************
* Author:		Chelsea Christison
* Filename:		PE 12.20.2.cpp
* Date Created:	01/25/2017
* Modifications:	1.25.17 - Created file and code 
*					1.25.17 - commented 
*************************************************************
*
* Lab/Assignment: Programming Exercise 12.20.2 
*
* Overview:
*	This program will read in a word from a txt file and store
*	into a dynamically created array when encountered. Also 
*	has a parallel integer array that keeps count of the 
*	number of times each word appears in the file. 
*
* Input:
*	The input file will contain a Bill Cosby quote and 
*	will read in one word at a time. Each word will be 
*	checked for punctuation, and punctuation will be 
*	removed if found. 
*	
*	input ex: 
*	I don't know the key to success, but the key to 
*	failure is trying to please everybody. 
*
* Output:
*	The output of this program will be the data inside both 
*	arrays. One output is the words collected, and the other
*	is the frequency each word appeared. Like so: 
*	
*	Words			Frequency
*	I				1
*	don't			1
*	know			1
*	the				2
*	...				...	
*
*
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include<iostream>
using std::cout; 
using std::endl;

#include<iomanip>
using std::setw;
using std::left;

#include<fstream>
using std::ifstream; 

#include<crtdbg.h>

//Functions
void ReadFile(char **& w_array, int **& f_array, int &word_count); 
void InsertWords(char **& w_array, int **& f_array, char * word, int &freq_count, int &word_count);
void PunctCheck(char *& word);
void PrintData(char ** w_array, int ** f_array, int word_count); 
void MemoryClean(char **& w_array, int **& f_array, int & word_count); 

const int MAX_W(12);

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//Variables
	char ** w_array = 0;			//char dbl ptr array 
	int ** f_array = 0;				//int dbl ptr array 
	int word_count(0);

	ReadFile(w_array, f_array, word_count);				//read and fill the arrays 
	
	PrintData(w_array, f_array, word_count);			//print all information 

	MemoryClean(w_array, f_array, word_count);			//delete information and arrays 

	return 0; 
}
/**********************************************************************
* Purpose: This function reads the input data for each word.
*
* Precondition:
*     w_array -	by reference, null at entry 
*	  f_array - by reference, null at entry 
*	  word_count - by reference, zero at entry 
*
* Postcondition:
*      Calling InsertWords() will read and fill arrays for print 
************************************************************************/
void ReadFile(char **& w_array, int **& f_array, int & word_count)
{ 
	char * word = 0; 
	char w_buff[MAX_W] = { '\0' };
	int frequency(1); 
	
	ifstream DataIn("Text.txt"); 

	if (DataIn.is_open())
	{
		while (DataIn.good())
		{
			while (!DataIn.eof())
			{
				DataIn >> w_buff;								//read in one word 

				word = new char[strlen(w_buff) + 1];			//allocate space for word * 
				strcpy(word, w_buff);							//copy buffer into perfect size array 

				InsertWords(w_array, f_array, word, frequency, word_count); 

				delete [] word; 
			}
		}
	}
	DataIn.close(); 
}

/**********************************************************************
* Purpose: This function inserts word into w_array, and updates 
*	  frequency array. 
*
* Precondition:
*     w_array -	Filled or not, will be changed and managed dynamically 
*	  f_array - Filled or not, will be changed and managed dynamically
*	  word_count - contains current count of elements in both arrays 
*
* Postcondition:
*      Modifies w_array and f_array, adding an extra row when neccesary
*	   and updates the counts inside of f_array if word is duplicate
*
************************************************************************/
void InsertWords(char **& w_array, int **& f_array, char * word, int &freq_count, int &word_count)
{
	char ** w_temp = 0;
	int ** f_temp = 0; 
	bool add(true);

	//First check punctuation of word 
	PunctCheck(word); 

	w_temp = new char *[word_count + 1]; 
	f_temp = new int *[word_count + 1]; 

	for (int i(0); i < word_count; ++i)
	{
		w_temp[i] = w_array[i];				//copy over to temp 
		f_temp[i] = f_array[i]; 

		if (stricmp(w_array[i], word) == 0)		//if incoming word is not in array
		{
			add = false;						//otherwise don't add 
			*f_temp[i] = *f_array[i] + 1;		//but increment counter for given word 
		}
	}

	if (add)
	{
		w_temp[word_count] = new char[strlen(word) + 1];	
		strcpy(w_temp[word_count], word);		//copy into allocated space the word 

		f_temp[word_count] = new int[sizeof(freq_count)]; 
		*f_temp[word_count] = freq_count; 

		++word_count;		//increment word count
	}
		delete[] w_array;	//delete old array
		w_array = w_temp;	//set to new array

		delete[] f_array;
		f_array = f_temp; 
}

/**********************************************************************
* Purpose: This function takes in word ptr and rewrites onto itself
*			excluding any punctuation - effectively removing it 
*
* Precondition:
*     Word - character pointer to array with word 
*
* Postcondition:
*      Modifies the word ptr to exculde punctuation 
*
************************************************************************/
void PunctCheck(char *& word)
{
	int wr(0);
	int rd(0); 

	while (word[rd])
	{
		if (word[rd] != ',' && word[rd] != '.' && word[rd] != '?')	//if char at element is neither a comma or period
			word[wr++] = word[rd];				//copy char back into same element, and increment write

		rd++;	//traverse 
	}

	word[wr] = '\0';	//place null onto end of string. 
}

/**********************************************************************
* Purpose: This function prints all data in w_array and f_array
*
* Precondition:
*     w_array	 - filled 
*	  f_array	 - filled 
*	  word_count - contains count of words in arrays 
*
* Postcondition:
*      Outputs to console 
*
************************************************************************/
void PrintData(char ** w_array, int ** f_array, int word_count)
{
	cout << setw(13) << left << "Words" << setw(13) << left << "Frequency\n" << endl;

	for (int i(0); i < word_count - 1; ++i)
	{
		cout << setw(13) << left << w_array[i]
			<< setw(13) << left << *f_array[i] << endl; 
	}
}

/**********************************************************************
* Purpose: This function cleans memory allocated by InsertWord()
*
* Precondition:
*     w_array	 - filled
*	  f_array	 - filled
*	  word_count - contains count of words in arrays
*
* Postcondition:
*      Modifies both arrays. Frees any memory allocated previously
*	   Sets word count to zero, and deletes arrays 
*
************************************************************************/
void MemoryClean(char **& w_array, int **& f_array, int &word_count)
{
	for (int i(0); i < word_count; ++i)
	{
		delete[] w_array[i]; 
		delete[] f_array[i];
	}
	delete[] w_array; 
	delete[] f_array; 
	word_count = 0; 
}

