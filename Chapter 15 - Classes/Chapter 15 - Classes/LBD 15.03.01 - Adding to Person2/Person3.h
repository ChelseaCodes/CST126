/************************************************************************
* Class: Person
*
*************************************************************************/

#ifndef PERSON3_H
#define PERSON3_H
#include<iostream>
using std::cout;
using std::endl;

class Person3
{
public:
	Person3();
	Person3(int id, char gender);
	Person3(int age, int shoesize = 8);
	Person3(const Person3& copy);
	Person3& operator=(const Person3& copy);

	void SetID(int id);
	void SetGender(char gender);
	void SetAge(int age);
	void SetShoeSize(int size);
	int GetID();
	char GetGender();
	int GetAge();
	int GetShoeSize();

	void Display();

	~Person3();

private:
	int m_ID;
	char m_gender;
	int m_age;
	int m_shoesize;
};
#endif
