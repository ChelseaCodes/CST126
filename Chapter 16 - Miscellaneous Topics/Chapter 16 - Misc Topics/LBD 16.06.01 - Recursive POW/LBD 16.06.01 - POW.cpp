#include<iostream>
using std::cout;
using std::cin; 
using std::endl;

double RecursivePower(double base, double exponent); 
void GetInfo(double & base, double & exponent); 

int main()
{
	double base = 0.0f;
	double exponent = 0.0f; 
	double result = 0.0f; 

	GetInfo(base, exponent); 
	
	result = RecursivePower(base, exponent); 
	cout << result << endl; 
	return 0;
}

double RecursivePower(double base, double exponent)
{
	//using the formula: x^n = x * x^(n-1); 
	//thus:
	//returned value is base times (call POW, but exponent minus 1)
	if (exponent == 0)
		return 1;
	else
		return base * RecursivePower(base, exponent - 1); 
}

void GetInfo(double & base, double & exponent)
{
	cout << "Please enter base:";
	cin >> base; 

	cout << "Please enter exponent:";
	cin >> exponent; 
}