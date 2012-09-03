// This program tests the IntList class.
#include <iostream>
#include "IntList.h"
using namespace std;
//Remember to add IntList.cpp to the project containing this file.

int main()
{   const int SIZE = 20;
	int x;
	IntList numbers;      // Create an IntList object, 
	                      // which is an array of ints
	int val;

	// Store 9s in the list and display an asterisk 
	// each time a 9 is successfully stored.
	for (x = 0; x < SIZE; x++)
	{
		if (numbers.set(x, 9))
			cout << "* ";
	}
	cout << endl;

	// Display the 9s
	for (x = 0; x < SIZE; x++)
	{
		if (numbers.get(x, val))
			cout << val << " ";
	}
	cout << endl;

	// Attempt to store a value outside the list's bounds.
	if (numbers.set(50, 9))
		cout << "Element 50 successfully set.\n";
	return 0;
}
