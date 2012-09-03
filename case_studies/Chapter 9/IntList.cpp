// Member function definitions for the enhanced IntList class
#include <iostream>
#include "IntList.h"
using namespace std;

/************************************************************
 *                          IntList                         *
 * This is the default constructor.                         *
 * It initializes each element in the list to zero.         *
 ************************************************************/
IntList::IntList()
{ 
	for (int index = 0; index < MAX_SIZE; index++)
		list[index] = 0;
}

/**************************************************************
 *                        isValid                             *
 * This private member function returns true if the argument  *
 * is a valid subscript into the list. Otherwise, it displays *
 * an error message and returns false.                        *
 *************************************************************/
bool IntList::isValid(int element)
{
	if (element < 0 || element > MAX_SIZE - 1)
	{
		cout << "ERROR: " << element;
		cout << " is an invalid subscript.\n";
		return false;
	}
	else
		return true;
}

/****************************************************************
 *                             set                              *
 * This public member function is passed an element number and  *
 * a value. If the element number is a valid array subscript,   *
 * the value is stored in the array at that location and the    *
 * function returns true. Otherwise,the function returns false. *
 ****************************************************************/
bool IntList::set(int element, int value)
{
	if (isValid(element))
	{
		list[element] = value;
		return true;
	}
	else
		return false;
}

/* ***************************************************************
 *                              get                              *
 * This public member function is passed an element number. If   *
 * it is a valid array subscript, the value stored in the array  *
 * at that location is retrieved and is made available to the    *
 * calling function by placing it in a reference parameter.      *
 * The function then returns true. If the element number passed  *
 * in is not a valid subscript, the function returns false.      *
 *****************************************************************/
bool IntList::get(int element, int &value)
{
	if (isValid(element))
	{
		value = list[element];
		return true;
	}
	else
		return false;
}

/* **************************************************************
 *                       linearSearch                           *
 * This public member function performs a linear search on the  *
 * list, looking for value. If it is found, its array subscript *
 * is returned. Otherwise, -1 is returned, indicating the value *
 * is not in the array.                                         *
 ****************************************************************/
int IntList::linearSearch(int value)
{
	int index = 0;                // Used as a subscript to search array 
	int position = -1;            // Used to record position of search value 
	bool found = false;           // Flag to indicate if the value was found 

	while (index < MAX_SIZE && !found)
	{
		if (list[index] == value) // If the value is found
		{
			found = true;         // Set the flag 
			position = index;     // Record the value's subscript 
		}
		index++;                  // Go to the next element 
	}
	return position;              // Return the position, or -1 
}                                 // -1 indicates the value was not found 

/* **************************************************************
 *                       binarySearch                           *
 * This public member function performs a binary search on the  *
 * list, looking for value. If it is found, its array subscript *
 * is returned. Otherwise, -1 is returned, indicating the value *
 * is not in the array.                                         *
 ****************************************************************/
int IntList::binarySearch(int value)
{
	int  first = 0,
		 last = MAX_SIZE - 1,
		 middle,
		 position = -1;
	bool found = false;

	// First, sort the list.
	selectionSort();

	while (!found && first <= last)
	{
		middle = (first + last) / 2;
		if (list[middle] == value)    // If value was found
		{	found = true;
			position = middle;        // Set position to the location
		}                             // where it was found
		else if (list[middle] > value)
			last = middle - 1;
 		else
			first = middle + 1;
	}
	return position;                  // If position is still -1 it 
}                                     // indicates value was not found

/* *************************************************************
 *                        bubbleSort                           *
 * This public member function performs an ascending-order     *
 * bubble sort on the list.                                    *
 ***************************************************************/ 
void IntList::bubbleSort()
{
	int temp;
	bool swap;

	do
	{
		swap = false;
		for (int count = 0; count < MAX_SIZE - 1; count++)
		{
			if (list[count] > list[count + 1])
			{
				temp = list[count];
				list[count] = list[count + 1];
				list[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}

/***************************************************************
 *                     selectionSort                           *
 * This public member function performs an ascending-order     *
 * selection sort on the list.                                 *
 ***************************************************************/
void IntList::selectionSort()
{
	int startScan, minIndex, minValue;

	for (startScan = 0; startScan < MAX_SIZE - 1; startScan++)
	{
		minIndex = startScan;
		minValue = list[startScan];
		for(int index = startScan + 1; index < MAX_SIZE; index++)
		{
			if (list[index] < minValue)
			{
				minValue = list[index];
				minIndex = index;
			}
		}
		list[minIndex] = list[startScan];
		list[startScan] = minValue;
	}
}
