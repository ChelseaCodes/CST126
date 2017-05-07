#define _CRTDBG_MAP_ALLOC
#include<iostream>
using std::cout;
using std::cin; 
using std::endl;

#include<iomanip>
using std::setw;
using std::left; 
using std::setprecision; 

#include<crtdbg.h>

int GetStud(); 
int ** FinalScores(int stud_count); 
void Display(int ** finals_array, int stud_count); 
void MemClean(int **& finals_array, int & stud_count); 

int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	int stud_count = GetStud(); 

	int ** finals_array =
		FinalScores(stud_count); 

	Display(finals_array, stud_count); 

	MemClean(finals_array, stud_count); 
	
	system("pause");
	return 0; 
}
int GetStud()
{
	int count(0); 

	cout << "How many students: "; 
	cin >> count; 
	cout << endl; 

	return count; 
}

int ** FinalScores(int stud_count)
{
	int ** Finals = new int *[stud_count]; 
	int buff; 

	for (int i(0); i < stud_count; ++i)
	{
		cout << "Enter score " << i + 1 << ": "; 
		cin >> buff; 

		Finals[i] = new int[sizeof(buff)]; 
		*Finals[i] = buff; 

	}

	return Finals;
}

void Display(int ** finals_array, int stud_count)
{
	float average(0.0); 
	float total(0.0);

	cout << setw(10) << left << "Student #"
		<< setw(10) << left << "Final Score\n";

	for (int i(0); i < stud_count; ++i)
	{
		cout << setw(10) << left << i + 1
			<< setw(10) << left << *finals_array[i]
			<< endl; 
		
		total = total + *finals_array[i]; 
	}
	average = total / stud_count; 

	cout << "Average score: " << setprecision(2) << average;
}

void MemClean(int **& finals_array, int & stud_count)
{
	for (int i(0); i < stud_count; ++i)
	{
		delete[] finals_array[i]; 
	}
	delete[]  finals_array;

}
