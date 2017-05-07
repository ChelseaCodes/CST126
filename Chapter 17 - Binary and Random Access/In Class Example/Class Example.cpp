#include<iostream>
using std::cout;
using std::cin;
using std::endl; 

#include<fstream>
using std::ifstream;
using std::ofstream; 
using std::fstream; 
using std::ios; 

//troy got tired of squigglies and opened a whole different
//file for demonstrating reading / writing binary files
//random access ect. 

struct EMP
{
	char name[30]; // Use cString not string
	short int age;
};
const short int NUM_EMPLOYEES = 2;
void WriteToFile(EMP ray[]);
void ReadFromFile(EMP ray[]);

int main()
{
	EMP ray[NUM_EMPLOYEES];
	strcpy(ray[0].name, "Linda"); 
	ray[0].age = 45; 
	strcpy(ray[1].name, "Bob");
	ray[1].age = 47;


	//FillArrayFromKeyboard(ray);
	WriteToFile(ray);
	ReadFromFile(ray);
	//PrintArray(ray);
	for (int i(0); i < NUM_EMPLOYEES; i++)
	{
		cout << ray[i].name << " " << ray[i].age << endl; 
	}
	return 0;
}

void WriteToFile(EMP ray[])
{
	ofstream fout("binary.dat", ios::out | ios::binary);
	if (fout.is_open())
	{
		fout.write(reinterpret_cast <char *>(ray), sizeof(EMP) * NUM_EMPLOYEES);
		fout.close();
	}
	else
		cout << "File not opened" << endl;
}

void ReadFromFile(EMP ray[])
{
	ifstream fin("binary.dat", ios::in | ios::binary);
	if (fin.is_open())
	{
		fin.read(reinterpret_cast <char *>(ray), sizeof(EMP) * NUM_EMPLOYEES);
		cout << "Number of bytes read is: " << fin.gcount();
		fin.close();
	}
	else
		cout << "File not opened" << endl;
}


