/*************************************************************
* Author:		Chelsea Christison
* Filename:		main.cpp
* Date Created:	3.10.2017
* *
* Lab/Assignment: Programming Linked List
*
* Overview:	
*	This allows a user to keep track of the music on an MP3.
*	Music information is read into a linked list, and user can
*	perform actions based on a menu: 
*	
*	1. Search by Song
*	2. Search by Artist
*	3. Search by Genre
*	4. Add a Song
*	5. Upload Extra Playlist
*	6. Display MP3
*	7. Remove Song
*	8. Remove list of Songs
*	9. Save
*	10. exit
*	
* Input:
*	Program reads 3 txt files: discard, music and extrasongs
*	in the format: 
*	
*	Song Title|Song Artist|Song Genre
*	
*	ex.
*	Reverse Skydiving (feat. Anabel Englund)|Hot Natured|House
*
* Output:
*	Program writes to 1 txt file: music, overwriting preexisting
*	information.
*
************************************************************/
#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include"controller.h"
int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//create controller class
	Controller c0; 
	c0.DownloadMP3();	//download mp3 info
	c0.Menu();			//display Menu

	return 0;
}