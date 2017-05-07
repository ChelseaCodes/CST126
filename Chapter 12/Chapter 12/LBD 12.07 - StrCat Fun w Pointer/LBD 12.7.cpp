#include<iostream>
using std::cout;
using std::cin; 
using std::endl; 

char * StrCat(char * src, char * dest); 

int main()
{
	//declarations of cstrings and their pointers. 
	char source[] = { "World" };
	char * src = source; 
	char destination[] = {"Hello, "};
	char * dest = destination; 

	/*cout << "Please enter destination string ";
	cin >> destination; 

	cout << "\nEnter source string "; 
	cin >> source; */

	StrCat(src, dest); 

	system("pause");
	return 0; 
}
/***********************************************
* Input: char * to source, char * to destination cstring
* 
* Output: pointer to the destination 
*
***********************************************/
char * StrCat(char * src, char * dest)
{
	//Taking the source string and concat it to destination 
	while(*dest != '\0')
	{
		dest++; 
	}

	while (*dest++ = *src++); 
	return dest; 
}