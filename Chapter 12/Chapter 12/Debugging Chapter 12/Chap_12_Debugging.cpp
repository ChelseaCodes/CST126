/********************************************************************
* File: Chap_12_Debugging.cpp
*
* General Instructions: Complete each step before proceeding to the 
* next.
*
* Debugging Exercise 1
*
* 1) Create Breakpoint 1 where indicated in the code.
* 2) Run the program using the Start Without Debugging option. Ignore
*    any warnings that your compiler may identify.
* 3) Your program should produce a runtime error.
* 4) Click on the Abort button of the runtime error notification
*    dialog box.
* 5) Run to Breakpoint 1.
* 6) Place a watch on the variable int_ptr.
* 7) Look at the address in int_ptr. Since the pointer wasn't
*    initialized, the address is invalid (garbage).
* 8) Step over the delete statement to verify that this is the line
*    causing the problem.
* 9) Close the runtime error dialog box.
* 10) Initialize the pointer to 0.
* 11) Run the program using the Start Without Debugging option.
* 12) Notice the runtime error no longer appears.
* 13) Disable Breakpoint 1.
*
* Debugging Exercise 2
*
* 1) Run the program using the Start Debugging option.
* 2) When the program is finished executing, inspect the Output
*    window (not the console window) in the compiler. 
* 3) Notice that there are memory leaks identified in the Output
*    window.
* 4) Inspect the information displayed in the Output window. Notice
*    the number of bytes left allocated to the program. Also notice
*    the hexadecimal display of the data.
* 5) Plug the leaks! Uncomment the delete statements located just
*    above the return statement.
* 6) Rerun the program using the Start Debugging option.
* 7) You broke it! Create Breakpoint 2 as indicated in the code.
* 8) Run to Breakpoint 2.
* 9) Put watches on both double pointers. Notice that they have the
*    same address. Deleting the first pointer releases the memory.
*    Deleting the second pointer most of the time will produce an
*    error because the memory has already been released.
* 10) Step over until your program once again crashes. 
* 11) Notice that there are 40 bytes of memory still
*     allocated when the program crashes. This is because dbl_ptr1 
*     now has the address of dbl_ptr2, not the original memory
*     allocated when dbl_ptr1 was declared. The memory originally
*     allocated will not be able to be recovered because there
*     isn't a pointer to that address any more.
* 12) Comment out the following line of code in the program:
*         dbl_ptr1 = dbl_ptr2;
* 13) Run to Breakpoint 2.
* 14) Step over the delete statement.
* 15) You broke it again! Now it is broken on the delete statement
*     for dbl_ptr1.
* 16) Look at the for loop. Notice that it is going out of bounds of
*     the dynamic array. Remember, when dynamic memory is
*     deallocated, the heap is inspected in the general area of the
*     deallocated memory. If it has been disturbed, the program
*     will crash.
* 17) Fix the condition so that it stays within the bounds of the
*     array.
* 18) Rerun the program to Breakpoint 2 and step over the delete
*     statement.
* 19) Notice there is still an error on the delete statement.
*
* Debugging Exercise 3
*
* 1) Create Breakpoint 3 as indicated in the code.
* 2) Run to Breakpoint 3.
* 3) Write down the address currently stored in dbl_ptr1.
* 4) Run to Breakpoint 2.
* 5) What address is currently stored in dbl_ptr1? Notice the
*    difference? Remember, you must delete using the address
*    returned by new.
* 6) Stop debugging.
* 7) Uncomment the following lines of code in the program:
*         double * dbl_ptr3 = dbl_ptr1;
*         dbl_ptr1 = dbl_ptr3;
* 8) Disable all breakpoints.
* 9) Run your program using the Start Debugging option.
* 10) Verify that there are no memory leaks and that the program
*     doesn't crash.
* 
********************************************************************/
#define _CRTDBG_MAP_ALLOC

#include <iostream>
using namespace std;

#include <crtdbg.h>

int main()
{
    _CrtSetDbgFlag( _CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF );

    int * int_ptr = 0;
    char * ch_ptr = new char();
    double * dbl_ptr1 = new double[5];
    double * dbl_ptr2 = new double[10];
    double * dbl_ptr3 = dbl_ptr1;

    // Breakpoint 3
    // Put a breakpoint on the following line
    for ( int i = 0; i <= 4; i++, dbl_ptr1++ )
        *dbl_ptr1 = i;

	//dbl_ptr1 = dbl_ptr2;
	dbl_ptr1 = dbl_ptr3;

    // Breakpoint 1
    // Put a breakpoint on the following line
    
    delete ch_ptr;

    // Breakpoint 2
    // Put a breakpoint on the following line
    delete [] dbl_ptr1;
    delete [] dbl_ptr2;

    return 0;
}

