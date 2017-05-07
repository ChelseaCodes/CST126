/*************************************************************
* Author:		Chelsea Christison
* Filename:		main.cpp
* Date Created:	02.22.2017

* Lab/Assignment: LBD 15.01.01 - person class
*
* Overview:
*	This program will create a person class - in the same
*
************************************************************/
#include<iostream>
using std::cout;
using std::cin;

#include "Person2.h"

int main()
{
	cout << "testing default c'tor\n" << endl;
	Person2 s0;

	cout << "testing 2 arg c'tor\n" << endl;
	Person2 s1(123, 'F');


	cout << "testing copy c'tor\n" << endl;
	Person2 s2(323, 'M');
	Person2 s3(s2);

	cout << "testing op=\n" << endl;
	s0 = s1;

	cout << "testing getters" << endl
		<< "getting s0 id and age: " << s0.GetID() << " " << s0.GetGender();
	cout << endl;

	cout << "testing setters" << endl
		<< "setting s3 id to 0, and char to F" << endl;
	s3.SetGender('F');
	s3.SetID(0);

	cout << "\nNew Gender/ID: " << s3.GetGender() << " " << s3.GetID() << endl;

	system("pause");
	return 0;
}

