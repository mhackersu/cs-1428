// This program uses the IntList class and demonstrates its
// selection sort capability.
#include <iostream>
#include <cstdlib>	        // Needed to use the rand() function
#include "IntList.h"
using namespace std;

int main()
{
	const int SIZE = 20;
	IntList numbers;
	int val;
	
	// Store random numbers in the list 
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
	cout << "Press ENTER to continue...\n";
	cin.get();

	// Sort the numbers using selectionSort
	numbers.selectionSort();

	// Display the numbers
	cout << "Here are the sorted values:\n";
	for (int index = 0; index < SIZE; index++)
	{
		if (numbers.get(index, val))
			cout << val << endl;
	}
	return 0;
}
