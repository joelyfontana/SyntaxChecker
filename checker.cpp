/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Syntax Checker*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include "checker.h"
#include <string>
using namespace std;

string line;
string tmp;
int lineNum = 0;
int rightPCount =0,leftPCount =0, rightBCount=0, leftBCount=0, rightWCount=0, leftWCount=0;
string answer;
//constructor for both stacks
Checker::Checker(string fileLocation)
{
	//initialize the stacks (using pointers)
	symbolStack = new GenStack<char>();
	locationStack = new GenStack<int>();
	//call the read file function
	readFile(fileLocation);
	checkDelim2();
}

//destructor
Checker::~Checker()
{
	//call the deconstructor
	symbolStack ->~GenStack();
	locationStack->~GenStack();
}

// reads the file
void Checker::readFile(string inFileName)
{
	//make a file object
	ifstream inFile;
	//open the file
	inFile.open(inFileName);
	cout << "filename: " << inFileName << endl;

	//check to make sure the file is open and if not throw an error
	if (!inFile)
	{
		throw runtime_error("The file you entered could not be opened");
	}

	// if the file is open and working 
	while (getline(inFile, line))
	{
		bool inQuotes = true;
		//iterate through the file
		for (int i = 0; i < line.length(); ++i)
		{
			//check to see if the delimiter is in quotations - if so forget it exists
			if (line[i] == '\"' || line[i] == '\'')
			{
				if (inQuotes == false)
				{
					inQuotes = true;
					cout << "true" << endl;
				}
				else
				{
					cout << "false" << endl;
					inQuotes = false;
				}
			}
			if (inQuotes == false)
			{
				continue;
			}
			//	cout << "entered bool loop" << endl;
				//check to see if the file has a parathesis and add it to the correct count
				if (line[i] == '(')
				{
					leftPCount++;
					symbolStack->push('(');
					locationStack->push(lineNum);
				}
				if (line[i] == ')')
				{
					rightPCount++;
					symbolStack->push(')');
					locationStack->push(lineNum);
				}
				if (line[i] == '[')
				{
					leftBCount++;
					symbolStack->push('[');
					locationStack->push(lineNum);
				}
				if (line[i] == ']')
				{
					rightBCount++;
					symbolStack->push(']');
					locationStack->push(lineNum);
				}
				if (line[i] == '{')
				{
					leftWCount++;
					symbolStack->push('{');
					locationStack->push(lineNum);
				}
				if (line[i] == '}')
				{
					rightWCount++;
					symbolStack->push('}');
					locationStack->push(lineNum);
				}
				
			
		}
		lineNum++;
		cout << "lineNum: " << lineNum << " " << line << endl;
		
	}
	
	cout << "leftPCount: " << leftPCount << endl;
	cout << "rightPCount: " << rightPCount << endl;
	cout << "leftBCount: " << leftBCount << endl;
	cout << "rightBCount: " << rightBCount << endl;
	cout << "leftWCount: " << leftWCount << endl;
	cout << "rightWCount: " << rightWCount << endl;
}

//void Checker::checkDelim()
//{
//	cout << "sArray: " << symbolStack->sArray << endl;
//	//check to see if there is an even number of delimiters
//	//if there is an even number the file is fine, and exit the program.
//	if ((rightPCount + leftPCount) % 2 == 0 && (rightBCount + leftBCount) % 2 == 0 && (rightWCount + leftWCount) % 2 == 0)
//	{
//		cout << "The file has no missing delimiters. You're good bro." << endl;
//	}
//
//	//if there is an odd number of delimiters it means one is missing
//	else
//	{
//		//if missing a parenthesis
//		if (leftPCount < rightPCount)
//		{
//			if (symbolStack->sArray[1] != '(')
//			{
//				if (symbolStack->sArray[1] != '[')
//				{
//					string message = "Expecting '(', found '[' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//				if (symbolStack->sArray[1] != '{')
//				{
//					string message = "Expecting '(', found '{' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//			}
//		}
//		if (leftPCount > rightPCount)
//		{
//			if (symbolStack->sArray[2] != ')')
//			{
//				if (symbolStack->sArray[2] == ']')
//				{
//					string message = "Expecting ')', found ']' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//				if (symbolStack->sArray[2] == '}')
//				{
//					string message = "Expecting ')', found '}' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//			}
//		}
//		//if missing a bracket
//		if (leftBCount < rightBCount)
//		{
//			cout << "SYmbolStack array 3: " << symbolStack->sArray[3] << endl;
//			if (symbolStack->sArray[3] != '[')
//			{
//				if (symbolStack->sArray[3] == '(')
//				{
//					string message = "Expecting '[', found '(' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//				if (symbolStack->sArray[3] != '{')
//				{
//					string message = "Expecting '[', found '{' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//			}
//		}
//		if (leftBCount > rightBCount)
//		{
//			if (symbolStack->sArray[4] != ']')
//			{
//				if (symbolStack->sArray[4] != ')')
//				{
//					string message = "Expecting ']', found ')' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//				if (symbolStack->sArray[4] != '}')
//				{
//					string message = "Expecting ']', found '}' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//			}
//		}
//		//if missing a wiggly bracket
//		if (leftWCount < rightWCount)
//		{
//			if (symbolStack->sArray[5] != '{')
//			{
//				if (symbolStack->sArray[5] != '(')
//				{
//					string message = "Expecting '{', found '(' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//				if (symbolStack->sArray[5] != '[')
//				{
//					string message = "Expecting '{', found '[' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//			}
//		}
//		//check to see if the user forgot the last closing wiggly bracket at the end of the file
//		if (leftWCount > rightWCount)
//		{
//			if (symbolStack->sArray[6] != symbolStack->peek())
//			{
//				if (symbolStack->sArray[6] != ')')
//				{
//					string message = "Expecting '}', found ')' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//				if (symbolStack->sArray[6] != ']')
//				{
//					string message = "Expecting '}', found ']' at line " + to_string(locationStack->peek());
//					throw runtime_error(message);
//				}
//			}
//			if (symbolStack->peek() != '}')
//			{
//				string message = "You are missing a '}' at the end of your file (line  " + to_string(lineNum + 1) + ')';
//				throw runtime_error(message);
//			}
//		}
//
//		//reset the values
//		rightPCount = 0, leftPCount = 0, rightBCount = 0, leftBCount = 0, rightWCount = 0, leftWCount = 0, lineNum = 1;
//	}
//}


void Checker::checkDelim2()
{
	//make sure the stack is not empty
	while (symbolStack->isEmpty() == false)
	{
		//get the top element in the stack and pop it
		char currentD = symbolStack->pop();
		//cout << "currentD: " << currentD << endl;
		//iterate through the stack and check to see if hey are paired
		for (int i = 0; i <= symbolStack->head+1; ++i)//may need to swap this
		{
			cout << "symbolstack: " << symbolStack->sArray[i] << endl;

			if (currentD == '(')
			{
				if (symbolStack->sArray[i] == ')')
				{
					break;
				}
				else if(symbolStack->sArray[i] == '}')
					{
					cout << "fuck" << endl;
					string message = "Expected ')', found '}'";
					throw runtime_error(message);
					}
				else if (symbolStack->sArray[i] == ']')
				{
					string message = "Expected ')', found ']'";
					throw runtime_error(message);
				}
			}
			if (currentD == '{')
			{
				if (symbolStack->sArray[i] == '}')
				{
					break;
				}
				else if (symbolStack->sArray[i] == ')')
				{
					cout << "fuck2" << endl;
					string message = "Expected '}', found ')'";
					throw runtime_error(message);
				}
				else if (symbolStack->sArray[i] == ']')
				{
					string message = "Expected '}', found ']'";
					throw runtime_error(message);
				}
			}
			if (currentD == '[')
			{
				if (symbolStack->sArray[i] == ']')
				{
					break;
				}
				else if (symbolStack->sArray[i] == '}')
				{
					string message = "Expected ']', found '}'";
					throw runtime_error(message);
				}
				else if (symbolStack->sArray[i] == ')')
				{
					string message = "Expected ']', found ')'";
					throw runtime_error(message);
				}
			}
		}
	}
}