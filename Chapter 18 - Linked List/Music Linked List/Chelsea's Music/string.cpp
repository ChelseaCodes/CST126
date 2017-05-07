/*************************************************************
* Author:		Chelsea Christison
* Filename:		string.cpp
* Date Created:	3.10.2017
* Modifications:	
*	3.15 -	added convert_lower 
**************************************************************/
#include "string.h"
#include <cstring>

//c'tor
String::String()
{
	m_str = new char[1];
	m_str[0] = '\0';
}

//c'tor one arg
String::String(char* cstr) 
{
	if(cstr != nullptr)
	{
		m_str = new char[strlen(cstr) + 1];
		strcpy(m_str, cstr);
	}
}

//copy c'tor
String::String(const String& copy)
{
	m_str = new char[strlen(copy.m_str) + 1];
	strcpy(m_str, copy.m_str); 
}

//op=
String& String::operator=(const String& rs)
{
	if(this != &rs)
	{
		delete[] m_str;
		m_str = new char[strlen(rs.m_str) + 1];
		strcpy(m_str, rs.m_str);
	}

	return *this; 
}

//returns length of String obj
int String::Length() const { return strlen(m_str); }

//returns char ptr
char* String::getCharPtr() const { return m_str; }

//d'tor
String::~String() { delete[] m_str; }

/*************************************************************
*	Purpose:
*		converts passed char pointer to all lowercase.
*		used for string comparison disregarding case
*		
**************************************************************/
char* String::convert_lower(char* convert)
{
	int i(0);
	char * convert_buff = new char[strlen(convert) + 1];
	while(convert[i])
	{
		convert_buff[i] = tolower(convert[i]);
		i++;
	}
	convert_buff[i] = '\0';
	return convert_buff; 
}

/*************************************************************
*	Purpose:
*		Overloaded conversion operator==.
*		compares two string objs, converts case to lowercase
*		before comparison.
*	Added Functionality:
*		Utilizes strstr to search if string contains part of
*		the other. If char * partial_string isn't null, 
*		then the string does. 
*		This is how user can input PART of a song title
*		and it will still find the song they are looking for. *		
*
**************************************************************/
bool operator==(const String& ls, const String& rs)
{
	char * temp = ls.convert_lower(ls.getCharPtr());

	char * partial_string = strstr(temp, rs.getCharPtr());

	bool equal = (partial_string != nullptr) || (stricmp(ls.m_str, rs.m_str) == 0);

	delete[] temp;
	return equal;
}

/*************************************************************
*	Purpose:
*		Overloaded comparison operator!=
*		calls String class op==, returns inverse
*
**************************************************************/
bool operator!=(const String& ls, const String& rs)
{
	return	!(ls == rs);
}

/*************************************************************
*	Purpose:
*		Overloaded operator +=, concatinates two String objs
*		and returns modified string.
*
**************************************************************/
String& operator+=(String& ls, const String& rs)
{
	int length = strlen(ls.m_str) + strlen(rs.m_str); 
	String temp = ls; 

	delete[] ls.m_str; 

	ls.m_str = new char[length + 1]; 
	strcpy(ls.m_str, temp.m_str);
	strcat(ls.m_str, rs.m_str);

	return ls;
}

/*************************************************************
*	Purpose:
*		Overloaded op+, calls String class op+=
*
**************************************************************/
String& operator+(String& ls, const String& rs)
{
	return ls += rs; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator>=, uses string compare
*		and returns if lhs is larger than or equal to rhs
*
**************************************************************/
bool operator>=(const String& ls, const String& rs)
{
	return (stricmp(ls.m_str, rs.m_str) >= 0);
}

/*************************************************************
*	Purpose:
*		Overloaded operator<, uses string compare
*		and returns if lhs is less than rhs
*
**************************************************************/
bool operator<(const String & ls, const String & rs)
{
	return (stricmp(ls.m_str, rs.m_str) < 0);
}

/*************************************************************
*	Purpose:
*		Overloaded operator>, uses string compare
*		and returns if lhs is larger than rhs
*
**************************************************************/
bool operator>(const String & ls, const String & rs)
{
	return (stricmp(ls.m_str, rs.m_str) > 0);
}

/*************************************************************
*	Purpose:
*		Overloaded operator<< for output stream. 
*		Used for passing string to output. 
*
**************************************************************/
ostream& operator<<(ostream& os, String data)
{
	os << data.m_str; 
	return os; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator<=, uses string compare 
*		and returns if ls is less than or equal to rs
*
**************************************************************/
bool operator<=(const String& ls, const String& rs)
{
	return (stricmp(ls.m_str, rs.m_str) <= 0);
}
