/*************************************************************
* Author:		Chelsea Christison
* Filename:		main.cpp
* Date Created:	3.4.2017
*
* Lab/Assignment: TP 15.14.01 Movie Class
*
* Overview:
*	This program tests the Movie Class functionality.
*	
* Input:
*	No user input from console. All variables made in main.cpp
*
* Output:
*	The output of this program will be the outputs in various 
*	Movie methods, such as the c'tor and d'tor. 
*
************************************************************/
#include<iostream>
using std::cout;
using std::endl;

#include"movie.h"

void TestMovieClass(); 
void MovieSet(Movie & movie); 
void TestConstMove(const Movie & movie); 
void GetterDisplay(const Movie & movie); 

int main()
{
	TestMovieClass(); 

	//further functionality const testing
	//const Movie 
	cout << "Testing const Movie" << endl; 
	const Movie Avatar("Avatar", 120.51, "PG-13");

	TestConstMove(Avatar); 

	return 0; 
}

/**********************************************************************
* Purpose: This function tests different methods of the Movie class.
*
* Precondition:
*   no inputs
*
* Postcondition:
*   output of methods, such as c'tor and d'tors and indications to 
*	user on what is happening: such as getting information or setting
*	information. 
*
************************************************************************/
void TestMovieClass()
{
	/*	TESTS	*/
	//default c'tor
	Movie test_movie; 

	//3 arg c'tor
	Movie Her("Her", 102.30, "R"); 

	//copy c'tor
	Movie HerCopy(Her); 

	//operator =
	test_movie = HerCopy;
	
	//Getters
	cout << "Getters: " << endl; 
	GetterDisplay(Her); 
	cout << endl; 

	//Setters
	cout << "Setting movie " << test_movie.getName() << endl;
	MovieSet(test_movie); 
	cout << "Movie set: " << endl; 
	test_movie.Display(); 
}

/**********************************************************************
* Purpose: This function sets the Movie object passed to arbitrary 
*	information. Tests the setters of given object. 
*
* Precondition:
*   movie - Movie object passed by reference
*
* Postcondition:
*   modifies movie
*
************************************************************************/
void MovieSet(Movie & movie)
{
	movie.setCost(2.99);
	movie.setLength(133.44);
	movie.setName("BLANK");
	movie.setRating("G"); 
}

/**********************************************************************
* Purpose: This function takes a const ref Movie object to test the 
*	that the const methods work with const class. 
*
* Precondition:
*   movie - passed by const ref
*
* Postcondition:
*   modifies movie
*
************************************************************************/
void TestConstMove(const Movie & movie)
{
	//copy c'tor
	const Movie movie2(movie); 

	//operator =
	Movie movie3; 
	movie3 = movie;

	//Getters
	cout << "Getters: " << endl;
	GetterDisplay(movie); 
}

void GetterDisplay(const Movie & movie)
{
	cout << "Name: " << movie.getName() << endl
		 << "Length: " << movie.getLength() << " minutes" << endl
		 << "Cost: " << movie.getCost() << endl << "Rating: " << movie.getRating()
		 << endl;
}
