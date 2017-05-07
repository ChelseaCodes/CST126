#include<iostream>
using std::cout;
using std::cin;
using std::endl;


void StrGet(char *& src, char *& dest); 
char * StrCat(const char * src, char * dest);	//strcat by pointer 
void RefStrCat(char * src, char *& dest);		//strcat by ref

const int MAX_BUF(50);

int main()
{
	char * src1 = 0; 
	char * src2 = 0; 
	char * dest1 = 0; 
	char * dest2 = 0; 

	StrGet(src1, dest1); 
	dest1 = StrCat(src1, dest1);

	cout << "Finished string: " << dest1 << endl; 

	StrGet(src2, dest2); 
	RefStrCat(src2, dest2);

	cout << "Finished string: " << dest2 << endl; 

	system("pause");
	return 0;
}
void StrGet(char *& src, char *& dest)
{
	//Make sure dest string is 
	//ALWAYS large enough for the cat
	char s_buff[MAX_BUF] = { '\0' };
	char d_buff[MAX_BUF] = { '\0' }; 
	
	cout << "Welcome to StrCat\n" << "Enter source string: "; 
	cin >> s_buff; 
	cout << endl; 

	cout << "Enter destination string: ";
	cin >> d_buff; 

	src = new char[strlen(s_buff) + 1];
	strcpy(src, s_buff); 

	dest = new char[strlen(d_buff) + strlen(s_buff) + 1];
	strcpy(dest, d_buff);
}

char * StrCat(const char * src, char * dest)
{
	int rd(0);
	int wr(0); 

	//Taking the source string and concat it to destination 
	while (dest[rd] != '\0')
	{
		rd++;
	}
	while (src[wr] != '\0')
	{
		dest[rd] = src[wr];
		rd++;
		wr++;
	}
	dest[rd] = '\0';
	return dest;
}

void RefStrCat(char * src, char *& dest)
{
	int rd(0);
	int wr(0);

	//Taking the source string and concat it to destination 
	while (dest[rd] != '\0')
	{
		rd++;
	}
	while (src[wr] != '\0')
	{
		dest[rd] = src[wr];
		rd++;
		wr++;
	}
	dest[rd] = '\0';
}
