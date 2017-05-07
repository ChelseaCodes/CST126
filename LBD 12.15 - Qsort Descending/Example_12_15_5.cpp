#include <iostream>
#include <cstdlib>  // Required for qsort
#include <cstring>
using std::cout;
using std::endl;

int compare_strs( const void *arg1, const void *arg2 );
int compare_ints( const void* arg1, const void* arg2 );

int main()
{
    char * shrooms[10] = 
    {
        "Matsutake", "Lobster", "Oyster", "King Boletus",
        "Shaggy Mane", "Morel", "Chanterelle", "Calf Brain",
        "Pig's Ear", "Chicken of the Woods"
    };

    int nums[10] = {99, 43, 23, 100, 66, 12, 0, 125, 76, 2};

    // The address of the array, number of elements
    // the size of each element, the function pointer to 
    // compare two of the elements
    qsort( (void *)shrooms, 10, sizeof( char * ), compare_strs ); 
    qsort( (void *)nums, 10, sizeof( int * ), compare_ints ); 

    // Output sorted lists
    for ( int i = 0; i < 10; ++i )
        cout << shrooms[i] << endl;

	cout << "\n" << endl; 

    for ( int i = 0; i < 10; ++i )
        cout << nums[i] << endl;

    return 0;
}

//Modify the following to sort in DESCENDING order 
int compare_ints( const void * arg1, const void * arg2 )
{
    int return_value = 0;

    if ( *(int *)arg1 < *(int *)arg2 )	//< 
        return_value = 1;	//-1
    else if ( *(int *)arg1 > *(int *)arg2 )	//>
        return_value = -1;	//1

    return return_value;
}
int compare_strs(const void * arg1, const void * arg2)
{
	//return (stricmp(*(char **)arg1, *(char **)arg2));

	if (stricmp(*(char **)arg1, *(char **)arg2) > 0)	//1: s1 > s2
		return -1;
	else if (stricmp(*(char **)arg1, *(char **)arg2) < 0)	//-1: s1 < s2
		return 1;
	else if (stricmp(*(char **)arg1, *(char **)arg2) == 0)
		return 0;

}		
