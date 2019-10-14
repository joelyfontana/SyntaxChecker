/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Syntax Checker*/

#include <iostream>
using namespace std;

//CONTAINS BOTH THE HEADER AND THE IMPLEMENTATION FILES!!!

template <class sTemp>
class GenStack
{
public:
	//declaring a pointer (lets the user define the size in the constructor)
	sTemp* sArray;
	int head;
	int size;

	//make a private function to resize the array (automatically private because it is not under the public thing
	void resizeArray()
	{
		//make a new array
		sTemp* newArray;
		//make a new array double the size
		newArray = new sTemp[size*2];
		//copy the old array into the new array
		for (int i = 0; i < size; i++)
		{
			newArray[i] = sArray[i];
		}

		//delete the old array
		delete[] sArray;
		//reset the variable name for the new array
		sArray = newArray;
		//set the new size
		size = size * 2;
	}

public: 
	//constructor
	GenStack()
	{
		sArray = new sTemp[128];
		size = 128;
		head = -1;
	}

	//overloaded constructor
	GenStack(int maxSize)
	{
		sArray = new sTemp[size];
		size = maxSize;
		head = -1;
	}
	//destructor 
	~GenStack()
	{
		delete[] sArray;
	}

	//functions needed in a stack
	void push(sTemp X)
	{
		//add the stack to the top of the stack (aka the head)
		sArray[++head] = X;
	}
	sTemp pop()
	{
		if (isEmpty() != true)
		{
			return sArray[head--];
		}
		else
		{
			throw runtime_error("Cannot pop - The stack is empty.");
		}
	}
	sTemp peek()
	{
		return sArray[head];
	}
	bool isEmpty()
	{
		return(head == size - 1);
	}

	bool isFull()
	{
		//if the array is full, call the resize function
		resizeArray();
		return(head == -1);
	}
};



