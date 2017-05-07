/*******************************************************************
* File: Chap_15_Debugging.cpp
*
* General Instructions: Complete each step before proceeding to the 
* next.
*
* 1) Look at the existing code and identify how many 
*    times you anticipate that the constructor will be called
*    when the program is executed.
* 2) Add an informative output message in the constructor
*    that includes the name of the stock symbol.
* 3) Build and execute the program and verify that the
*    constructor was called once for each of the three
*    objects created.
* 4) Add a destructor.
* 5) Set and run your program to Breakpoint 1. Use Step 
*    Into to actually step into the destructor.  
* 6) Stop debugging.
* 7) Add an informative message in your destructor that 
*    includes the name of the stock symbol.
* 8) Rebuild and execute the program. Make sure 
*    the dtor is being called for all three of 
*    your Stock objects.  
* 9) If you have not already done so, find and correct 
*    the problem associated with the destructor not 
*    being called for one of your objects.
*10) Create an array of three Stock objects in main.
*11) Rebuild and execute the program. Notice we have a 
*    problem.
*12) Add the necessary constructor to fix this problem.
*    Make sure you include a descriptive message noting
*    that this is the default constructor. Rebuild and 
*    execute the program to make sure that everything is 
*    working.
*13) Notice the number of times the constructors and the 
*    destructor are being called.
*14) Try making both of your constructors private.
*15) Rebuild and execute the program. Notice how this stops
*    any instance of the object from being created.
*16) Make your constructors public again.
*17) Uncomment the following two lines in main:
*      // Stock s1();
*      // s1.setPrice( 12.34 );
*18) Try rebuilding the program. Notice there is a problem.
*19) Look carefully at the first line you uncommented.  
*    This is simply a function declaration. It is not 
*    instantiating an object!
*20) Remove the ( ), rebuild and execute the program. 
*********************************************************************/

// Chap_15_Debugging.cpp
#include <iostream>
using std::cout;
using std::endl;

#include "Debugging.h"

void DisplayStock( Stock & s );
void DisplayStock( Stock * s );
void SetStockPricesEqual( Stock & s1, Stock s2 ); //& del

int main()
{	
	//**deleted()
	Stock s1;
    s1.setPrice ( 12.34 );
	Stock s2( "MSFT", 100, 28.50 );
	Stock s3( "INTC", 200, 21.25 );
	Stock * s4 = new Stock( "CSCO", 300, 24.75 );	//& del

	
    DisplayStock( s2 );
	SetStockPricesEqual( s2, s3 );
	DisplayStock( s3 );
	DisplayStock( s4 );

	//**Added array
	cout << "making Stock array in main" << endl; 
	Stock array[4]; 

	delete s4;	//was s3

    // Breakpoint 1
	return 0;
}

void DisplayStock( Stock & s )
{  	
	cout << "\nStock: " << s.getStockSymbol()
	     << " Shares: " << s.getShares() 
         << " Price: "  << s.getPrice() << endl;	
}
void DisplayStock( Stock * s )
{  	
	cout << "\nStock: " << s->getStockSymbol() 
	     << " Shares: " << s->getShares() 
         << " Price: "  << s->getPrice() << endl;	
}
void SetStockPricesEqual( Stock & s1, Stock s2 )	//wrong
{	
	s1.setPrice( s2.getPrice() );
}