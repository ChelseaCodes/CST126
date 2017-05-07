#ifndef String_H
#define String_H
#include <iostream>
using std::cout;
using std::endl; 

class String
{
public:
	String();
	String(char * s); 
	String(const String& copy);
	String& operator=(const String& copy); 

	char * GetString() const; 

	void Display() const;

	~String(); 

private:
	char * m_string; 
};
#endif