/*************************************************************
* Author:		Chelsea Christison
* Filename:		Source.cpp
* Date Created:	2.21.2017
* Modifications:	
**************************************************************/
#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <fstream>
using std::ifstream;
using std::ofstream;

#include<iomanip>
using std::left;
using std::setw;
using std::setfill; 

#include<string>
using std::string; 

/*#include<cctype>
#include<cstring>*/

/*CONSTANTS*/
const int MAXCHAR(20);
const int MAXINT(13);
const int MAXP(10); 

/*Prototypes called in main()*/
//int ReadFile(string txt_name, char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT]);
//bool BubbleSort(int count, char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT]);
//int DisplayMenu();
//void ProcessChoice(char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT], int userinput, int & count);

int ReadFile(string txt_name, string fname[], string lname[], string phone_number[], string birth_day[]);
bool BubbleSort(int count, string fname[], string lname[], string phone_number[], string birth_day[]);
int DisplayMenu();
void ProcessChoice(string fname[], string lname[], string phone_number[], string birth_day[], int & count);

/*Called from ProcessChoice()*/
//int Find(char target[], char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT], int count);
//void Add(char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT], int & person_count);
//void Edit(int index, int count, char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT]);
//void DisplayAll(int person_count, char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT]);

int Find(string target, string fname[], string lname[], string phone_number[], string birth_day[], int count);
void Add(string fname[], string lname[], string phone_number[], string birth_day[], int & person_count);
void Edit(int index, int count, string fname[], string lname[], string phone_number[], string birth_day[]);
void DisplayAll(int person_count, string fname[], string lname[], string phone_number[], string birth_day[]);

/*Extra functions*/
//void Swap(char fname[][MAXCHAR], char lname[][MAXCHAR], char phone_number[][MAXINT], char birth_day[MAXP][MAXINT], int element, int i);
void Swap(string fname[], string lname[], string phone_number[], string birth_day[], int element, int i);
void WriteFile(string txt_name, string fname[], string lname[], string phone_number[], string birth_day[], int person_count);

int main()
{
	/*Array Declarations*/
	string fname[MAXP];				//holds first name
	string lname[MAXP];				//holds last name 
	string phone_number[MAXP];		//holds 10 digit phone number 
	string birth_day[MAXP];			//holds 10 character birth date: mm/dd/yyyy 

	/*Variables*/
	int person_count(0);								//counter counts amount of people in Array database
	int userinput(0);									//userinput number for switch statement 
	string txt_name; 


	cout << "Please name .txt file: "; 
	cin >> txt_name; 

	//read in the file, find out how many people there are 
	person_count = ReadFile(txt_name, fname, lname, phone_number, birth_day); 

	//capitalize lname and fname
	for (int k(0); k < person_count; k++)
	{
		fname[k][0] = toupper(fname[k][0]);
		lname[k][0] = toupper(lname[k][0]);
	}

	//sort the array once read in. 
	BubbleSort(person_count, fname, lname, phone_number, birth_day); 

	//Process input 
	ProcessChoice(fname, lname, phone_number, birth_day, person_count); 

	WriteFile(txt_name, fname, lname, phone_number, birth_day, person_count);

	system("pause"); 
	return 0; 
}
/*****************************************************************************************************************
*ReadFile(): Takes in all user information arrays, with user-given txtfile name. 
*
*****************************************************************************************************************/
int ReadFile(string txt_name, string fname[], string lname[], string phone_number[], string birth_day[])
{
	//variables 
	int count(0);				//counts people coming in 
	//open txt file 
	ifstream data_file("PeopleInformation.txt");

	//check to see if file is open 
	if (data_file.is_open())
	{
		//priming read 
		data_file >> fname[count]
				  >> lname[count]
				  >> phone_number[count]
				  >> birth_day[count];
		//read until end of file 
		while (!data_file.eof())
		{
			count++;
			data_file >> fname[count]
					  >> lname[count]
					  >> phone_number[count]
					  >> birth_day[count];
		}
		//close file once finished
		data_file.close();
	}
	else
		cout << "Error: Unable to open " + txt_name + ".txt!" << endl; 

	return (count + 1);
}
/*****************************************************************************************************************
*BubbleSort(): Sorts by last name, if last names are the same - sort by first name .
*
*****************************************************************************************************************/
bool BubbleSort(int count, string fname[], string lname[], string phone_number[], string birth_day[])
{
	bool sorted(false);					//always assume it's not sorted 
	char temp[MAXCHAR];					//temp array used as a throwaway 
	int tempcount(count);				//temp counter 
	int row (0);						//tracks current row in array accessed 
	int element(0);				    	//tracks current element in array 
	int pass(0);						//tracks numbers of passes 

	while (pass < tempcount || sorted == false)
	{
		sorted = true;
		for(int i(0); i < tempcount - 1; i++)							//If letter1 is > letter2 
		{
			if (lname[i] > lname[i + 1])				//is first lname larger than second lname
			{
				sorted = false; 
				//swap lname
				Swap(fname, lname, phone_number, birth_day, element, i); 
			}
			else if (lname[i] == lname[i + 1])		//if letter1 == letter2
			{
				sorted = false;
				do						//loop to keep looking at the next element as long as they are equal.	
				{
					element++;			//increment element 
					if (lname[i] > lname[i + 1])
						Swap(fname, lname, phone_number, birth_day, element, i);

				} while (lname[i] == lname[i + 1]);
				element = 0;
			}
			else
				sorted = true; 
		}
		pass++;			//one iteration is done, move on to the next 
	}

	/*for (int k(0); k < tempcount; k++)
		cout << lname[k] << ", " << fname[k] << endl; */

	return sorted; 

}
/*****************************************************************************************************************
*Swap(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with 
* lname2. 
*
*****************************************************************************************************************/
void Swap(string fname[], string lname[], string phone_number[], string birth_day[], int element, int i)
{
	string temp;

	//cout check 
	/*cout << lname[i] << ", " << fname[i] << " " << birth_day[i] << "  " << phone_number[i] << endl; 
	cout << lname[i+1] << ", " << fname[i+1] << " " << birth_day[i+1] << "  " << phone_number[i+1];*/
	
	//first swap the last name 
	temp = lname[i];				//lname into the temp 
	lname[i] = lname[i + 1];		//copy into first lnname, the second one
	lname[i + 1] = temp;			//copy into second lname, whats in temp. Lname is switched 

	//Swap fname 
	temp = fname[i];				
	fname[i] = fname[i + 1];		
	fname[i + 1] = temp;

	//Swap phone
	temp = phone_number[i];
	phone_number[i] = phone_number[i + 1];
	phone_number[i + 1] = temp;

	//Swap birthday 
	temp = birth_day[i];
	birth_day[i] = birth_day[i + 1];
	birth_day[i + 1] = temp;

	//cout check
	/*cout << lname[i] << ", " << fname[i] << " " << birth_day[i] << "  " << phone_number[i] << endl;
	cout << lname[i + 1] << ", " << fname[i + 1] << " " << birth_day[i + 1] << "  " << phone_number[i + 1];*/
}
/*****************************************************************************************************************
*DisplayMenu(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with
* lname2.
*
*****************************************************************************************************************/
int DisplayMenu()
{
	int userinput; 
	cout << "\t\t\t\tWhat are you here for?" << endl;
	do 
	{
		cout << "1) Find a person's Info" << endl
			 << "2) Add a person to database" << endl
			 << "3) Edit a person to database" << endl
			 << "4) Display everyone in database" << endl
			 << "5) Exit" << endl;
		cin >> userinput;

		if (userinput > 6 || userinput < 0)
			cout << "Please enter a valid number!" << endl; 
	} while (userinput > 6 || userinput < 0);

	return userinput; 
}
/*****************************************************************************************************************
*ProcessChoice(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with
* lname2.
*
*****************************************************************************************************************/
void ProcessChoice(string fname[], string lname[], string phone_number[], string birth_day[], int & count)
{
	int userinput(0);
	do
	{
		userinput = DisplayMenu(); 
		switch (userinput)
		{
			case 1://Find
			{
				string target;
				cout << "\nPlease enter the last name of person you're looking for: "; 
				cin >> target; 
				//cin.getline(target, MAXCHAR);

				Find(target, fname, lname, phone_number, birth_day, count); 
				break;
			}
			case 2://Add
				Add(fname, lname, phone_number, birth_day, count); 
				break;
			case 3://Edit
			{
				char target[MAXCHAR] = { '\0' };
				cout << "\nPlease enter the last name of person you're looking for: ";
				cin >> target;

				int index = Find(target, fname, lname, phone_number, birth_day, count);

				Edit(index, count, fname, lname, phone_number, birth_day); 
				break;
			}
			case 4://Display 
				DisplayAll(count, fname, lname, phone_number, birth_day);
				break;
			case 5://Exit
				   //update to txtfile 

				break;
			default:
				cout << "Please pick option from menu ";
		}
     } while (userinput != 5);
}
/*****************************************************************************************************************
*Find(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with
* lname2.
*
*****************************************************************************************************************/
int Find(string target, string fname[], string lname[], string phone_number[], string birth_day[], int count)
{
	bool found(false); 
	int left(0), 	    //start of array chunk
		right(count),	//right end of array chunk
		mid(0), 	    //Middle of chunk 
		index(-1);	    //index in row where user info is found 
		
	while (left <= right && found == false)
	{
		mid = (left + right) / 2; 

		if (target == lname[mid])		//if target == lname[mid]; 
		{
			cout << "\n****\n" << lname[mid] << ", " << fname[mid] << " " << phone_number[mid] << " " << birth_day[mid] << "\n\n";
			found = true;
			index = mid; 
		}
		else if (target > lname[mid])	//if target > lname[mid] reset left end and look upper half 
			left = mid + 1;
		else										//if target < lname[mid] reset right end to look at lower half 
			right = mid - 1; 
	}
	if (found == false)
		cout << "The person you are looking for is not in the database!" << endl; 

	return index;		//if index returns a -1, it did not find the person. 
}
/*****************************************************************************************************************
*Add(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with
* lname2.
*
*****************************************************************************************************************/
void Add(string fname[], string lname[], string phone_number[], string birth_day[], int & person_count)
{
	int index = person_count; 
	if (person_count < 9)
	{
		cout << "Here you can add a person to the database.\nYou can currently add: " << MAXP - person_count << " people!\n";
		cout << "Please enter the first name: ";
		cin >> fname[index];

		cout << endl << "Please enter the last name: ";
		cin >> lname[index];

		cout << endl << "Please enter 10-digit phone number (no ' - '): ";
		cin >> phone_number[index];

		phone_number[index].insert(3, 1, '-');
		phone_number[index].insert(7, 1, '-');

		cout << endl <<"Please enter birth day (mm/dd/yyyy): ";
		cin >> birth_day[index];
		cout << endl; 

		//capitalize name 
		fname[index][0] = toupper(fname[index][0]);
		lname[index][0] = toupper(lname[index][0]);

		cout << "\nAdded\n" << lname[index] << ", " << fname[index] << " " << phone_number[index] 
			 << " " << birth_day[index] << endl;

		person_count++;

		BubbleSort(person_count, fname, lname, phone_number, birth_day);

	}
	else
		cout << "Only 10 people allowed in database, can't add another person.\n" << endl; 
}
/*****************************************************************************************************************
*Edit(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with
* lname2.
*
*****************************************************************************************************************/
void Edit(int index, int count, string fname[], string lname[], string phone_number[], string birth_day[])
{
	int userinput(0); 
	string nametemp;		//temp array for lname or fname changes 
	string numbertemp;		//temp array for birth or phone changes

	if (index != -1)					//if the index holds a row value, and not a "false" 
	{
		cout << "Which property would you like to edit:\n1. First Name\n2. Last Name\n3. Phone Number\n4. Birth Day ";
		cin >> userinput;

		switch (userinput)
		{
		case 1://edit fname 
		{
			cout << "\nEditing first name. What is the new first name: ";
			cin >> nametemp; 

			fname[index] = nametemp;												//copy temp into the edited name 
			cout << "\nEdit complete!\n" << lname[index] << ", " << fname[index] 
				 << " " << phone_number[index] << " " << birth_day[index] << "\n\n";		//cout the new information 
			break;
		}
		case 2://edit lname
		{
			cout << "\nEditing last name. What is the new last name: ";
			cin >> nametemp;

			lname[index] = nametemp;												//copy temp into the edited name 
			cout << "\nEdit complete!\n" << lname[index] << ", " << fname[index]
				<< " " << phone_number[index] << " " << birth_day[index] << "\n\n";		//cout the new information 
			break;
		}
		case 3://edit phone_number 
		{
			cout << "\nEditing phone number. What is the new number (no '-'): ";
			cin >> numbertemp;

			phone_number[index] =  numbertemp;								    //copy temp into the edited name 
			phone_number[index].insert(3, 1, '-');
			phone_number[index].insert(7, 1, '-');
			cout << "Edit complete!\n" << lname[index] << ", " << fname[index]
				<< " " << phone_number[index] << " " << birth_day[index] << "\n\n";		//cout the new information 
			break;
		}
		case 4://edit birth_date 
		{
			cout << "\nEditing birthday. What is the new birthday (mm/dd/yyyy): ";
			cin >> numbertemp;

			birth_day[index] = numbertemp;								       //copy temp into the edited name 
			cout << "\nEdit complete!\n" << lname[index] << ", " << fname[index]
				<< " " << phone_number[index] << " " << birth_day[index] << "\n\n";	   //cout the new information 
			break;
		}
		default:
			cout << "\nPlease choose a real option...";
		}

		if(userinput == 2)		//if the user chose to edit the last name
			BubbleSort(count, fname, lname, phone_number, birth_day); 

	}

}
/*****************************************************************************************************************
*DisplayAll(): takes in position of row, i. and the element currently looking at (most likely 0). Will Swap lname1 with
* lname2.
*
*****************************************************************************************************************/
void DisplayAll(int person_count, string fname[], string lname[], string phone_number[], string birth_day[])
{
	cout << "\nDatabase Files\n\n"; 
	cout << left << setw(18) << "   Last Name"
		 << left << setw(15) << "First Name"
		 << left << setw(20) << "Phone Number"
		 << left << "Birthday\n";
	cout << "_________________________________________________________________________________\n";
	for (int i(0); i < person_count; i++)
	{
		cout << i + 1 << ". " << left << setw(15) << lname[i] << ", " 
			 << left << setw(12) << fname[i] << " " 
			 << left << setw(10) << phone_number[i]
			 << left << setw(8) << " " << birth_day[i] << endl;
	}
	cout << "_________________________________________________________________________________\n"; 
}
void WriteFile(string txt_name, string fname[], string lname[], string phone_number[], string birth_day[], int person_count)
{
	ofstream data_out("PeopleInformation.txt"); 

	if (data_out.is_open())
	{
		for (int i(0); i < person_count; i++)
		{
			data_out << fname[i] << " " << lname[i] << " " << phone_number[i] << " " << birth_day[i] << endl; 
		}
		cout << "Text file updated" << endl; 
		data_out.close();		
	}
}