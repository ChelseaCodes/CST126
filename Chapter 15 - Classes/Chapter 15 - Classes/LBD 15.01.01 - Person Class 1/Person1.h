/************************************************************************
* Class: Person
*
*************************************************************************/

#ifndef PERSON_H
#define PERSON_H
#include<iostream>
using std::cout;
using std::endl;

class Person
{
	public:
		Person();
		Person(int id, char gender); 
		Person(const Person& copy); 
		Person& operator=(const Person& copy); 

		void SetID(int id);
		void SetGender(char gender); 
		int GetID();
		char GetGender(); 

		~Person();

	private:
		int m_ID; 
		char m_gender; 
};

Person::Person()
{
	cout << "Person default c'tor" << endl; 
}

Person::Person(int id, char gender) : m_ID(id), m_gender(gender) 
{
	cout << "Person 2 arg c'tor" << endl; 
}

Person::Person(const Person& copy) : m_ID(copy.m_ID), m_gender(copy.m_gender)
{
	cout << "Person copy c'tor" << endl; 
}

Person& Person::operator=(const Person& copy)
{
	cout << "Person op='s" << endl; 
	if (this != &copy)
	{
		m_ID = copy.m_ID; 
		m_gender = copy.m_gender; 
	}

	return *this; 
}

void Person::SetGender(char gender) 
{
	cout << "Setting gender" << endl;
	m_gender = gender; 
}

void Person::SetID(int id)
{
	cout << "Setting ID" << endl; 
	m_ID = id; 
}

char Person::GetGender()
{
	return m_gender;
}

int Person::GetID()
{
	return m_ID; 
}

Person::~Person()
{
	cout << "Person d'tor" << endl;
}
#endif



