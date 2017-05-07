/************************************************************************
* Class: Music
*
* Purpose:
*	This class defines a Music object: Song, Artist, Genre
*
* Manager functions:
*	Music()
*	Music(String s, String a, String g)
*	Music(const Music& copy)
*	Music& operator=(const Music& copy)
*
* Methods:
*	all setters and getters for Song, Artist, Genre
*	Overloaded comparison operators
*	
*	friend ostream& operator<<(ostream& os, Music * data)
*		overloaded output stream
*	void DisplaySong(ostream& os)
*		Displays song to passed output stream
*	void DisplaySongAndArtist(ostream & os);
*		Displays song and artist info to passed output stream
*	
*************************************************************************/
#ifndef Music_H
#define Music_H

#include <iomanip>
using std::setw; 
using std::left; 

#include <ostream>
using std::ostream;

#include "string.h"

class Music
{
public:
	Music(); 
	Music(String s, String a, String g); 
	Music(const Music& copy); 
	Music& operator=(const Music& copy); 

	String getSong() const;
	String getArtist() const;
	String getGenre() const; 
	void setSong(String s); 
	void setArtist(String a);
	void setGenre(String g);

	friend ostream& operator<<(ostream& os, Music * data); 
	void DisplaySong(ostream& os);
	void DisplaySongAndArtist(ostream & os); 

	bool operator<=(const String & rhs);
	bool operator>= (const String & rhs);
	bool operator<(const String & rhs);
	bool operator>(const String & rhs);
	bool operator==(const String & rhs);
	bool operator!=(const String & rhs);
	bool operator!=(const Music & rhs);
	bool operator==(const Music & rhs);

	~Music(); 
private:
	String m_song;
	String m_artist;
	String m_genre;
	
};

#endif