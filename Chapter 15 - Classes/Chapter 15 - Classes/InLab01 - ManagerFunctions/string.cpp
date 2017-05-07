#include "string.h"

String::String() : m_string(nullptr)
{
	cout << "in String default c'tor" << endl; 
}

String::String(char * s)
{
	m_string = new char[strlen(s) + 1];
	strcpy(m_string, s); 

	cout << "in String 1 arg c'tor for " << s
		<< endl; 
}

String::String(const String& copy)
{
	m_string = new char[strlen(copy.m_string) + 1];
	strcpy(m_string, copy.m_string);

	cout << "in String copy c'tor for "
	     << m_string << endl; 
}

String& String::operator=(const String& copy)
{
	cout << "in String op = " << endl; 
	if(this != &copy)
	{
		delete[] m_string; 
		if(strlen(copy.m_string) == 0)
		{
			m_string = new char[1]; 
			m_string[0] = '\0';
		}
		else
		{
			m_string = new char[strlen(copy.m_string) + 1];
			strcpy(m_string, copy.m_string);
		}
	}
	return *this; 
}

char* String::GetString() const
{
	cout << "String getter" << endl; 
	return m_string; 
}

void String::Display() const
{
	cout << m_string; 
}

String::~String()
{
	cout << "in String d'tor"<< endl; 
	delete[] m_string;
}
