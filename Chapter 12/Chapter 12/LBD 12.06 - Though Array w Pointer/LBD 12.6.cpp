#include<iostream>
using std::cout;
using std::endl; 

const int ROW = 4;
const int COL = 5;

int main()
{
	int numbers[ROW][COL] =				//two dimensional array already initialized
	{
		{0,1,2,3,4},
		{5,6,7,8,9},
		{10,11,12,13,14},
		{15,16,17,18,19}
	};
	int * ptr = &numbers[0][0];			//pointer to numbers 

	for (int i(0); i < ROW; i++)		//loops through the row
	{
		for (int j(0); j < COL; j++)	//loops through the cols
		{
			cout << *ptr << " "; 
			ptr++;
		}
		cout << endl; 
	}

	system("pause"); 
	return 0; 
}