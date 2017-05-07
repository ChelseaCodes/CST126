#include<iostream>
using std::cout;
using std::endl;

#include<fstream>
using std::ifstream;
using std::ofstream;
using std::ios; 



int main()
{
	/*ofstream append_mode("my data file.docx", ios::out | ios::app | ios::binary); 

	if (append_mode.is_open())
	{
		append_mode.close(); 
	}*/

	ofstream output_mode("my data file.docx", ios::out | ios::binary);
	if (output_mode.is_open())
	{
		output_mode.close(); 
	}


	return 0; 
}