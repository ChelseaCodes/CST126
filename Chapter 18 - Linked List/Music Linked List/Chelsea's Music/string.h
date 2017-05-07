/************************************************************************
* Class: String
*
* Purpose:
*	This class simulates the predefined string class
*
* Manager functions:
* 	String()
*	String(char * cstr); 
*	String(const String& copy)
*	String& operator=(const String& rs)
*
* Methods:
*	int Length()
*		returns the length of the String
*	operator==(const String& ls, const String& rs)
*	operator!=(const String& ls, const String& rs)
*	operator+=(String &ls, const String& rs)
*	operator+(String &ls, const String& rs)
*	operator<=(const String& ls, const String& rs)
*	operator>=(const String& ls, const String& rs)
*	operator<(const String& ls, const String& rs)
*	operator>(const String& ls, const String& rs)
*	ostream& operator<<(ostream& os, String data)
*	static char * convert_lower(char * convert)
*		converts passed ptr to lowercase
*
*************************************************************************/
#ifndef String_H
#define String_H

#include <iostream>
using std::cout;
using std::cin; 
using std::endl; 

#include <ostream>
using std::ostream;
using std::istream;

class String
{
public:
	String();
	String(char * cstr); 
	String(const String& copy); 
	String& operator=(const String& rs); 

	int Length() const; 
	char * getCharPtr() const; 

	friend bool operator==(const String& ls, const String& rs); 
	friend bool operator!=(const String& ls, const String& rs); 
	friend String& operator+=(String &ls, const String& rs);
	friend String& operator+(String &ls, const String& rs); 
	friend bool operator<=(const String& ls, const String& rs);
	friend bool operator>=(const String& ls, const String& rs);
	friend bool operator<(const String& ls, const String& rs);
	friend bool operator>(const String& ls, const String& rs);
	friend ostream& operator<<(ostream& os, String data);

	~String();
	static char * convert_lower(char * convert);
private:
	char * m_str; 
	
};

#endif