/*
 *List.h
 * 
 * Class Description: List data collection ADT.
 * Class Invariant: Data collection with the following characteristics:
 *                   - Each element is unique (no duplicates).
 *                   - Each phone nunber is a search key
 *
 * Author: AL, Yewon Park
 */

#include <iostream>
#include <string>
#include "Member.h"
#include "List.h"


// Description: Factor all code that destroy or remove all elements from the List into
//              this method. Then call it from whichever method needs this functionality.
void List::clear()
{
    for(unsigned int i = 0; i< elementCount;i++)
    {
    	remove(elements[i]);
    }
}

// Default constructor
List::List()
{
	elements = new Member[CAPACITY];
}
	
// Destructor
// Description: Destruct a List object, releasing heap-allocated memory.
List::~List()
{	
	clear();
	delete [] elements;        
}


// Description: Returns the total number of elements currently stored in List.
unsigned int List::getElementCount() const
{
	return elementCount;
}

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.  
// Postcondition: newElement inserted in its proper place in List
//                and elementCount has been incremented.   
bool List::insert( Member& newElement )
{
	if(elementCount < CAPACITY)
	{
		if(search(newElement) != NULL)
			return false;
		elements[elementCount] = newElement;
		elementCount++;
		
	}
	else
		return false;
		
	for(unsigned int i = 0; i < elementCount; i++)
	{
		for(unsigned int j = 0; j < elementCount-i-1; j++)
		{
			if(elements[j] > elements[j+1])
			{
				Member mem = elements[j];
				elements[j] = elements[j+1];
				elements[j+1] = mem;
			}
		}
	}
	return true;
}

// Description: Remove an element. 
// Postcondition: toBeRemoved is removed (leaving no gap in the data structure of List)
//                and elementCount has been decremented.	
bool List::remove( Member& toBeRemoved )
{
	bool ableToRemove = elementCount > 0;
	if(ableToRemove)
	{
		for(unsigned int i = 0; i < elementCount; i++)
		{
			if(elements[i] == toBeRemoved)
			{
				for(unsigned int j =i; j < elementCount; j++)
				{
					elements[j] = elements[j+1];
				}
				elementCount--;
				return ableToRemove;
			}
		} 
	}
	if(elementCount == 0) 
		clear();

	
	return ableToRemove;
}
	
// Description: Remove all elements.
// Postcondition: List is back to the state it was right after being constructed.
void List::removeAll()
{
	clear();
	elementCount = 0;
	  
}
   
// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Member* List::search( Member& target )
{
	Member* tar;
	for(unsigned int i = 0; i < elementCount; i++)
	{
		if(elements[i] == target)
		{
			tar = &elements[i];
			return tar;
		}
	}
	return NULL;
}




	
// Description: Prints all elements stored in List by descending order of search key.
// Time Efficiency: O(n)
void List::printList()
{
	for(int i = elementCount-1; i >= 0; i--)
	{
		cout << elements[i];
	}
}

// end List.cpp


