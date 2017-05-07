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

#include "Person3.h"

void Sample(Person3 p3);

int main()
{
	//C
	cout << "invoking default c'tor p0" << endl;
	Person3 p0; 

	//E & G
	cout << "testing age/shoe c'tor p1" << endl;
	Person3 p1(18); 

	//e
	cout << "testing copy c'tor\n" << endl;
	Person3 s2(323, 'M');
	Person3 s3(s2);

	//f
	cout << "testing op= p0 = p1\n" << endl;
	p0 = p1;

	cout << "testing getters" << endl
		<< "getting p0 id and gender: " << p0.GetID() << " " << p0.GetGender();
	cout << endl;
	cout << "getting p0 age and shoe size" << p0.GetAge() << " " << p0.GetShoeSize();
	cout << endl;

	cout << "testing setters" << endl
		<< "setting p3 id to 0, and char to F" << endl;
	s3.SetGender('F');
	s3.SetID(0);
	cout << "setting p3 age to 12, and shoe size to 14" << endl; 
	s3.SetAge(12);
	s3.SetShoeSize(14); 
	cout << endl; 
	s3.Display();

	//i
	cout << "Creating Array " << endl; 
	Person3 array[5]; 

	//j
	Sample(s3); 

	//k - copy c'tor is called. 
	Person3 test = p1; 
	Person3 test2(p1); 

	//system("pause");
	return 0;
}

void Sample(Person3 p3)
{
	p3.Display(); 
}
