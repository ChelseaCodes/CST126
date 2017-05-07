#include "person.h"

Person::Person() : m_name(""), m_age(18)
{
	cout << "in Person default c'tor" << endl;
}

Person::Person(String name, int age) : m_name(name), m_age(age)
{
	cout << "in Person 2 arg c'tor for ";
	m_name.Display();
	cout << " of age " << m_age << endl;
}

Person::Person(const Person& copy) : m_name(copy.m_name), m_age(copy.m_age)
{
	cout << "in Person copy c'tor for ";
	m_name.Display();
	cout << endl; 
}

Person& Person::operator=(const Person& copy)
{
	cout << "in Person op =" << endl; 
	if(this != & copy)
	{
		m_name = copy.m_name;
		m_age = copy.m_age; 
	}
	return *this; 
}

void Person::Display() const
{
	m_name.Display(); 
	cout << " of age " << m_age;
}

Person::~Person()
{
	cout << "in Person d'tor for ";
	Display();  
	cout << endl;
}

