/*************************************************************
* Author:		Chelsea Christison
* Filename:		controller.cpp
* Date Created:	3.10.2017
* Modifications:
*	3.17 -  created GetInput() function for less redundancy
*			
*			DownloadMP3() now checks the strlen of the buffer
*			to ensure data was read in, and not a blank line
*			
*			AddMoreMusic() now checks to see if the song read
*			already exists in the file BEFORE creating the
*			object to prevent unnecessary allocation and 
*			deallocation of Music objects.
*			
**************************************************************/
#include"controller.h"

//default c'tor
Controller::Controller() { }

/*************************************************************
*	Purpose: 
*		Read from music.txt and fill linked list MP3 with 
*		Nodes containing music objects
*
**************************************************************/
void Controller::DownloadMP3()
{
	ifstream read("music.Txt");

	//buffers
	char buff[BIGBUFF] = { '/0' };
	String songtitle;
	String artist;
	String genre;
	char * buff_tok = nullptr;

	if (read.is_open())
	{
		while (!read.eof())
		{
			read.getline(buff, BIGBUFF);		//read in a whole line
			if(strlen(buff) != 0)
			{
				buff_tok = strtok(buff, "|");	//tokenize buffer on the "," 
				songtitle = buff_tok;			//store the song title 

				buff_tok = strtok(nullptr, "|");
				artist = buff_tok;				//store the artist

				buff_tok = strtok(nullptr, "|");
				genre = buff_tok;				//store the genre

				Music * add_song = new Music(songtitle, artist, genre);

				m_MP3.InsertOrdered(add_song);
			}
			
		}
		read.close();
	}
}

/*************************************************************
*	Purpose:
*		Open music.txt and write entire linked list MP3 back
*		in. Saving any changes made. 
*
**************************************************************/
void Controller::UploadMP3()
{
	ofstream write("music.txt");
	int songnum(1); 
	if(write.is_open())
	{
		write << &m_MP3; 
	}
	write.close(); 
	cout << "Saved MP3" << endl; 
}

/*************************************************************
*	Purpose:
*		Display Menu options for user to select from. 
*		Calls ProcessMenuChoice() 
*
**************************************************************/
void Controller::Menu()
{
	int userinput(0);
	do
	{
		userinput = 0;
		system("cls");
		cout << ":: Chelsea's MP3 ::" << endl
			<< setw(WIDTH) << left << " 1. Search by Song" << setw(40) << left << "Do I have a song? Lets find out!" << endl
			<< setw(WIDTH) << left << " 2. Search by Artist" << setw(30) << left << "See all songs by an artist" << endl
			<< setw(WIDTH) << left << " 3. Search by Genre" << setw(30) << left << "List songs by genre" << endl
			<< setw(WIDTH) << left << " 4. Add a Song" << setw(30) << left << "Add a song to MP3" << endl
			<< setw(WIDTH) << left << " 5. Upload Extra Playlist" << setw(30) << left << "Add a list of songs to MP3" << endl
			<< setw(WIDTH) << left << " 6. Display MP3" << setw(30) << left << "Alphabetized list of all music" << endl
			<< setw(WIDTH) << left << " 7. Remove Song" << setw(30) << left << "I didn't like it that much anyways" << endl
			<< setw(WIDTH) << left << " 8. Remove List of Songs" << setw(30) << left << "I mean, they REALLY sucked" << endl
			<< setw(WIDTH) << left << " 9. Save" << setw(30) << left << "Save songs" << endl
			<< setw(WIDTH) << left << " 10.Exit" << endl;

		Refresh(MENU);
		cout << "Please enter a menu option: ";
		cin >> userinput;
		cin.clear();
		ProcessMenuChoice(userinput);
	} while (userinput != 10);

}

//d'tor
Controller::~Controller() {}

/*************************************************************
*	Purpose:
*		Retrieve input from the console. 
*		
*	Stipulations:
*		Caller must prompt user with what to input. 
*
**************************************************************/
char* Controller::GetInput()
{
	char * cStr = 0;
	char buffer[BUFF] = { '\0' };

	cin.ignore(cin.rdbuf()->in_avail());
	cin.getline(buffer, BUFF);
	cin.clear();
	cout << endl;

	cStr = new char[strlen(buffer) + 1];	//memleak - delete where appropriate 
	strcpy(cStr, buffer);

	return cStr;
}

/*************************************************************
*	Purpose:
*		Open and read extrasongs.txt to add to MP3 - which 
*		is already filled. 
*		Checks if the song to be added already exists in list
*		before adding. 
*
**************************************************************/
void Controller::AddMoreMusic()
{
	ifstream readin("extrasongs.txt"); 
	char buff[BIGBUFF] = { '/0' };
	String songtitle;
	String artist;
	String genre;
	char * buff_tok = nullptr;
	int songcount(0);

	if(readin.is_open())
	{
		while(!readin.eof())
		{
			readin.getline(buff, BIGBUFF);	//read in a whole line

			buff_tok = strtok(buff, "|");	//tokenize buffer on the "," 
			songtitle = buff_tok;			//store the song title 

			buff_tok = strtok(nullptr, "|");
			artist = buff_tok;				//store the artist

			buff_tok = strtok(nullptr, "|");
			genre = buff_tok;

			//search if the song exists already. 
			if(!m_MP3.SearchExistance(songtitle))
			{
				Music * add_song = new Music(songtitle, artist, genre);
				m_MP3.InsertOrdered(add_song); 
				songcount++;
			}
		}
		readin.close();
	}
	cout << "Added " << songcount << " songs to MP3!" << endl; 
}

/*************************************************************
*	Purpose:
*		Open and read discard.txt to read in song name, and 
*		delete from the song from MP3. Delete function in 
*		linked list class handles if song to delete is not 
*		found. 
*
**************************************************************/
void Controller::RemoveSongList()
{
	ifstream readin("discard.txt");
	char buff[BIGBUFF] = { '/0' };
	String songtitle;
	String artist;
	String genre;
	int numchars = 150;
	char * buff_tok = nullptr;
	if(readin.is_open())
	{
		while(!readin.eof())
		{
			readin.getline(buff, BIGBUFF); 

			buff_tok = strtok(buff, "|");	//tokenize buffer on the "," 
			songtitle = buff_tok;			//store the song title 

			m_MP3.Delete(songtitle);
		}
		readin.close();
	}
}

/*************************************************************
*	Purpose:
*		Prompts user to enter in a song name to delete from 
*		the MP3. User can enter the song in any format. 
*		For example: 
*		If actual Music object's song name is:
*			Reverse Skydiving (feat. Anabel Englund)
*		User can enter in the following to find it:
*			"Reverse Skydiving"
*			"reverse skydiving"
*		or the whole title. 
*
**************************************************************/
void Controller::RemoveSong()
{
	char * buffer; 
	system("cls"); 
	cout << "Song name to delete: ";
	buffer = GetInput(); 
	String removesong(buffer);

	cout << "Attempting to remove " << removesong << endl; 
	m_MP3.Delete(removesong); 
	delete[] buffer; 
}

/*************************************************************
*	Purpose:
*		Before exiting program, asks user to save changes.
*		Calls UploadMP3();
*
**************************************************************/
void Controller::Exit()
{
	char userinput; 
	system("cls"); 
	cout << "Would you like to save before exiting?(Y/N): ";
	cin >> userinput;

	if (userinput == 'Y' || userinput == 'y')
	{
		UploadMP3();
		cout << "Saved MP3!" << endl; 
	}

	cout << "Exiting MP3" << endl; 
}

/*************************************************************
*	Purpose:
*		Takes an int representing the number from one of the 
*		menu options. Uses case statement to call desired 
*		menu option.
*
**************************************************************/
void Controller::ProcessMenuChoice(int user_input)
{
	system("cls");
	
	switch (user_input)
	{
		case 1://search for specific song
			{
				SearchSong();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue..."; 
				cin.get(); 
				break;
			}
			
		case 2://list all songs by an artist
			{
				SearchArtist();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 3://list songs by genre
			{	
				SearchGenre();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 4://add a song to MP3
			{
				AddSong();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 5://add more music from txt file
			{
				AddMoreMusic(); 
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get(); 
				break;
			}
		case 6://display contents of mp3
			{
				DisplayMP3();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 7://remove a song 
			{
				RemoveSong(); 
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 8://remove list of songs
			{
				RemoveSongList();
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 9://save the list to music.txt
			{
				UploadMP3();	
				cin.ignore(cin.rdbuf()->in_avail());
				cout << "\n\npress enter to continue...";
				cin.get();
				break;
			}
		case 10:
			{
				Exit(); 
				break; 
			}
		default:
			break; 
	}
}

/*************************************************************
*	Purpose:
*		Searches for a song in the MP3. Prompts user to enter
*		in a song name. User can enter name in any format.
*		For example: 
*		If actual Music object's song name is:
*			Reverse Skydiving (feat. Anabel Englund)
*		User can enter in the following to find it:
*			"Reverse Skydiving"
*			"reverse skydiving"
*		or the whole title. 
*
**************************************************************/
void Controller::SearchSong()
{
	char * buffer;
	system("cls");
	cout << "Song to search for: ";
	buffer = GetInput(); 
	String target_song(buffer);

	Music * song = m_MP3.SearchMP3For(target_song); 

	if (song != nullptr)
		DisplaySong(song);
	else
		DisplayNotFound(target_song); 

	delete[] buffer; 
}

/*************************************************************
*	Purpose:
*		Prompts user for artist name to search for 
*		(case insensitive), and passes it to MP3 to print
*		all songs listed under the artist. 
*		
**************************************************************/
void Controller::SearchArtist()
{
	char *  buffer;
	system("cls");
	cout << "Artist to search for: ";
	buffer = GetInput(); 
	String target_artist(buffer);

	m_MP3.PrintArtistSongs(target_artist);
	delete[] buffer; 
}

/*************************************************************
*	Purpose:
*		Displays to console a menu to chose from for displaying
*		all songs under a particular genre. Takes userinput and
*		passes to MP3. 
*
**************************************************************/
void Controller::SearchGenre()
{	
	char buffer[BUFF] = { '/0' };
	int genrenum = 0; 
	int pickedgenre = 0; 
	char * genres[] = { "House", "Trap", "Chillwave", "Hardstyle", "Electro",
							 "Techno", "TrapRap", "AltIndie", "ChillHop", nullptr};
	system("cls");
	while(genres[genrenum])
	{
		cout << genrenum + 1 << ". " << genres[genrenum] << endl; 
		genrenum++; 
	}
	cout << "Genre to search for: ";
	cin >> pickedgenre;
	
	m_MP3.PrintByGenre(pickedgenre);
}

/*************************************************************
*	Purpose:
*		Adds a song to the MP3. Prompts user for song name, 
*		artist and genre. 
*	Problems!!
*		New genres added wont' be added to predefined list of 
*		genres. This means user wont be able to search for 
*		the new genre type and list the song. 
*		Future Fix: 
*			- Have an dynamic array to contain Genre names. 
*			  As songs are loaded onto MP3, add new genres to 
*			  array.
*		
**************************************************************/
void Controller::AddSong()
{
	char * title_buff;
	char * artist_buff;
	char * genre_buff;
	system("cls");

	//get song title
	cout << "Add a Song\nSong Title: ";
	title_buff = GetInput(); 
	String title(title_buff);
	
	//get artist
	system("cls");
	cout << "Artist: ";
	artist_buff = GetInput();
	String artist(artist_buff);
	
	//get genre
	system("cls");
	cout << "Genre: ";
	genre_buff = GetInput();
	String genre(genre_buff);
	
	Music  * newsong = new Music(title, artist, genre); 
	m_MP3.InsertOrdered(newsong);

	delete[] title_buff;
	delete[] artist_buff;
	delete[] genre_buff;
}

//display the song
void Controller::DisplaySong(Music* song)
{
	cout << "\n - " <<song << endl;
}

//display error for unfound target
void Controller::DisplayNotFound(String target_not_found)
{
	cout << target_not_found << " could not be found!" << endl; 
}

//display entire mp3 list 
void Controller::DisplayMP3()
{
	cout << ":: Chelsea's MP3 ::" << endl; 
	m_MP3.DisplayMP3(); 
}

/*************************************************************
*	Purpose:
*		Outputs certain number of return carriages to enhance
*		the menu display.  
*		
**************************************************************/
void Controller::Refresh(int lines)
{	
	for (int i(0); i < lines; i++)
		cout << '\n';

	cout << endl;
}