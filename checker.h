/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Syntax Checker*/

#include <iostream>
#include "GenStack.h"

using namespace std;

class Checker
{
public:
	//constructor that takes in a file name
	Checker(string fileLocation);
	//destructor
	~Checker();
	GenStack<char>* symbolStack;
	GenStack<int>* locationStack;

	void readFile(string inFileName);
	//void checkDelim();
	void checkDelim2();
};