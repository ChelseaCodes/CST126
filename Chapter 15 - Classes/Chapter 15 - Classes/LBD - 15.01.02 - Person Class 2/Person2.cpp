#include "Person2.h"
Person2::Person2()
{
	cout << "Person2 default c'tor" << endl;
}

Person2::Person2(int id, char gender) : m_ID(id), m_gender(gender)
{
	cout << "Person2 2 arg c'tor" << endl;
}

Person2::Person2(const Person2& copy) : m_ID(copy.m_ID), m_gender(copy.m_gender)
{
	cout << "Person2 copy c'tor" << endl;
}

Person2& Person2::operator=(const Person2& copy)
{
	cout << "Person2 op='s" << endl;
	if (this != &copy)
	{
		m_ID = copy.m_ID;
		m_gender = copy.m_gender;
	}

	return *this;
}

void Person2::SetGender(char gender)
{
	cout << "Setting gender" << endl;
	m_gender = gender;
}

void Person2::SetID(int id)
{
	cout << "Setting ID" << endl;
	m_ID = id;
}

void Person2::SetAge(int age)
{
	m_age = age; 
}

void Person2::SetShoeSize(int size)
{
	m_shoesize = size; 
}

char Person2::GetGender()
{
	return m_gender;
}

int Person2::GetID()
{
	return m_ID;
}

int Person2::GetAge()
{
	return m_age;
}

int Person2::GetShoeSize()
{
	return m_shoesize;
}

Person2::~Person2()
{
	cout << "Person2 d'tor" << endl;
}
