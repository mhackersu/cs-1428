// Member function definitions for the IntList class 
#include <iostream>
#include "IntList.h"
using namespace std;

/*************************************************************
 *                     Constructor                           *
 * Initializes each element in the list to zero.             *
 *************************************************************/
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

/***************************************************************
 *                          set                                *
 * This public member function is passed an element number and *
 * a value. If the element number is a valid array subscript,  *
 * the value is stored in the array at that location and the   *
 * function returns true. Otherwise,the function returns false.*
 ***************************************************************/
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
