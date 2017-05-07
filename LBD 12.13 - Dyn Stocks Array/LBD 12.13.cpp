#include <iostream>
using std::cout; 
using std::cin; 
using std::endl;

#include<iomanip>
using std::setw;
using std::right; 

//functions 
void GetInput(char **& stocks, int & count); 
void Add(char **& stocks, char buff[], int & count);
void Sort(char **& stocks, int count); 
void Display(char **& stocks, int count);
void FreeStocks(char **& array, int & count); 

const int MAX(6); 

int main()
{
	char ** stocks = 0; 
	int count(0); 

	GetInput(stocks, count); 

	Sort(stocks, count);

	Display(stocks, count); 
	FreeStocks(stocks, count);

	return 0;
}

void GetInput(char **& stocks, int & count)
{
	bool again(false);
	char buff[MAX] = { '\0' }; 
	char input = '\0';

	cout << "You can enter as many stocks as you'd like\n" << endl; 
	do
	{
		again = false; 

		cout << "Please enter a Stock: "; 
		cin >> buff; 

		for (int i(0); i < strlen(buff); i++)
		{
			buff[i] = toupper(buff[i]); 
		}

		Add(stocks, buff, count);

		if (again == false)
		{
			cout << "would you like to enter another stock? (Y/N)";
			cin >> input; 
			cout << endl; 
			
			input = toupper(input); 

			if (input == 'Y')
				again = true;
			else
				cout << "Done entering data\n\nPrinting Stocks:" << endl; 
		}

	} while (again == true);


}

void Add(char **& stocks, char buff[], int & count)
{
	char ** temp = 0; 
	char * st = 0; 

	//copy over to temp, everything in stocks 
	temp = new char *[count + 1]; 
	for (int i(0); i < count; i++)
	{
		temp[i] = stocks[i];
	}

	temp[count] = new char[strlen(buff) + 1]; 
	strcpy(temp[count], buff); 

	count++; 

	delete[] stocks; 
	stocks = temp; 
}

void Sort(char **& stocks, int count)
{
	bool sorted(false); 
	char * temp = 0; 
	int tempcount(count); 
	int row(0);
	int pass(0); 

	while (pass < tempcount || sorted == false)
	{
		sorted = true; 
		for (int i(0); i < tempcount - 1; i++)
		{
			if (*stocks[i] > *stocks[i + 1])
			{
				sorted = false; 
				temp = stocks[i]; 
				stocks[i] = stocks[i + 1]; 
				stocks[i + 1] = temp; 
			}
		}
		pass++; 
	}
}

void Display(char **& stocks, int count)
{
	for (int i(0); i < count; i++)
	{
		cout << setw(10) << right << stocks[i] << endl; 
	}
	cout << endl; 
}

void FreeStocks(char **& array, int & count)
{
	//loop through array 
	for (int i(0); i < count; ++i)
	{
		delete[] array[i];	//free inside data 
	}
	delete[] array;	//delete array 
	count = 0;		//reset counter 
}