// This program allows the user to enter two sets of numbers and then 
// finds the intersection of the two sets (i.e., the set of numbers
// contained in both sets). The intersecting values are displayed.
#include <iostream>
using namespace std;

// Function prototypes
void getArrays(int [], int []);
int findIntersection(int [], int [], int []);
void displayIntValues(int [], int);

const int SET_SIZE = 10;

int main()
{
	int set1[SET_SIZE],          // First set
	    set2[SET_SIZE],		     // Second set
		intersection[SET_SIZE],  // Set containing intersection values
		numIntValues;		     // Number of values in intersection set

	getArrays(set1, set2);
	numIntValues = findIntersection(set1, set2, intersection);
	displayIntValues(intersection, numIntValues);
	return 0;
}

/******************************************************
 *                      getArrays                     *
 * This function receives two int arrays as arguments * 
 * and fills them with values input by the user.      *
 ******************************************************/
void getArrays(int first[], int second[])
{
	int index;
	
	// Get values for first array.
	cout << "Enter " << SET_SIZE << " values for the first set:\n";
	for (index = 0; index < SET_SIZE; index++)
		cin >> first[index];

	// Get values for second array.
	cout << "\nEnter " << SET_SIZE << " values for the second set:\n";
	for (index = 0; index < SET_SIZE; index++)
		cin >> second[index];
}

/**********************************************************
 *                    findIntersection                    *
 * This function receives three int arrays as arguments.  *
 * The first two arrays (first and second) are scanned,   *
 * and all values appearing in both are stored in the     *
 * third array (intersect). The number of values common   *
 * to both arrays is returned.                            *
 **********************************************************/
int findIntersection(int first[], int second[], int intersect[])
{
	int intCount = 0, index3 = 0;

	for (int index1 = 0; index1 < SET_SIZE; index1++)
	{
		for(int index2 = 0; index2 < SET_SIZE; index2++)
		{
			if (first[index1] == second[index2])
			{
				intersect[index3] = first[index1];
				index3++;
				intCount++;
			}
		}
	}
	return intCount;
}

/************************************************************
 *                       displayIntValues                   *
 * This function receives two arguments: an array of ints   *
 * and an int indicating the number of valid elements in    *
 * the array. These values are displayed, if there are any. *
 ************************************************************/
void displayIntValues(int intersect[], int num)
{
	if (!num)          // Same as saying if (num == 0)
		cout << "\nThere are no intersecting values.\n";
	else
	{
		cout << "\nHere is a list of the intersecting values:\n";
		for (int index = 0; index < num; index++)
			cout << intersect[index] << " ";
		cout << endl;
	}
}
