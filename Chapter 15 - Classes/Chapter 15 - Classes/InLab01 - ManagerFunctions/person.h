#ifndef Person_H
#define Person_H
#include <iostream>
using std::cout;
using std::endl; 

#include "string.h"
class Person
{
public:
	Person();
	Person(String name, int age);
	Person(const Person& copy); 
	Person& operator=(const Person& copy); 

	void Display() const; 

	~Person();
private:
	String m_name; 
	int m_age; 
};
#endif
