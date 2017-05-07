#include<iostream>
using std::cout;
using std::cin; 
using std::endl; 

//output a cString backwards, recursively
void Backwards(char * cStr); 

int main()
{
	char * ptrarray = "Supercalifragilisticexpialadotious"; 

	cout << "String to reverse: " << ptrarray << endl; 

	cout << "Reversed string: "; 
	Backwards(ptrarray);
	cout << endl; 

	system("pause"); 
	return 0; 
}

void Backwards(char * cStr)
{
	if (*cStr != '\0')
	{
		Backwards(cStr + 1);
		cout << *cStr;
	}
}