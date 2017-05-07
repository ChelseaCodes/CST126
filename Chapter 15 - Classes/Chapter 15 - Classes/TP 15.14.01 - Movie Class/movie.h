/************************************************************************
* Author:		Chelsea Christison
* Filename:		movie.h
* Date Created:	3.4.2017
*
* Class: Movie
*
* Purpose: This class creates a Fraction object with a numerator,
*		denominator, and a whole number
*
* Manager functions:
* 	Movie();
*	Movie(string name, float length, string rating)
*	Movie(const Movie& copy); 
*	Movie & operator=(const Movie& copy)
*	~Movie();
*
* Methods:
*	all setters and getters
*************************************************************************/
#ifndef MOVIE_H
#define MOVIE_H
#include<iostream>
using std::cout;
using std::endl;

#include<string>
using std::string;

class Movie
{
	public:
		Movie();
		Movie(string name, float length, string rating); 
		Movie(const Movie& copy); 
		Movie& operator=(const Movie& copy); 

		//getters
		string getName() const;
		float getLength() const; 
		float getCost() const;
		string getRating() const; 

		//setters
		void setName(const string name);
		void setLength(const float length);
		void setCost(float cost);
		void setRating(const string rating); 
		
		void Display() const; 

		~Movie();
	private:
		string m_name;
		float m_length; 
		float m_cost; 
		string m_rating; 
};
#endif