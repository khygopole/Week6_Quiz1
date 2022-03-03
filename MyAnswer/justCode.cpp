/*
* 
* 
* GOPOLE, KHYLE MATTHEW (PABLO)
* CPE104L-C1
* 
* QUIZ 1

QUESTION 1

Download the zip file. 
Inspect and understand the functions in the files. 
Create a program that will use all the functions in the class. 
Use a list of characters. Your program will be graded 
not only with the implementation of the headers but also 
the uniqueness of the program.

*/


#include <iostream>
#include "headerMe.h"

using namespace std;

int main() 
{
    stackType<char> object1; //object for the header
    char input; //For the input parameter



    cout << "\t\tWELCOME TO REVERSE WORD PROGRAM" << endl;
    cout << "\nThis program lets you enter words or even sentences and prints it out in reverse form." << endl;
    cout << "This program uses Stack Data Structure using Array-Based Lists." << endl;

    object1.p1(); //initialize the stacktop to 0

    cout << "\nEnter a string for the reverse form: ";
    cin >> input;
    do
    {
        object1.p4(input); //inputs the current character  // Function p3 is already used here to check whether the list is already full
        cin.get(input); //use to proceed on the next character 
    } while (input != '\n'); //use to terminate the loop

    cout << "\n\nChecking whether the list is already full.\n";

    if (!object1.p3()) //Function to check the list if it's already full
        cout << "Confirmed: The list still has vacant spaces left!\n";
    else
        cout << "Confirmed: The list is already full from your input!\n";



    cout << "\nNow printing the reversed form of the characters: \n\n";

    while (!object1.p2()) //does while loop and terminates once the list is empty
    {
        cout << object1.p5(); //prints the top-most element on the list
        object1.p6(); //deletes the top-most element on the list 
    }

    cout << "\n\nTHANK YOU FOR USING THE PROGRAM!";

    return 0;
}
