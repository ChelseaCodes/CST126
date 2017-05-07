#include<iostream>
using std::cout;
using std::cin;
using std::endl; 

#include<fstream>
using std::ifstream; 

const int MAX(25); 

struct Person
{
	char f_name[MAX];
	int age; 
	char gender; 
};

int ReadData(Person p_array[]); 
void DisplayOne(Person s_person); 
void EditRef(Person & s_person); 
void EditPointer(Person * s_person); 

int main()
{
	Person p_array[6]; 
	Person * ptr_array = p_array; 

	int person_count(0); 

	person_count = ReadData(p_array); 
	
	for (int i(0); i < person_count; i++)
	{
		DisplayOne(p_array[i]); 
	}
	cout << "\n\n" << endl;

	EditRef(p_array[3]);

	EditPointer(&ptr_array[0]);

	return 0; 
}

int ReadData(Person p_array[])
{
	ifstream ReadFile("DataFile.txt"); 
	int person_count(0); 

	if (ReadFile.is_open())
	{
		while (ReadFile.good())
		{
			while (!ReadFile.eof())
			{
					ReadFile >> p_array[person_count].f_name >> p_array[person_count].age
						>> p_array[person_count].gender;
					person_count++;
			}
		}
	}
	else
		cout << "File did not open!" << endl; 

	return --person_count; //increments one too many
}

void DisplayOne(Person s_person)
{
	cout << s_person.f_name << " " << s_person.age << " "
		<< s_person.gender << endl; 
}

void EditRef(Person & s_person)
{
	int user_input(0); 
	int new_age(0); 
	char new_gender; 
	char new_name[MAX] = { '\0' };

	cout << "Person info:\n";
	DisplayOne(s_person); 

	cout << "What would you like to edit?\n"
		<< "1. Name\n"
		<< "2. Age\n"
		<< "3. Gender" << endl; 
	cin >> user_input;

	switch (user_input)
	{
		case 1:
		{
			cout << "What is the new name: "; 
			cin >> new_name; 

			strcpy(s_person.f_name, new_name); 
			break;
		}
		case 2:
		{
			cout << "What is the new age: ";
			cin >> new_age; 

			s_person.age = new_age; 
			break;
		}
		case 3:
		{
			cout << "What is the new gender: ";
			cin >> new_gender; 

			s_person.gender = new_gender; 
			break; 
		}
		default:
			break;
	}

	cout << "Here is the updated information:\n"; 
	DisplayOne(s_person); 
}

void EditPointer(Person * s_person)
{
	int user_input(0);
	int new_age(0);
	char new_gender;
	char new_name[MAX] = { '\0' };

	cout << "Person info:\n";
	DisplayOne(*s_person);

	cout << "What would you like to edit?\n"
		<< "1. Name\n"
		<< "2. Age\n"
		<< "3. Gender" << endl;
	cin >> user_input;

	switch (user_input)
	{
	case 1:
	{
		cout << "What is the new name: ";
		cin >> new_name;

		strcpy(s_person->f_name, new_name);
		break;
	}
	case 2:
	{
		cout << "What is the new age: ";
		cin >> new_age;

		s_person->age = new_age;
		break;
	}
	case 3:
	{
		cout << "What is the new gender: ";
		cin >> new_gender;

		s_person->gender = new_gender;
		break;
	}
	default:
		break;
	}

	cout << "Here is the updated information:\n";
	DisplayOne(*s_person);
}
