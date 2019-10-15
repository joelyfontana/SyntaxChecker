/*Joely Fontana
Student ID : 2313535
Data Structures
Section 1
Syntax Checker*/

#include <iostream>
#include <fstream>
#include "checker.h"
using namespace std;

//DECLARE VARIABLES
string fileLocation;

int main(int argc, char** argv)
{
	//error checking to make sure that the user enters the file in the command prompt
	if (argc != 2)
	{
		cout << "Please enter the name of the file in the command prompt" << endl;
		return 0;
	}

	//get the file from the command line and error check

		string fileLocation;
		fileLocation = argv[1];
	/*catch (runtime_error e)
	{
		cout << "That file does not exist. Please enter an existing file." << endl;
		exit the program if the file does not exist
		return 1;

	}*/
	
	//if the user wants to check another file
	string answer = "yes";
	while (answer == "yes")
	{
		//open the file 
		ifstream file;
		//error checking if a delimiter is missing
		try
		{
			Checker checky(fileLocation);
			cout << "All good bro.\n";
		}
		catch (runtime_error e)
		{
			cout << e.what() << endl;
			//cout << "The program will now exit." << endl;
			return 0;
		}
		//see if the user would like to enter another file
		cout << "Would you like to enter another file to check? (yes/no): " << endl;
		cin >> answer;
		//if the user wants to enter another file
		if (answer == "yes")
		{
			cout << "Please enter the name of the file you wish to check: " << endl;
			cin >> fileLocation;
		}
		continue;
	}
	cout << "Goodbye!" << endl;
	return 0;
}

