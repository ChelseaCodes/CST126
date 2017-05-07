#include <iostream>
using std::endl;
using std::cout; 

#include<iomanip>
using std::setw; 
using std::right; 


int main()
{
	int numbers[5] = { 99, 34, 1, 88, 100 };	//array of numbers
	int * int_ptr = numbers;					//pointer to numbers 
	int ** int_ptr_ptr = &int_ptr;				// pointer to pointer to numbers 

	//print address...
	//of array using array name
	cout << "Address of array: " << setw(30) << right << &numbers << endl; 

	//of array using intptr
	cout << "Address of array using int_ptr: " <<  setw(16) << right << int_ptr << endl;

	//of array using intptrptr
	cout << "Address of array using int_ptr_ptr: " << setw(12) <<  *int_ptr_ptr << endl;

	//of intptr using intptr
	cout << "Address of int_ptr: " << setw(28) << &int_ptr << endl;

	//of intptr using intptrptr
	cout << "Address of int_ptr using int_ptr_ptr: " << setw(10) << int_ptr_ptr << endl;

	//print first element using intptr
	cout << "First element of array w/ int_ptr: " << setw(13) << *int_ptr << endl;

	//print first element using intptrptr 
	cout << "First element of array w/ int_ptr_ptr: " << setw(9) << **int_ptr_ptr << endl;

	//change intptr to second element of array
	cout << "\nChanging int_ptr to the second element\n" << endl;
	int_ptr = &numbers[1]; 

	//print second element using intptr
	cout << "Second element w/ int_ptr: " << setw(21) << *int_ptr << endl;

	//using intptrptr
	cout << "Second element w/ int_ptr_ptr: " << setw(17) << **int_ptr_ptr << endl;

	//change second element to 101 using intptr
	cout << "Changing second element of array: ";
	*int_ptr = 101;
	cout << setw(14) << *int_ptr << endl;

	//change to 102 using intptrptr
	cout << "Changing second element of array: ";
	**int_ptr_ptr = 102; 
	cout << setw(14) << **int_ptr_ptr << endl;

	//change the address of intptr to point to third element using intptrptr
	cout << "\nChanging int_ptr_ptr to third element\n\n"; 
	*int_ptr_ptr = &numbers[2]; 
	//cout << setw(13) << *int_ptr_ptr << endl;

	//change third element to -1 using intptr
	cout << "Changing third element w/ int_ptr: "; 
	*int_ptr = -1;
	cout << setw(13) << *int_ptr << endl;

	//change to -2 using intptrptr 
	cout << "Changing third element w/ int_ptr_ptr: "; 
	**int_ptr_ptr = -2; 
	cout << setw(9) << **int_ptr_ptr << "\n" << endl; 

	//print the contents of array to verify
	for (int i(0); i < 5; i++)
	{
		cout << numbers[i] << ", "; 
	}

	system("pause"); 
	return 0; 
}