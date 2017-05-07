/************************************************************************
* Class: Controller
*
* Purpose:
*	This class drives the Menu options, and makes calls to linked list. 
*	Most methods hidden from menu. Processes are contained. 
*
* Manager functions:
*	Controller()
*	~Controller()
*	
* Methods:
* Public:
*	DownloadMP3()
*		Reads file and inserts music into list 
*	Menu()
*		menu display
*		
* Private:
*	GetInput()
*		get input from console 
*	AddMoreMusic()
*		batch add more music to list 
*	RemoveSongList()
*		batch remove songs from list
*	RemoveSong()
*		remove a song
*	Exit()
*		exit application 
*	ProcessMenuChoice(int user_input)
*		process menu choice from user 
*	SearchSong()
*		search for and display song
*	SearchArtist()
*		display all songs under an artist
*	SearchGenre()
*		display all songs under a genre
*	AddSong()
*		add a song to list
*	DisplaySong(Music * song)
*		display song to console
*	DisplayNotFound(String  target_not_found)
*		display error if not found 
*	DisplayMP3()
*		display all songs in list 
*		
*************************************************************************/
#ifndef Controller_H
#define Controller_H
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

#include<iomanip>
using std::setw;
using std::left; 

#include <ostream>
using std::ostream;

#include<fstream>
using std::ifstream;
using std::ofstream; 

#include "llist.h"

const int MENU(12);
const int SCRN(17);
const int WIDTH(30);
const int BUFF(80);
const int BIGBUFF(200);

class Controller
{
public:
	Controller(); 

	void DownloadMP3();		//Batch Add
	void Menu();

	~Controller(); 
private:
	Llist m_MP3; 
	char * m_genre_list[];
	static void Refresh(int lines);
	static char * GetInput();
	void AddMoreMusic();	//batch add
	void RemoveSongList();	//Batch Remove
	void RemoveSong(); 
	void Exit(); 
	void ProcessMenuChoice(int user_input);
	void SearchSong(); 
	void SearchArtist(); 
	void SearchGenre();
	void AddSong(); 
	void DisplaySong(Music * song); 
	void DisplayNotFound(String  target_not_found);
	void UploadMP3();		//Save
	void DisplayMP3();
};

#endif // !Controller_H
