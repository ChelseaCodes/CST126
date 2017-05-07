#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h> 
#include <iostream>
using std::cout;
using std::endl;

#include "person.h"
#include "string.h"

void FunValue(String string);
void FunReference(String & string);
void FunPointer(String * string);
void FunConstRef(const String & string); 

void FunValue(Person person);
void FunReference(Person & person); 
void FunPointer(Person * person);
void FunConstRef(const Person & person); 

Person FunPerson(); 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	char * temp = "King Kai"; 

	/* 1. Instantiate 2 String objs. Calls default and 1 arg */
	String str0; 
	String str1(temp); 

	/* 2. Instantiate 2 Person objs. Calls default and 2 arg */
	Person p0; 
	Person p1(str1, 19); 

	/* 3. Pass String by val */
	String kitty("Kitty");
	FunValue(kitty);

	/* 4. Pass String by ref */
	FunReference(kitty);

	/* 5. Pass String by pointer */
	FunPointer(&kitty);

	/* 6. Pass String by const-ref */
	FunConstRef(kitty); 

	/* 7. Return Person obj from function */
	Person not_so_local_guy = FunPerson(); 

	/* 8. Pass Person by val */
	FunValue(not_so_local_guy);

	/* 9. Pass Person by ref */
	FunReference(not_so_local_guy);

	/* 10. Pass person by pointer */
	FunPointer(&not_so_local_guy);

	/* 11. Pass person by const-ref*/
	FunConstRef(not_so_local_guy); 


	return 0; 
}

void FunValue(String string)
{
	cout << "Passed string '";
	string.Display();
	cout << "' by value" << endl;
}

void FunReference(String & string)
{
	cout << "Passed string '";
	string.Display();
	cout << "' by reference" << endl; 
}

void FunPointer(String* string)
{
	cout << "Passed string '";
	string->Display();
	cout << "' by pointer" << endl;
}

void FunConstRef(const String& string)
{
	cout << "Passed string '";
	string.Display();
	cout << "' by const-ref" << endl;
}

void FunValue(Person person)
{
	cout << "Passed person '";
	person.Display();
	cout << "' by value" << endl;
}

void FunReference(Person & person)
{
	cout << "Passed person '";
	person.Display();
	cout << "' by reference" << endl; 
}

void FunPointer(Person * person)
{
	cout << "Passed person '";
	person->Display();
	cout << "' by pointer" << endl;
}

void FunConstRef(const Person & person)
{
	cout << "Passed person '";
	person.Display();
	cout << "' by const-ref" << endl;
}

Person FunPerson()
{
	String dave("Dave");
	Person local_guy(dave, 39);
	return local_guy; 
}
