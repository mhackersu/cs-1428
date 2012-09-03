// This program uses the IntList class and demonstrates its
// binary search capability.
#include <iostream>
#include <cstdlib>		// Needed to use the rand() function
#include "IntList.h"
using namespace std;

int main()
{
	const int SIZE = 20;
	IntList numbers;
	int val, 
		 searchResult;
		 
	// Store random numbers in the list. 
	for (int index = 0; index < SIZE; index++)
	{
		if (!numbers.set(index, rand()))
			cout << "Error storing a value.\n";
	}
	cout << endl;

	// Display the numbers
	for (int index = 0; index < SIZE; index++)
	{
		if (numbers.get(index, val))
			cout << val << endl;
	}
	cout << "Enter one of the numbers shown above: ";
	cin  >> val;
	
	// Search the list for the entered value
	cout << "Searching...\n";
	searchResult = numbers.binarySearch(val);
	if (searchResult == -1)
		cout << "That value was not found in the array.\n";
	else
	{
		cout << "After the array was sorted, that value\n";
		cout << "is found at subscript " << searchResult << endl;
	}
	return 0;
}
