/*************************************************************
* Author:		Chelsea Christison
* Filename:		PE 13_09.cpp
* Date Created:	2.8.2017
* Modifications:
*	2.8.2017 - began the read in process
*	2.10.2017 - made modifications to read in process. 
*				finished, and commented code.
*
* Lab/Assignment: Chapter 13 Programming Exercise 13.09
*
* Overview:
*	This program will read info from a .txt file and store it 
*	in a dynamic 2D array of Employee Structures. Creation 
*	of structure will include computing overtime pay, and 
*	deducting union dues where applicable. 
*
* Input:
*	Program input is EmployeeInfo.txt, containing the name, 
*	social security number(SSN), wage/hr, hours worked, 
*	and status of employment. Form:
*
*	John Smith 123-09-8765 9.00 46 F
*	Molly Brown 432-89-7654 9.50 40 F
*
* Output:
*	The output of this program will be all Employee info,
*	nicely formatted into columns,
*	including their calculated Overtime pay and Net pay. 
*	Form: 
*
*	John Smith  123-09-8765  F  $ 9.00  46  $ 360.00  $81.00 
*	$ 436.00
*
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include<iostream> 
using std::cout; 
using std::endl;

#include<fstream>
using std::ifstream; 

#include<iomanip>
using std::setw;
using std::left;
using std::right; 
using std::setprecision; 
using std::fixed; 
using std::setfill; 

#include<crtdbg.h>

//consts
const int MAX(35);
const int MAX_HOURS(40);
const float OVERTIME_ADJUST(1.5f);
const float UNION_DUES(5.00f);

struct Employee
{
	char * fname;
	char * lname;
	char * social;
	float wage;
	int weeklyhours;
	char status; 
	float straighttimepay; 
	float overtimepay; 
	float netpay; 
};

//functions
void ReadFile(Employee *** employees); 
Employee * MakeEmployee(char first_name[], char last_name[], char social[], float wage, int weeklyhours, char status);
void AddEmployee(Employee *** employees, Employee ** newEmployee);
void DisplayEmployees(Employee ** employees);
void FreeMemory(Employee *** employees); 

//globals
int employee_count(0); 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Employee ** employees = nullptr; 
	
	ReadFile(&employees);			//read the file, and create 2D array
	DisplayEmployees(employees);	//display all information 
	FreeMemory(&employees);			//free all memory allocated 

	return 0; 
}

/**********************************************************************
* Purpose: This function reads the input data for each Employee struct.
*		Calls MakeEmployee() and AddEmployee(). 
*
* Precondition:
*     employees - Comes in as nullptr, triple star Employee array.
*					catching the address of empty 2D array.
*
* Postcondition:
*      Modifies 2D Employee array.
*
************************************************************************/
void ReadFile(Employee *** employees)
{
	ifstream ReadFile("EmployeeInfo.txt");

	char first_name_buffer[MAX] = { '\0' };
	char last_name_buffer[MAX] = { '\0' };
	char social_buffer[MAX] = { '\0' };
	float wage_buffer(0.0f); 
	int hour_buffer(0); 
	char status_buffer('\0');

	if (ReadFile.is_open())
	{
		if (ReadFile.good())
		{
			while (!ReadFile.eof())
			{
				ReadFile >> first_name_buffer >> last_name_buffer >> social_buffer >> wage_buffer
						 >> hour_buffer >> status_buffer;

				if (strlen(first_name_buffer) > 1)
				{
					Employee * e = MakeEmployee(first_name_buffer, last_name_buffer, social_buffer, wage_buffer, hour_buffer, status_buffer);
					AddEmployee(employees, &e); 
				}
			}
		}
		ReadFile.close(); 
	}
}

/**********************************************************************
* Purpose: This function creates a pointer to a filled Employee struct
*	to be passed back for insertion to the 2D Employee array. Does 
*	all calculations needed depending on weeklyhours and status of 
*	employment. 
*
* Stipulations: 
*	  Caller must delete allocated memory for Employee struct data
*
* Precondition:
*     first_name - size of the MAX buffer, not null 
*	  last_name  - "
*	  social     - "
*	  wage       - size of a float, not null 
*	  weeklyhours- size of an int, not null
*     status     - size of a char, not null 
*
* Postcondition:
*      Returns a pointer to filled Employee struct
*
************************************************************************/
Employee * MakeEmployee(char first_name[], char last_name[], char social[], float wage, int weeklyhours, char status)
{
	//create shell of employee struct 
	Employee * newEmployee = new Employee();

	//copy all information passed, into struct 
	newEmployee->fname = new char[strlen(first_name) + 1];
	strcpy(newEmployee->fname, first_name);

	newEmployee->lname = new char[strlen(last_name) + 1];
	strcpy(newEmployee->lname, last_name);

	newEmployee->social = new char[strlen(social) + 1];
	strcpy(newEmployee->social, social);
	newEmployee->wage = wage;
	newEmployee->weeklyhours = weeklyhours;
	newEmployee->status = status;

	//perform applicable calculations
	//check for overtime
	if (weeklyhours > 40)
	{
		//calculate straight time pay up to max hours 40
		newEmployee->straighttimepay = wage * MAX_HOURS;

		//Calculate overtime pay using elevated pay rate (wage * 1.5)
		int hourly_difference = weeklyhours - MAX_HOURS; 
		newEmployee->overtimepay = (wage * OVERTIME_ADJUST) * hourly_difference;

		//net = overtime + straight time
		newEmployee->netpay = newEmployee->straighttimepay + newEmployee->overtimepay;
	}
	else
	{
		//no overtime, regular straight time pay
		newEmployee->overtimepay = 0.0f;
		newEmployee->straighttimepay = wage * weeklyhours;
		newEmployee->netpay = wage * weeklyhours;
	}

	//deduct union dues from net pay if full time 
	if (status == 'F')
	{
		newEmployee->netpay -= UNION_DUES; 
	}
	
	return newEmployee;
}

/**********************************************************************
* Purpose: This function adds an Employee structs into the 2D array
*
* Stipulations: 
*	  Caller must delete memory allocated for new Employee in 2D array
*
* Precondition:
*     employees - 2D array of Employee structs, first passed as nullptr
*			      further passes include Employee information.
*	  newEmployee - pointer to the new Employee information, passed by
*					pointer, not null. 
*	  employee_count - global int, containing total employees in array
*                      
* Postcondition:
*      Modifies the 2D employee array, and employee_count
*
************************************************************************/
void AddEmployee(Employee *** employees, Employee ** newEmployee)
{
	//declare temp
	Employee ** temp = nullptr;

	temp = new Employee *[employee_count + 1];

	for (int i(0); i < employee_count; i++)
	{
		temp[i] = (*employees)[i]; 
	}
	temp[employee_count] = *newEmployee;

	employee_count += 1; 

	//reset 2D array to new one 
	delete[](*employees);
	(*employees) = temp; 
}

/**********************************************************************
* Purpose: This function displays all information inside 2D array in 
*	 a composed, formatted manner. 
*
* Precondition:
*     employees - 2D array containing all read data from txt file, 
*					can't be null. 
*
* Postcondition:
*      Outputs to console all 2D array contents. 
*
************************************************************************/
void DisplayEmployees(Employee ** employees)
{
	cout << setw(20) << left << "     Name" << setw(12) << left << "    SSN" << setw(5) << left << "Stat" << setw(7) << right << " Wage"
		 << setw(4) << left << " Hrs" << setw(10) << right << "ST Pay" << setw(10) << right << "  OT Pay" << setw(11)
		 << right << "Net Pay" << endl;
	for (int i(0); i < 80; i++)
	{
		cout << '_';
	}
	cout << endl; 
	for (int i(0); i < employee_count; i++)
	{
		cout << setw(9) << left << employees[i]->fname << setw(11) << left << employees[i]->lname
			 << setw(13) << left << employees[i]->social << setw(4) << left << employees[i]->status << "$" << setw(6) << right << fixed
			 << setprecision(2)  << employees[i]->wage << setw(4) << employees[i]->weeklyhours << setw(3) << right
			 << "$" << setw(7) << fixed << setprecision(2)<< right << employees[i]->straighttimepay << setw(3) << right
			 << "$" << setw(7) << fixed << setprecision(2)<< right << employees[i]->overtimepay << setw(3) << right << "$" 
			 << setw(8) << fixed << setprecision(2) << right <<employees[i]->netpay << endl;

	}
}

/**********************************************************************
* Purpose: This function frees all memory allocated when creating 
*	 and appending to 2D array. 
*
* Precondition:
*     employees - filled, not null, 2D Employee array, passed by pointer
*	  employee_count - global count to iterate though 2D array. 
*
* Postcondition:
*      Modifies employee array, freeing memory and setting to nullptr.
*	   modifies employee_count, set to zero.
*
************************************************************************/
void FreeMemory(Employee *** employees)
{
	for (int i(0); i < employee_count; i++)
	{
		delete[] (*employees)[i]->fname;
		delete[] (*employees)[i]->lname;
		delete[] (*employees)[i]->social;
		delete[] (*employees)[i];
	}
	
	delete[] *employees; 
	employees = nullptr; 
	employee_count = 0; 
}
