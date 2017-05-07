#include<iostream>
using std::cout; 
using std::endl; 

int main( int argc, char *argv[] )
{
    float average;
    int sum = 0;

    // Valid number of arguments?
    if ( argc > 1 ) 
    {
        // Loop through arguments ignoring the first which is
        // the name and path of this program
        for ( int i = 1; i < argc; i++ ) 
        {
            // Convert cString to int 
            sum += atoi( argv[i] );    
        }

        // Calculate average
        average = sum / ( argc - 1 );       
        cout << "\nSum: " << sum << '\n'
             << "Average: " << average << endl;
    }
    else
    {
	  // If invalid number of arguments, display error message
        // and usage syntax
        cout << "Error: No arguments\n" 
             << "Syntax: command_line [space delimted numbers]" 
             << endl;
    }

    return 0;
}
// Command line execution
//C:\LearnByDoing\debug>command_line 15 25 35 10 19 40

// Output
//Sum: 144
//Average: 24
