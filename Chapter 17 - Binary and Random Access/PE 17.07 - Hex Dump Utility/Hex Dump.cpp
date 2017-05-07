/*************************************************************
* Author:		Chelsea Christison
* Filename:		Hex Dump.cpp
* Date Created:	02/17/2017
* Modifications:
*	2.19.2017 - finished writing
*************************************************************
*
* Lab/Assignment: PE 17.07 - Hex Dump Utility
*
* Overview:
*	 This program reads a file in binary, and outputs into
*	a text file, a Hex Dump of the file. 
*
* Parameters:
*	Program takes in path to file from console:
*	C:\Users\Chelsea Christison\OneDrive\Documents\Binary.docx
*
* Output:
*	The output of this program will be the formatted output
*	of Hex Dump into "Hex Dump.txt": 

*	Address                        Hex Dump                                ASCII
*	-------  -------------------------------------------------  ----------------
*	0000000  48 65 6c 6c 6f 20 68 6f   77 20 69 73 20 6c 69 66   Hello how is lif
*	0000010  65 3f 20 0d 0a 41 72 65   20 79 6f 75 20 65 6e 6a   e? ..Are you enj
*********************************************************************************/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<iomanip>
using std::setw;
using std::left;
using std::fixed;
using std::setprecision;
using std::hex;
using std::setfill; 
using std::right; 

#include<fstream>
using std::ifstream;
using std::ofstream;
using std::ios;

void FillDump(); 
void GetFile(char file_name[]);

int main()
{
	FillDump(); 

	return 0; 
}

/**********************************************************************
* Purpose: This function creates the hex dump. 
*
* Precondition:
*     none 
*
* Postcondition:
*      modifies HexDump.txt storing hex dump
************************************************************************/
void FillDump()
{
	char file_name[250];
	GetFile(file_name); 

	ifstream fin(file_name, ios::in | ios::binary);
	ofstream fout("HexDump.txt");
	unsigned char buffer[250];		//buffer for binary read
	long int address(0);			//address for hex dump
	long int bytes_read(0);			//bytes read
	long int bytes_written(0);		//count for bytes written
	int buffer_index(0);			//buffer index
	int sixteen_bytes(16);


	if (fin.is_open() && fout.is_open())
	{
		fout << setw(31) << left << "Address"
			<< setw(30) << left << "Hex Dump"
			<< setw(15) << right << "ASCII" << endl;
		fout << "-------  -------------------------------------------------  ----------------" << endl;

		while (!fin.eof())
		{
			fin.read(reinterpret_cast<char *>(buffer), 16); //second param specifies number of bytes - 16 
			bytes_read = fin.gcount();						//store number of bytes read - always 16

			//1. write the address
			fout << hex << setw(7) << setfill('0') << address << "  ";
			address += 16;

			//2. write the data inside buffer- looping for count 
			//formatted: 2 per, fill w/ 0, output hex
			bytes_written = 0;
			for (buffer_index = 0; buffer_index < sixteen_bytes; buffer_index++)
			{
				//if else statement allows writing pairs of hex bytes w/o
				//weird spacing issues
				if (bytes_written <= bytes_read)
				{
					fout << hex << setw(2) << setfill('0') << (int)buffer[buffer_index];
					if (bytes_written == 7)
						fout << "  ";
				}
				else
					fout << "  ";

				fout << " ";
				bytes_written += 1;
			}

			//3. write translated version of bytes - if able
			fout << "  ";
			bytes_written = 0;
			for (buffer_index = 0; buffer_index < sixteen_bytes; buffer_index++)
			{
				if (bytes_written <= bytes_read)
				{
					//write '.' if byte is beyond writable characters
					if (buffer[buffer_index] < 32 || buffer[buffer_index] > 126)
					{
						fout << '.';
					}
					else
						fout << buffer[buffer_index];
				}
			}
			fout << endl;
		}
		fout.close();
		fin.close();
	}
	else
		cout << "Could not open file" << endl; 
}

/**********************************************************************
* Purpose: This function gets file path from console 
*
* Precondition:
*     file_name - empty before pass
*
* Postcondition:
*      modifies the file_name
************************************************************************/
void GetFile(char file_name[])
{
	cout << "Please enter the file to open:"; 
	cin.getline(file_name, 250); 
}
