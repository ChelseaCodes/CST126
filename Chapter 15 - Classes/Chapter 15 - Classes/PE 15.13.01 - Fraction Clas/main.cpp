/*************************************************************
*
* Lab/Assignment: PE 15.01 - Fraction Class
*
* Overview:
*	This program tests the Fraction Class functionality
*	ensuring reducing and computations are accurate. 
* Input:
*	The input is nothing. All variables are created in Test
*	functions.
*
* Output:
*	The output of this program will be the results of various 
*	computations with fractions, using a mix of negative, and 
*	whole number fractions. 
*
************************************************************/
#include<iostream>
using std::cout;
using std::endl; 
#include"Fraction.h"
void TestAdd(); 
void TestSubtract();
void TestMultiply();
void TestDivide(); 
void Display(char * operation, Fraction lhs, Fraction rhs, Fraction result); 

int main()
{
	TestAdd(); 
	TestSubtract();
	TestMultiply();
	TestDivide();

	return 0; 
}
void TestAdd()
{	
	//operations
	char * add = " + "; 
	Fraction f1(1, 2),		//reg
			 f2(3, 4),		//reg
			 f3(-4, 5),		//neg reg
			 f4(-6, 13),	//neg reg
			 f5(2, 3, 6),	//pos mix
			 f6(2, 3, 3),	//pos mix
			 f7(2, 5, -5),	//neg mix
			 f8(3, 7, -4);	//neg mix

	cout << "Testing Add: " << endl; 

	//add two pos reg 
	Fraction t0;
	t0.Add(f1, f2); 
	Display(add, f1, f2, t0);

	cout << endl; 
	//add two neg reg
	Fraction t1; 
	t1.Add(f3, f4);
	Display(add, f3, f4, t1); 

	cout << endl;
	//add one neg reg, one pos reg
	Fraction t2; 
	t2.Add(f1, f3);
	Display(add, f1, f3, t2); 

	cout << endl; 
	//add one pos reg, one pos mix
	Fraction t3;
	t3.Add(f1, f5);
	Display(add, f1, f5, t3); 

	cout << endl;
	//add one neg reg, one pos mix
	Fraction t4;
	t4.Add(f3, f6);
	Display(add, f3, f6, t4); 

	cout << endl;
	//add two pos mix
	Fraction t5;
	t5.Add(f5, f6);
	Display(add, f5, f6, t5); 

	cout << endl;
	//add two neg mix
	Fraction t6; 
	t6.Add(f7, f8);
	Display(add, f7, f8, t6);

	cout << endl;
	//and one neg mix, one pos mix
	Fraction t7;
	t7.Add(f7, f5);
	Display(add, f7, f5, t7);

}

void TestSubtract()
{
	char * subtract = " - ";

	Fraction f1(1, 2),		//reg
			 f2(3, 4),		//reg
			 f3(-4, 5),		//neg reg
			 f4(-6, 13),	//neg reg
			 f5(2, 3, 6),	//pos mix
			 f6(2, 3, 3),	//pos mix
			 f7(2, 5, -5),	//neg mix
			 f8(3, 7, -4);	//neg mix

	cout << "Testing Subtract: " << endl;

	//Subtract two pos reg 
	Fraction t0;
	t0.Subtract(f1, f2);
	Display(subtract, f1, f2, t0);

	cout << endl;
	//Subtract two neg reg
	Fraction t1;
	t1.Subtract(f3, f4);
	Display(subtract, f3, f4, t1);

	cout << endl;
	//Subtract one neg reg, one pos reg
	Fraction t2;
	t2.Subtract(f1, f3);
	Display(subtract, f1, f3, t2);

	cout << endl;
	//Subtract one pos reg, one pos mix
	Fraction t3;
	t3.Subtract(f1, f5);
	Display(subtract, f1, f5, t3);

	cout << endl;
	//Subtract one neg reg, one pos mix
	Fraction t4;
	t4.Subtract(f3, f6);
	Display(subtract, f3, f6, t4);
	
	cout << endl;
	//Subtract two pos mix
	Fraction t5;
	t5.Subtract(f5, f6);
	Display(subtract, f5, f6, t5);

	cout << endl;
	//Subtract two neg mix
	Fraction t6;
	t6.Subtract(f7, f8);
	Display(subtract, f7, f8, t6);

	cout << endl;
	//Subtract one neg mix, one pos mix
	Fraction t7;
	t7.Subtract(f7, f5);
	Display(subtract, f7, f5, t7);
}

void TestMultiply()
{
	char * multiply = " * ";
	Fraction f1(1, 2),		//reg
			 f2(3, 4),		//reg
			 f3(-4, 5),		//neg reg
			 f4(-6, 13),	//neg reg
			 f5(2, 3, 6),	//pos mix
			 f6(2, 3, 3),	//pos mix
			 f7(2, 5, -5),	//neg mix
			 f8(3, 7, -4);	//neg mix

	cout << "Testing Multiply: " << endl;

	//Multiply two pos reg 
	Fraction t0;
	t0.Multiply(f1, f2);
	Display(multiply, f1, f2, t0);

	cout << endl;
	//Multiply two neg reg
	Fraction t1;
	t1.Multiply(f3, f4);
	Display(multiply, f3, f4, t1);

	cout << endl;
	//Multiply one neg reg, one pos reg
	Fraction t2;
	t2.Multiply(f1, f3);
	Display(multiply, f1, f3, t2);

	cout << endl;
	//Multiply one pos reg, one pos mix
	Fraction t3;
	t3.Multiply(f1, f5);
	Display(multiply, f1, f5, t3);

	cout << endl;
	//Multiply one neg reg, one pos mix
	Fraction t4;
	t4.Multiply(f3, f6);
	Display(multiply, f3, f6, t4);

	cout << endl;
	//Multiply two pos mix
	Fraction t5;
	t5.Multiply(f5, f6);
	Display(multiply, f5, f6, t5);

	cout << endl;
	//Multiply two neg mix
	Fraction t6;
	t6.Multiply(f7, f8);
	Display(multiply, f7, f8, t6);

	cout << endl;
	//and one neg mix, one pos mix
	Fraction t7;
	t7.Multiply(f7, f5);
	Display(multiply, f7, f5, t7);

}

void TestDivide()
{
	char * divide = " / ";
	Fraction f1(1, 2),		//reg
			 f2(3, 4),		//reg
			 f3(-4, 5),		//neg reg
			 f4(-6, 13),	//neg reg
			 f5(2, 3, 6),	//pos mix
			 f6(2, 3, 3),	//pos mix
			 f7(2, 5, -5),	//neg mix
			 f8(3, 7, -4);	//neg mix

	cout << "Testing Divide: " << endl;

	//Divide two pos reg 
	Fraction t0;
	t0.Divide(f1, f2);
	Display(divide, f1, f2, t0);

	cout << endl;
	//Divide two neg reg
	Fraction t1;
	t1.Divide(f3, f4);
	Display(divide, f3, f4, t1);

	cout << endl;
	//Divide one neg reg, one pos reg
	Fraction t2;
	t2.Divide(f1, f3);
	Display(divide, f1, f3, t2);

	cout << endl;
	//Divide one pos reg, one pos mix
	Fraction t3;
	t3.Divide(f1, f5);
	Display(divide, f1, f5, t3);

	cout << endl;
	//Divide one neg reg, one pos mix
	Fraction t4;
	t4.Divide(f3, f6);
	Display(divide, f3, f6, t4);

	cout << endl;
	//Divide two pos mix
	Fraction t5;
	t5.Divide(f5, f6);
	Display(divide, f5, f6, t5);

	cout << endl;
	//Divide two neg mix
	Fraction t6;
	t6.Divide(f7, f8);
	Display(divide, f7, f8, t6);

	cout << endl;
	//and one neg mix, one pos mix
	Fraction t7;
	t7.Divide(f7, f5);
	Display(divide, f7, f5, t7);

}

void Display(char * operation, Fraction lhs, Fraction rhs, Fraction result)
{
	lhs.Display(); 
	cout << operation;
	rhs.Display(); 
	cout << " = "; 
	result.Display(); 
	cout << endl; 
}
