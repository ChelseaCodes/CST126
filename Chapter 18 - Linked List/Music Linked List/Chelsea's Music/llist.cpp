/*************************************************************
* Author:		Chelsea Christison
* Filename:		llist.cpp
* Date Created:	3.10.2017
* Modifications:
*	3.16 -	Added SearchExistance for printing all songs under
*			a single artist
*			
*			PrintByGenre now gives user a predefined set of 
*			options to choose from for displaying all songs
*			under a specific genre: 
*			
*			1. House		6. Techno
*			2. Trap			7. TrapRap
*			3. Chillwave	8. AltIndie
*			4. Hardstyle	9. ChillHop
*			5. Electro
*			
*			overloaded op<< for linked list to be written to
*			file. Takes Music data in each node, and adds a
*			bar('|') when written back. 
*			
*	3.17 -  Delete function used for both delete list of songs
*			and to delete just a single song defined by user
**************************************************************/
#include"llist.h"

//default c'tor
Llist::Llist() : m_head(nullptr) {}

/*************************************************************
*	Purpose:
*		Takes a ptr to Music obj and adds it into the linked
*		list alphabetically by song name. 
*		Utilizes overloaded comparison operators for cleaner
*		readability. 
*
**************************************************************/
void Llist::InsertOrdered(Music * song)
{
	Node * nn = new Node(song);

	if (m_head == nullptr || *nn <= *m_head)
	{
		nn->setNext(m_head);
		m_head = nn; 
	}
	else
	{
		Node * travel = m_head; 
		Node * trail = nullptr;
		while (travel != nullptr && *travel < *nn)
		{
			trail = travel;
			travel = travel->getNext();
		}
		trail->setNext(nn); 
		nn->setNext(travel);
	}
}

/*************************************************************
*	Purpose:
*		Takes a String obj containing a song name and compares
*		to data in linked list. 
*		
*	Returns:
*		Returns a ptr to the music object found, or null if 
*		not found.
**************************************************************/
Music* Llist::SearchMP3For(String Song) const
{
	Node * travel = m_head;
	while (travel != nullptr && *(travel->getData()) != Song)
	{
		travel = travel->getNext();
	}

	if (travel != nullptr)
		return travel->getData();

	return nullptr;
}

/*************************************************************
*	Purpose:
*		Takes a String obj calls SearchMP3For
*	Returns:
*		returns conditional statement result: Is m ptr
*		not null
**************************************************************/
bool Llist::SearchExistance(String target) const
{
	Music * m = SearchMP3For(target);
	return m != nullptr;
}

/*************************************************************
*	Purpose:
*		Takes a String obj containing artist name, and displays
*		all songs under that Artist. *
*	Returns:
*		outputs songs to console. 
**************************************************************/
void Llist::PrintArtistSongs(String artist) const
{
	system("cls");
	if(SearchExistance(artist))
	{
		Node * travel = m_head;
		int song_num = 1; 
		cout << ":: " << artist << " ::" << endl;
		while(travel != nullptr)
		{
			if(*(travel->getData()) == artist)
			{
				cout << " " << song_num << ". ";
				travel->getData()->DisplaySong(cout); 
				song_num++;
			}
			travel = travel->getNext(); 
		}
	}
}

/*************************************************************
*	Purpose:
*		takes an integer input which is called after gaining
*		input from a displayed genre list. 
*		Displays all songs under chosen genre
*		
**************************************************************/
void Llist::PrintByGenre(int genre) const
{
	system("cls"); 
	Node * travel = m_head;
	int song_num = 1;
	char * genres[] = { "House", "Trap", "Chillwave", "Hardstyle", "Electro",
		"Techno", "TrapRap", "AltIndie", "ChillHop" };

	cout << ":: " << genres[--genre] << " ::" << endl;
	while (travel != nullptr)
	{
		if (*(travel->getData()) == genres[genre])
		{
			cout << " " << song_num << ". "; 
			travel->getData()->DisplaySongAndArtist(cout);
			song_num++;
		}
		travel = travel->getNext();
	}
}

/*************************************************************
*	Purpose:
*		Traverses and displays all songs in linked list
*
**************************************************************/
void Llist::DisplayMP3() const
{
	system("cls");
	Node * travel = m_head;
	int song_number = 1; 

	while(travel)
	{
		cout << song_number << ". " << travel->getData() << endl;
		song_number++;
		travel = travel->getNext(); 
	}
}

/*************************************************************
*	Purpose:
*		takes a target String obj with desired song name to 
*		delete. If its found in the linked list, it will be 
*		deleted. 
*
**************************************************************/
void Llist::Delete(String song)
{
	Node * travel = nullptr;
	Node * trail = nullptr; 

	if (m_head == nullptr)
		cout << "Empty MP3!" << endl; 
	else if(*(m_head->getData()) == song)
	{
		trail = m_head;
		m_head = m_head->getNext(); 
		delete trail;
	}
	else
	{
		travel = m_head;
		while(travel != nullptr && *(travel->getData()) != song)
		{
			trail = travel; 
			travel = travel->getNext(); 
		}

		if (travel == nullptr)
			cout << song << " was not found in MP3! " << endl; 
		else
		{
			trail->setNext(travel->getNext()); 
			delete travel; 
		}
	}
}

/*************************************************************
*	Purpose:
*		Overloaded operator<< returns an output stream. 
*		Used for writing linked list into .txt file for 
*		saving. 
*
**************************************************************/
ostream& operator<<(ostream& os, Llist * list)
{
	Node * travel = list->m_head;
	const String bar("|"); 
	
	while(travel)
	{
		os << travel->getData()->getSong() << bar << travel->getData()->getArtist()
			<< bar << travel->getData()->getGenre();
		
		if (travel->getNext() != nullptr)
			os << endl; 
		
		travel = travel->getNext(); 
	}
	return os; 
}

//d'tor
Llist::~Llist() { Purge(); }

/*************************************************************
*	Purpose:
*		Purges linked list. releasing any allocated memory
*		for Nodes. 
*
**************************************************************/
void Llist::Purge()
{
	Node * trail = nullptr;
	while (m_head != nullptr)
	{
		trail = m_head;
		m_head = m_head->getNext();
		delete trail;
	}
}
