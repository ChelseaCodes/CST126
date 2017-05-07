/*************************************************************
* Author:		Chelsea Christison
* Filename:		music.cpp
* Date Created:	3.10.2017
* Modifications: 
*	3.16 -  added in op== for comparing music objects and op!=
*			for both music objects, and music/string
*	3.16 -  op==(Music, String) now checks for a match with 
*			all Music data members instead of JUST Song. 
*			Doesn't restrict comparison to only song. 
*	3.16 -  op==(Music, Music) added to check complete match 
*			between two objects. checking all data members.
*	3.16 -	Added two more display functions:
*			-DisplaySong() will display only the song and genre.
*			-DisplaySongAndArtist() display both song and artist
*				(used for listing by genre) 
*
**************************************************************/
#include "music.h"

//default c'tor
Music::Music():m_song('\0'), m_artist('\0'), m_genre('\0')
{}

//overloaded c'tor: Strings - song, artist, genre
Music::Music(String s, String a, String g) : m_song(s), m_artist(a),
					m_genre(g)
{}

//copy c'tor 
Music::Music(const Music& copy) : m_song(copy.m_song), m_artist(copy.m_artist),
					m_genre(copy.m_genre)
{}

//op= 
Music& Music::operator=(const Music& copy)
{
	if(this != &copy)
	{
		m_song = copy.m_song; 
		m_artist = copy.m_artist;
		m_genre = copy.m_genre; 
	}
	return *this; 
}

//returns song name
String Music::getSong() const
{ return m_song; }

//returns artist name
String Music::getArtist() const
{ return m_artist; }

//returns genre name 
String Music::getGenre() const
{ return m_genre; }

//sets m_song of Music obj
void Music::setSong(String s)
{ m_song = s; }

//sets m_artist of Music obj
void Music::setArtist(String a)
{ m_artist = a; }

//sets m_genre of Music obj
void Music::setGenre(String g)
{ m_genre = g; }

//music d'tor
Music::~Music()
{}

/*************************************************************
*	Purpose:
*		Overloads the extraction operator for Music obj. 
*		Allows user to output the object to a stream rather 
*		than call a display function. 
*		
*		passes all information about song. 
**************************************************************/
ostream& operator<<(ostream& os, Music* data)
{
	os << setw(data->getSong().Length()) << left << data->getSong() << " by "
		<< setw(data->getArtist().Length()) << left << data->getArtist() << " (" << data->getGenre()
		<< ")" << endl;

	return os; 
}

/*************************************************************
*	Purpose:
*		Loads output stream with song name and genre. 
*		Used when user wishes to display all songs under a
*		specific artist
*		ex.
*		Do You Go Up (Chillwave)
*		ostream passed by reference. 
*
**************************************************************/
void Music::DisplaySong(ostream& os)
{
	os << setw(m_song.Length()) << left << m_song  << " (" << m_genre
		<< ")" << endl;
}

/*************************************************************
*	Purpose:
*		Loads output stream with  song name and artist. Used 
*		when user wishes to display all songs under a specific
*		genre.
*		ex.
*		Do You Go Up by Khai
*		
**************************************************************/
void Music::DisplaySongAndArtist(ostream& os)
{
	os << setw(m_song.Length()) << left << m_song << " by "
	    << setw(m_artist.Length()) << left << m_artist << endl; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator<=.
*		Passed this obj and a string. Compares m_song to
*		string passed.
*		Calls the op<= overload in String Class
*
**************************************************************/
bool Music::operator<=(const String& rhs)
{
	return m_song <= rhs; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator>=
*		Passed this obj and a string. Compares m_song to
*		string passed.
*		Calls the op>= overload in String Class
*
**************************************************************/
bool Music::operator>=(const String & rhs)
{
	return m_song >= rhs; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator<
*		Passed this obj and a string. Compares m_song to
*		string passed.
*		Calls the op< overload in String Class
*
**************************************************************/
bool Music::operator<(const String& rhs)
{
	return m_song < rhs; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator>
*		Passed Music obj and a string. Compares m_song to
*		string passed.
*		Calls the op> overload in String Class
*
**************************************************************/
bool Music::operator>(const String& rhs)
{
	return m_song > rhs; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator==
*		Passed Music obj and a string.
*		Compares string passed to all data members in this obj
*		allowing versatility for the string to be passed to
*		contain a song, an artist name or a genre.
*		Calls the op== of string class
*
**************************************************************/
bool Music::operator==(const String& rhs)
{
	return m_song == rhs || m_artist == rhs || m_genre == rhs; 
}

/*************************************************************
*	Purpose:
*		Overloaded operator!=
*		Checks if this music obj passed and string are not the same
*		Calls op== of Music class and returns the inverse
*
**************************************************************/
bool Music::operator!=(const String& rhs)
{
	return !(*this == rhs); 
}

/*************************************************************
*	Purpose:
*		Overloaded operator!=
*		Passed Music objs.
*		Calls the op== of Music class and returns the inverse
*
**************************************************************/
bool Music::operator!=(const Music& rhs)
{
	return (*this == rhs); 
}

/*************************************************************
*	Purpose:
*		Overloaded operator==
*		Passed Music objs. Calls op== of String class.
*		Checks if all data members match.
*
**************************************************************/
bool Music::operator==(const Music& rhs)
{
	return (m_song == rhs.m_song) && 
		   (m_artist == rhs.m_artist) && 
		   (m_genre == rhs.m_genre);
}