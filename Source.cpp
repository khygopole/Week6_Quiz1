#include <iostream>
#include <string>

#include "queueAsArray.h"

using namespace std;

int main()
{
	queueType<int> object1;
	queueType<char> object2;

	int num;
	int numStart;
	char ch;
	char chStart;
	int deleteConsecNum;

	for (int i = 0; i < 10; i++)
	{
		cout << "Enter a character: ";
		cin >> ch;
		object2.addQueue(ch);
	}



	cout << "Enter the starting character to be deleted: ";
	cin >> chStart;

	cout << "Enter the number of elements to be deleted starting from that point: ";
	cin >> deleteConsecNum;

	object2.RemoveFromListFunction(chStart, deleteConsecNum);

	while (!object2.isEmptyQueue())
	{
		cout << object2.front() << " ";
		object2.deleteQueue();
	}

	return 0;
}