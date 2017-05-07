/*************************************************************
* Author:		Chelsea Christison
* Filename:		Fraction.cpp
* Date Created:	2/23/2017
* Modifications:	2/26/17 - fixed reducing issues and negative
	number problems 
**************************************************************/
#include "Fraction.h"

Fraction::Fraction(int numer, int denom, int whole) : m_numer(numer), m_denom(denom),
m_whole(whole)
{
	//cout << "in 3 arg c'tor" << endl; 

	//if denom is a negative
	if (m_denom < 0)
	{
		m_denom *= -1; //make positive
		m_numer *= -1; //make numer negative
	}

	//for operations, best to be improper
	if (m_whole != 0)
	{
		if (m_whole < 0)
		{
			m_whole *= -1; 
			ConvertToImproper(); 
			m_numer *= -1; 
		}
		else
			ConvertToImproper(); 
	}
}

Fraction::Fraction(const Fraction& copy) : m_numer(copy.m_numer), m_denom(copy.m_denom),
m_whole(copy.m_whole)
{
	//cout << "in copy c'tor" << endl;

	//if denom is a negative
	if (m_denom < 0)
	{
		m_denom *= -1; //make positive
		m_numer *= -1; //make numer negative
	}

	if (m_whole != 0)
	{
		ConvertToImproper();
	}
}

Fraction& Fraction::operator=(const Fraction& copy)
{
	//cout << "in op='s" << endl; 
	if (this != &copy)
	{
		m_numer = copy.m_numer;
		m_denom = copy.m_denom;
		m_whole = copy.m_whole; 

		if (m_denom < 0)
		{
			m_denom *= -1; //make positive
			m_numer *= -1; //make numer negative
		}

		if (m_whole != 0)
		{
			ConvertToImproper();
		}
	}

	return *this; 
}

void Fraction::Add(Fraction left_frac, Fraction right_frac)
{
	//	(a/b) + (c/d) = (a*d + b*c) / b * d
	m_numer = (left_frac.m_numer * right_frac.m_denom) +
		      (left_frac.m_denom * right_frac.m_numer);

	m_denom	= (left_frac.m_denom * right_frac.m_denom);

}

void Fraction::Subtract(Fraction left_frac, Fraction right_frac)
{
	//	(a/b) - (c/d) = (a*d - b*c) / b * d
	m_numer = (left_frac.m_numer * right_frac.m_denom) -
			  (left_frac.m_denom * right_frac.m_numer);

	m_denom = (left_frac.m_denom * right_frac.m_denom);
}

void Fraction::Multiply(Fraction left_frac, Fraction right_frac)
{
	m_numer = left_frac.m_numer * right_frac.m_numer; 
	m_denom = left_frac.m_denom * right_frac.m_denom; 
}

void Fraction::Divide(Fraction left_frac, Fraction right_frac)
{
	//using right hand fraction, create an inverse fraction
	Fraction temp(right_frac.m_denom, right_frac.m_numer);

	//pass inverse to be multiplied
	Multiply(left_frac, temp);
}

int Fraction::GCD(int num_a, int num_b)
{
	int temp(0);

	if (num_a < 0)
		num_a *= -1;
	if (num_b < 0)
		num_b *= -1; 

	if (num_a < num_b)
	{
		temp = num_a;
		num_a = num_b;
		num_b = temp;
	}
	while (num_b != 0)
	{
		temp = num_b;
		num_b = num_a % num_b;
		num_a = temp;
	}
	return num_a;
}

void Fraction::Display()
{
	Reduce(); 
	if (m_whole != 0)
	{
		cout << m_whole << " "; 
	}

	if(m_numer != 0 && m_denom != 0)
		cout << m_numer << "/" << m_denom; 
}

void Fraction::SetNumer(int numer)
{
	m_numer = numer; 
}

void Fraction::SetDenom(int denom)
{
	m_denom = denom; 
}

void Fraction::SetWhole(int whole)
{
	m_whole = whole; 
}

int Fraction::GetNumer()
{
	return m_numer;
}

int Fraction::GetDenom()
{
	return m_denom;
}

int Fraction::GetWhole()
{
	return m_whole;
}


void Fraction::Reduce()
{
	if (m_numer > m_denom)
	{
		m_whole = m_numer / m_denom; 
		m_numer %= m_denom; 
	}
	else if ((-1 * m_numer) > m_denom)	//checks if number is neg, but larger
	{
		m_whole = ( -1 * m_numer) / m_denom;
		m_numer %= m_denom;
	}
	else if (m_numer == m_denom)
	{
		m_whole = 1; 
		m_numer = 0; 
		m_denom = 0; 
	}

	int gcd = GCD(m_numer, m_denom);
	m_numer /= gcd; 
	m_denom /= gcd; 

	//if numer is negative with a whole num
	if (m_numer <= 0 && m_whole != 0)
	{
		m_numer *= -1; //make numer pos
		m_whole *= -1; //reflect negative in whole num
	}


}

void Fraction::ConvertToImproper()
{
	m_numer = (m_denom * m_whole) + m_numer; 
	m_whole = 0;
}

Fraction::~Fraction()
{
	//cout << "Fraction d'tor" << endl;
}

