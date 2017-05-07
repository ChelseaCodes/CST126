#include "Person3.h"
Person3::Person3()
{
	cout << "Person2 default c'tor" << endl;
}

Person3::Person3(int id, char gender) : m_ID(id), m_gender(gender), m_age(0), m_shoesize(0)
{
	cout << "ID/Gender c'tor" << endl;
}

Person3::Person3(int age, int shoesize):m_ID(0), m_gender('\0'), m_age(0), m_shoesize(shoesize)
{
	cout << "Age/Shoe c'tor" << endl; 
}

Person3::Person3(const Person3& copy) : m_ID(copy.m_ID), m_gender(copy.m_gender),
		m_age(copy.m_age), m_shoesize(copy.m_shoesize)
{
	cout << "Person3 copy c'tor" << endl;
}

Person3& Person3::operator=(const Person3& copy)
{
	cout << "Person3 op='s" << endl;
	if (this != &copy)
	{
		m_ID = copy.m_ID;
		m_gender = copy.m_gender;
		m_age = copy.m_age; 
		m_shoesize = copy.m_shoesize; 
	}

	return *this;
}

void Person3::SetGender(char gender)
{
	cout << "Setting gender" << endl;
	m_gender = gender;
}

void Person3::SetID(int id)
{
	cout << "Setting ID" << endl;
	m_ID = id;
}

void Person3::SetAge(int age)
{
	cout << "Setting age" << endl;
	m_age = age; 
}

void Person3::SetShoeSize(int size)
{
	cout << "Setting ShoeSize " << endl; 
	m_shoesize = size; 
}

char Person3::GetGender()
{
	return m_gender;
}

int Person3::GetID()
{
	return m_ID;
}

int Person3::GetAge()
{
	return m_age;
}

int Person3::GetShoeSize()
{
	return m_shoesize;
}

void Person3::Display()
{
	cout << "ID: " << m_ID << "\nGender: " << m_gender
		 << "\nAge: " << m_age << "\nShoe size: " << m_shoesize
		 << endl; 
}

Person3::~Person3()
{
	cout << "Person3 d'tor" << endl;
}
