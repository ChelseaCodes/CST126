/************************************************************************
* Class: Fraction
*
* Purpose: This class creates a Fraction object with a numerator, 
*		denominator, and a whole number
*
* Manager functions:
* 	Fraction ( )
* 		The default values are numer =1, and denom = 1
*	Fraction (int numer =1, int denom = 1)
*		Creates a fraction, initialized to 1/1
*	Fraction (const Fraction & copy)
*	operator = (const Fraction & copy)
*	~Fraction()
*
* Methods:
*	void Add(Fraction left_frac, Fraction right_frac)	
*			add two fractions
*	void Subtract(Fraction left_frac, Fraction right_frac)
*			subtract two fractions
*	void Multiply(Fraction left_frac, Fraction right_frac)
*			multiply two fractions
*	void Divide(Fraction left_frac, Fraction right_frac)
*			divide two fractions
*	int GCD(int left_denom, int right_denom)
*			find the greatest common divisor 
*	void Display(); 
*************************************************************************/
#ifndef FRACTION_H
#define FRACTION_H
#include<iostream>
using std::cout;
using std::endl; 

class Fraction
{
	public:
		//Fraction();
		Fraction(int number = 1, int denom = 1, int whole = 0);
		Fraction(const Fraction& copy);
		Fraction& operator=(const Fraction& copy); 

		void Add(Fraction left_frac, Fraction right_frac); 
		void Subtract(Fraction left_frac, Fraction right_frac);
		void Multiply(Fraction left_frac, Fraction right_frac); 
		void Divide(Fraction left_frac, Fraction right_frac); 
		int GCD(int left_denom, int right_denom);
		void Display(); 

		void SetNumer(int numer); 
		void SetDenom(int denom); 
		void SetWhole(int whole); 
		int GetNumer();
		int GetDenom(); 
		int GetWhole();

		~Fraction(); 
	private:
		int m_numer;
		int m_denom;
		int m_whole; 
		void Reduce(); 
		void ConvertToImproper(); 

};
#endif // !FRACTION_H


