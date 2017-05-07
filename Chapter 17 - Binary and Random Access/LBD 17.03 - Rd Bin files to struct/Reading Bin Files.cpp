/*************************************************************
* Author:		Chelsea Christison
* Filename:		Reading Bin Files.cpp
* Date Created:	02/17/2017
* Modifications:
*************************************************************
*
* Lab/Assignment: Learn By Doing 17.03.1
*
* Overview:
*	 This program reads from a txt file into a structure
*	in binary, and stores info in an array of structs
*	Finally, rewriting back to the txt file, in binary, 
*	first with the number of records in array 
*
* Input:
*    Text.txt containing structure information with the 
*	format: First name, last name, hourly wage, hours 
*
* Output:
*	 no outputs
************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream; 
using std::ofstream; 
using std::ios; 

const int MAX(20); 
const int STUDENTNUM(5); 

//student structure to read into 
struct Student
{
	char first_name[MAX];
	char last_name[MAX]; 
	float hourly_wage; 
	int hours;
};

//functions
int ReadAndFill(Student array[]); 
void WriteToFile(Student array[], int num_students); 
void Display(Student array[]); 

int main()
{
	Student stud_array[STUDENTNUM]; 

	int student_count = 
	ReadAndFill(stud_array);
	Display(stud_array); 

	WriteToFile(stud_array, student_count); 

	return 0; 
}

/**********************************************************************
* Purpose: This function reads in the txt file as binary and fills 
*	the student structure array 
*
* Stipulations: none
*
* Precondition:
*     array - always empty, five student structures total 
*
* Postcondition:
*      fills the array 
************************************************************************/
int ReadAndFill(Student array[])
{
	ifstream fin("Text.txt");
	int student_count(0); 

	if (fin.is_open())
	{
		char fname_buffer[MAX];
		char lname_buffer[MAX];
		float wage_buffer(0.0f);
		int hour_buffer(0); 
		int index(0); 

		while (!fin.eof())
		{
			fin >> fname_buffer >> lname_buffer >> wage_buffer >> hour_buffer; 
		
			strcpy(array[index].first_name, fname_buffer);
			strcpy(array[index].last_name, lname_buffer); 
			array[index].hourly_wage = wage_buffer; 
			array[index].hours = hour_buffer; 
			index++; 
		}

		student_count = index; 
	}
	else
		cout << "File could not be opened" << endl; 

	return student_count; 
}

/**********************************************************************
* Purpose: This function writes back to a binary file 
*
* Stipulations: none
*
* Precondition:
*     array - filled, five student structures total
*
* Postcondition:
*      creates a .bin file 
************************************************************************/
void WriteToFile(Student array[], int num_students)
{
	ofstream fout("Students.dat", ios::out | ios::binary); 

	if (fout.is_open())
	{
		fout.seekp(0);	
		fout.write(reinterpret_cast<char *>(&num_students), sizeof(num_students));
		fout.write(reinterpret_cast<char*>(array), sizeof(Student) * num_students);
		fout.close();
	}
	else
		cout << "file could not open" << endl;
}

void Display(Student array[])
{
	for (int i(0); i < STUDENTNUM; i++)
	{
		cout << array[i].first_name << " " << array[i].last_name << " " 
			<< array[i].hourly_wage << " " << array[i].hours << endl; 
	}
}

