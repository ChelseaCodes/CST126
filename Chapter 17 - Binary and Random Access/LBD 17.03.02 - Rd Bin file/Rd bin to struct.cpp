/*************************************************************
* Author:		Chelsea Christison
* Filename:		Rd bin to struct.cpp
* Date Created:	02/17/2017
* Modifications:
*************************************************************
*
* Lab/Assignment: name of such
*
* Overview:
*	 This program .... what does it do?
*
* Input:
*    what are the inputs? txt files, user input ect.
*	include an example below
*
* Output:
*	 The output of this program will be... to console?
*	to a txt file, no output? Paste and example below
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
void ReadAndFill();
void ReadOneAtATime(); 

int main()
{
	//ReadAndFill(); 
	ReadOneAtATime();

	return 0;
}

void ReadAndFill()
{
	ifstream fin("Students.dat", ios::in | ios::binary);
	int student_number(0); 
	Student * students = nullptr; 

	if (fin.is_open())
	{
		fin.read(reinterpret_cast<char *>(&student_number), sizeof(student_number));
		students = new Student[student_number];
		fin.read(reinterpret_cast<char*>(students), sizeof(Student) * student_number);
		fin.close();
	}
	else
		cout << "could not open file" << endl; 


	for (int i(0); i < student_number; i++)
	{
		cout << students[i].first_name << " " << students[i].last_name << " " << students[i].hourly_wage
			<< " " << students[i].hours << endl; 
	}

}

void ReadOneAtATime()
{

	ifstream fin("Students.dat", ios::in | ios::binary);
	int student_number(0);
	Student * students = nullptr;

	if (fin.is_open())
	{
		fin.read(reinterpret_cast<char *>(&student_number), sizeof(student_number));
		students = new Student[student_number];
		Student temp = Student(); 
		for (int i(0); i < student_number; i++)
		{
			fin.read(reinterpret_cast<char*>(&temp), sizeof(Student));
			strcpy(students[i].first_name, temp.first_name);
			strcpy(students[i].last_name, temp.last_name); 
			students[i].hourly_wage = temp.hourly_wage;
			students[i].hours = temp.hours; 
		}

		fin.close();
	}
	else
		cout << "could not open file" << endl;


	for (int i(0); i < student_number; i++)
	{
		cout << students[i].first_name << " " << students[i].last_name << " " << students[i].hourly_wage
			<< " " << students[i].hours << endl;
	}
}
