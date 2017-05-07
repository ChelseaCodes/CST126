#include<iostream>
using std::cout; 
using std::endl; 

int cCharChar(char * cStr, char targ);

int main()
{
	char test[] = "How many a's are appearing hear"; 
	char * cStr = test; 

	int a_count = cCharChar(cStr, 'z');

	cout << "cString:\n" << test << "\nhas " << a_count << " a's in it."
		<< endl; 

	return 0; 
}

int cCharChar(char * cStr, char targ)
{
	int t_count(0);

	for (int i(0); i < strlen(cStr); ++i)
	{
		if (cStr[i] == targ)
			t_count++; 
	}

	return t_count;	
}