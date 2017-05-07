/************************************************************************
* Class: Person
*
*************************************************************************/

#ifndef PERSON2_H
#define PERSON2_H
#include<iostream>
using std::cout;
using std::endl;

class Person2
{
public:
	Person2();
	Person2(int id, char gender);
	Person2(const Person2& copy);
	Person2& operator=(const Person2& copy);

	void SetID(int id);
	void SetGender(char gender);
	void SetAge(int age);
	void SetShoeSize(int size);
	int GetID();
	char GetGender();
	int GetAge();
	int GetShoeSize();

	~Person2();
private:
	int m_ID;
	char m_gender;
	int m_age;
	int m_shoesize; 
};
#endif
