/************************************************************************
* Class: Llist
*
* Purpose:
*	This class defines the linked list which uses Nodes.
*
* Manager functions:
*	Llist()
*	~List()
*	
* Methods:
*	InsertOrdered(Music * song) 
*		Insert song into list alphabetically
*	SearchMP3For(String song)
*		search list for desired target
*	SearchExistance(String target)
*		search for the existence of target: returns bool 
*	PrintArtistSongs(String artist)
*		prints all songs by artist
*	PrintByGenre(int genre)
*		print all songs under a genre
*	DisplayMP3
*		Display all contents of list
*	Delete(String song)
*		Delete song from list
*	operator<<(ostream& os, Llist* list)
*		output entire linked list to .txt file, with format conditions
*	Purge()
*		purge list of all data, free memory
*
*************************************************************************/
#ifndef Llist_H
#define Llist_h
#include "node.h"

class Llist
{
public:
	Llist();

	void InsertOrdered(Music * song); 

	Music * SearchMP3For(String Song) const; 
	bool SearchExistance(String target) const;
	void PrintArtistSongs(String artist) const;
	void PrintByGenre(int genre) const;
	void DisplayMP3() const; 
	void Delete(String song); 

	friend ostream& operator<<(ostream & os, Llist * list); 
	~Llist();
private:
	Node * m_head;
	void Purge();
};

#endif // !Llist_H
