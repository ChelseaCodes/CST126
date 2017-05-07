/*************************************************************
* Author:		Chelsea Christison
* Filename:		movie.cpp
* Date Created:	3.4.2017
* Modifications: 3.4 - added a Display method 
**************************************************************/
#include "movie.h"

Movie::Movie() : m_name("\0"), m_length(0.0), m_cost(12.99), m_rating("\0")
{
	cout << "Movie default c'tor\n" << endl; 
}

Movie::Movie(string name, float length, string rating) : m_name(name),
			m_length(length), m_cost(12.99), m_rating(rating)
{
	cout << "Movie 3 arg c'tor\n" << endl; 
}

Movie::Movie(const Movie & copy) : m_name(copy.m_name), m_length(copy.m_length),
			m_cost(copy.m_cost), m_rating(copy.m_rating)
{
	cout << "Movie copy c'tor\n" << endl; 
}

Movie & Movie::operator=(const Movie & copy)
{
	cout << "Movie op=\n" << endl; 
	if (this != &copy)
	{
		m_name = copy.m_name;
		m_length = copy.m_length; 
		m_cost = copy.m_cost; 
		m_rating = copy.m_rating; 
	}

	return *this; 
}

string Movie::getName() const
{
	return m_name;
}

float Movie::getLength() const
{
	return m_length;
}

void Movie::setName(const string name)
{
	m_name = name; 
}

void Movie::setLength(const float length)
{
	m_length = length;
}

void Movie::setCost(float cost)
{
	m_cost = cost; 
}

void Movie::setRating(const string rating)
{
	m_rating = rating; 
}

void Movie::Display() const
{
	cout << "Name: " << m_name << endl
		 << "Length: " << m_length << " minutes" << endl
		 << "Cost: " << m_cost << endl << "Rating: " << m_rating
		 << endl;
}

float Movie::getCost() const
{
	return m_cost;
}

string Movie::getRating() const
{
	return m_rating;
}

Movie::~Movie()
{
	cout << "Movie d'tor\n" << endl;
}
