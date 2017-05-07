/************************************************************************
* File: Chap_13_Debugging.cpp
*
* General Instructions: Complete each step before proceeding to the
* next.
*
* Debugging Exercise 1
*
* 1) Take a few minutes and review the various UDT's provided in the 
*    code below.
* 2) Create Breakpoint 1 and Breakpoint 2 where indicated.
* 3) Run the program using the Start Debugging option to Breakpoint 1. 
* 4) Add the variables student_pay, student_hire_date, and summer_hire 
*    to your Watch window.
* 5) Briefly examine the Value and the Type associated with each of the
*    variables.
* 6) Continue running your program to Breakpoint 2.
* 7) Inspect the contents of the variable summer_hire. Make it a point 
*    to open up the various members of the structure within the watch 
*    window (i.e., click on the '+' symbol). Use this feature often to 
*    inspect the contents of your UDT variables.
* 8) Stop Debugging.
* 9) Disable Breakpoints 1 and 2.
* 10) Execute your program using the Start Without Debugging option.
* 11) Notice there is a problem with the output for the year. Fix that
*     problem by assigning the current year to the necessary field via
*     the variable summer_hire.
* 12) Execute and verify your results.
* 13) Inspect the output generated by displaying the value associated
*     with the grade. Notice that it is not very self-documenting.
* 14) Fix the output by using the PayGradeText ragged array.
* 15) Execute and verify your results.
*
* Debugging Exercise 2
*
* 1) Uncomment the following line of code located within the function
*    main:
*       // EditInfo( summer_hire );
* 2) Set Breakpoint 3 where indicated in the code. 
* 3) Within the function EditInfo, add the necessary line of code 
*    to change the value of the id to 99 and the first name to "Ward".
*    Do not make any modifications to the function signature at this
*    time.
* 4) Within the same function, modify the cout statement to also 
*    display the employee last name and hire date (i.e., mm/dd/yyyy).
* 5) Run the program using the Start Debugging option to Breakpoint 3.
* 6) Add the id and fname data members to your Watch window.  
* 7) Step Over the call to EditInfo and notice the results of 
*    the changes you made in the function. Verify that the results
*    produced by the function appear in the console window. Notice that
*    the values return to their original state when the function ends.
* 8) Stop Debugging.
* 9) Modify the function EditInfo again so it receives the Employee by
*    reference.
* 10) Run the program using the Start Debugging option to Breakpoint 3.
* 11) Step Over the function call to EditInfo and notice the results of 
*     the changes made within the function to the data members.
* 12) Stop Debugging.
* 13) Modify the function EditInfo so it receives an Employee by 
*     pointer.
* 14) Update the necessary statements within the function to use 
*     pointer notation to access the data members. 
* 15) Make sure to change the corresponding calling statement to pass
*     in the address of the variable.
* 16) Run the program using the Start Debugging option to Breakpoint 3.
* 17) Step Over the function call to EditInfo and notice the results
*     of the changes made within the function remain even after the
*     function ends.
* 18) Stop Debugging and remove Breakpoint 3.
*
* Debugging Exercise 3
*
* 1) Uncomment the following lines:
*      // Building b1, b2;
*      // b1.security_code = new char[(strlen( "Classified" ) + 1)];
*      // strcpy( b1.security_code, "Classified" );	
*      // b1.location = 011;
*      // b2 = b1;			// Shallow copy
*      // cout << "\n\nBuilding b1 Security Code: " << b1.security_code 
*      //		<< "  B1 location: " << b1.location; 
*      // cout << "\nBuilding b2 Security Code: " << b2.security_code 
*      //	    << "  B2 location: " << b2.location << endl;
* 2) With all Breakpoints removed, run the program using the Start
*    Debugging option and notice the memory leak being reported in 
*    your Output window.
* 3) Uncomment the following lines:
*      //delete [] b1.security_code;	
*      //delete [] b2.security_code;	
* 4) Create Breakpoint 4.
* 5) Run your program to Breakpoint 4. 
* 6) Step Over each of the next two lines.  Notice the program 
*    crashes on the second delete statement because you are attempting 
*    to delete memory that has already been deallocated in the previous
*    line. This happens because of the shallow copy made during the 
*    assignment of b1 to b2.
* 7) Comment out the line:  b2 = b1;
* 8) Add all the necessary lines of code to perform a deep copy by 
*    individually assigning all the data members in the variable 
*    b1 to b2. 
* 9) Build and execute your code.  
* 10) Make sure there are no memory leaks being reported and that your 
*     program does not crash.
*
***********************************************************************/
#define _CRT_SECURE_NO_DEPRECATE
#define _CRTDBG_MAP_ALLOC

#include <iostream>
using std::cout;
using std::endl;

#include <cstring>
#include <crtdbg.h>

enum PayGrade {	FULL, PART, INT };

const char * PayGradeText[] =
{  
	"Full-time",
    "Part-time",
    "Intern"
};

union PayType
{
    int	   salary;
    double hourly_wage;
    double intern_wage;
};

struct Date
{
	short month;
	short day;
	short year; 
};

struct Employee
{
    int   id;
    char  fname[25];
    char  lname[25];
    char  gender;
    PayGrade grade;
    Date  start_date;
};

struct Building
{	
    char * security_code;
	int location;
};

void EditInfo( Employee * e );

int main()
{
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF || _CRTDBG_LEAK_CHECK_DF );

    PayType student_pay;
    student_pay.intern_wage = 28000;

	Date student_hire_date;
	student_hire_date.month = 6;
	student_hire_date.day = 15;
	student_hire_date.year = 2017;

    Employee summer_hire;

    // Breakpoint 1
    // Put a breakpoint on the following line
    summer_hire.id = 1019;
    strcpy( summer_hire.fname, "Barbara" );
    strcpy( summer_hire.lname, "Cleaver" );
    summer_hire.gender = 'F';
    summer_hire.grade = INT;
	summer_hire.start_date = student_hire_date;

    // Breakpoint 2
    // Put a breakpoint on the following line
    cout << "\n Here is the summer intern:"
         << "\n\tID:  " << summer_hire.id
         << "\t NAME: " << summer_hire.fname
         << " " << summer_hire.lname
         << "\n\tGENDER: " << summer_hire.gender
         << "\t GRADE: " << PayGradeText[summer_hire.grade]
         << "\t START DATE: " << summer_hire.start_date.month << "/"
                              << summer_hire.start_date.day << "/"
                              << summer_hire.start_date.year << endl;

    // Breakpoint 3
    // Put a breakpoint on the following line
    EditInfo( &summer_hire );

     //Code for Debugging Exercise 3
     Building b1, b2;
     b1.security_code = new char[(strlen( "Classified" ) + 1)];
     strcpy( b1.security_code, "Classified" );
     b1.location = 011;

	 b2 = b1;
	 b2.location = b1.location;
	 b2.security_code = new char[strlen(b1.security_code) + 1];
	 strcpy(b2.security_code, b1.security_code);

     cout << "\n\nBuilding b1 Security Code: " << b1.security_code
          << "  B1 location: " << b1.location;
	 cout << "\nBuilding b2 Security Code: " << b2.security_code
		  << "  B2 location: " << b2.location << endl;

     // Breakpoint 4
     // Put a breakpoint on the following line
     delete[]  b1.security_code;
     delete[]  b2.security_code;

	 system("pause");
	 return 0;
}

void EditInfo( Employee * e )
{	
    cout << "\n\n ** Inside the EditInfo function! **";
    cout << "\nEmployee id: " << e->id 
         << "\nFirst name: "  << e->fname
		 << "\nLast name: "   << e->lname
		 << "\nHire date: " << e->start_date.month << "/"
							<< e->start_date.day << "/"
							<< e->start_date.year
							<< endl;

	e->id = 99; 
	strcpy(e->fname, "Ward"); 

    cout << "\n ** Leaving the EditInfo function! **\n";
}