/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Syntax Checker

#include "GenStack.h"
#include <iostream>

using namespace std;
template <class sTemp>

//constructor that sets a default max size
GenStack<sTemp>::GenStack()
{
	sArray = new sTemp[128];
	size = 128;
	head = -1;
}


//constructor with ajustable size
template <class sTemp>
GenStack<sTemp>::GenStack(int size)
{
	sArray = new sTemp[size];
	this->size = size;
	head = -1;
}

template <class sTemp>
//destructor 
GenStack<sTemp>::~GenStack()
{
	delete[] sArray;
}

template <class sTemp>
void GenStack<sTemp>::push(sTemp X)
{
	//add the stack to the top of the stack (aka the head)
	X = sArray[++head];
}

//returns and removes values from the stack after it is imcremented
template <class sTemp>
sTemp GenStack<sTemp>::pop()
{
	if (isEmpty != true)
	{
		return sArray[head--];
	}
	else
	{
		//throw error
	}	
}

//returns the top element in the stack
template <class sTemp>
sTemp GenStack<sTemp>::peek()
{
	return sArray[head];
}

//checks to see if the stack is full
template <class sTemp>
bool GenStack<sTemp>::isFull()
{
	return(head == size - 1);
}

//checks to see if the stack is full?
template <class sTemp>
bool GenStack<sTemp>::isEmpty()
{
	return(head == -1);
}
*/
