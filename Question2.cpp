/*
* 
* GOPOLE, KHYLE MATTHEW (PABLO)
* CPE104L-C1
* 
* QUIZ 1
* 
* QUESTION 2


Create a function for the alinked list headers for an 
unordered list that will accept a number and return that 
number's frequency. Use the function in a working program. 
Your program must accept a list of characters. An example 
of the expected output is as follows:

list = x, x, z, x, z, r, r, x

calls your function and passes x

returns the value of 4

Submit all the headers and the main program. 
Use a compression tool for all the files and upload them here.

*/

#include <iostream>
#include "unorderedLinkedList.h"


using namespace std;

int main()
{
	unorderedLinkedList<char> object2;
	char inputChar;
	char confirm;
	char check;

	cout << "WELCOME TO FREQUENCY CHECKER PROGRAM!" << "\n\n";

	do
	{
		cout << "Please enter a character for the list: ";
		cin >> inputChar;
		object2.insertLast(inputChar);
		cout << "Do you want to enter another character ('Y' - Yes  ||  'N' - No): ";
		cin >> confirm;
		system("cls");
	} while (confirm == 'Y' || confirm == 'y');

	cout << "Now Printing Your Entered Characters: \n";

	cout << "list: ";
	object2.print();

	cout << "\nEnter the character you want frequency check: ";
	cin >> check;

	cout << "\nNow Checking Frequency\n";
	cout << "\nFrequency: " << object2.FrequencyChecker(check);

	cout << "\n\nThank you for using the program.";

	return 0;
}