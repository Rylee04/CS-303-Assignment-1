// Functions.cpp file. This file contains the implementation of functions
#include <fstream>
#include <vector>
#include "Functions.h"
using namespace std;

// Prints the menu
char menu() {

	// Resets user input
	char choice = '0';

	// Displays the options
	cout << "Press which number option to perform" << endl
		 << "1: Find a number" << endl
		 << "2: Modify a number" << endl
		 << "3: Add a number" << endl
		 << "4: Delete a number" << endl
		 << "5: Quit program" << endl;
	
	// Continually accepts inputs until one matches a valid option
	while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5') {
		cin >> choice;
	}

	return choice;

}

// Reads text file
vector<int> readFile(vector<int> &numbers) {

	// Opens designated file
	ifstream inFile("listOfIntegers.txt");
	// While the file is open and has elements
	if (inFile.is_open()) {
		while (inFile.good()) {

			// Populates array with elements from file
			int elem;
			inFile >> elem;
			numbers.push_back(elem);
			
		}
	}
	else {
		// Basic error message
		cout << "File not found";
	}

	inFile.close();
	return numbers;

}

// Looks for a specific number in list
int findNumber(vector<int> numbers) {

	int check = 0;
	int findTarget = -1;

	// Loops until an integer is inputted
	while (cout << "What number are you trying to find?: " && !(cin >> findTarget)) {

		// Clears user input and prints error message
		cin.clear();
		cin.ignore();
		cout << "Invalid input; try again" << endl;

	}

	// Iterates through list looking for designated number
	for (int i = 0; i < numbers.size(); i++) {
		if (numbers[i] == findTarget) {
			// Prints index(es) if the number is found
			cout << "Target number found at index: " << i << endl;
			check = 1;
		}
	}
	
	// Output if no matching number was found
	if (check == 0) {
		cout << "No numbers were found" << endl;
	}

	cout << endl;
	return 0;

}

// Modifies a number
int modNumber(vector<int>& numbers, int* target, int* value) {

	// Copies original value in target index to return
	int modIndex = *target;
	int oldNum = numbers[modIndex];
	// Sets new number into target index
	numbers[*target] = *value;

	return oldNum;

}

// Adds a number to the end of the list
vector<int> addNumber(vector<int> &numbers) {
	
	// Try/catch block checking if user input is integer
	try {

		int newNumber;
		if (cout << "What number would you like to add?: " && !(cin >> newNumber)) {
			throw runtime_error("error");
		}
		numbers.push_back(newNumber);
		cout << newNumber << " successfully added to list" << endl << endl;
	}
	catch (...) {

		cerr << "Invalid input" << endl << endl;
		cin.clear();

	}

	return numbers;

}

// Deletes or replaces target index
vector<int> delNumber(vector<int>& numbers) {

	int delIndex;
	while (cout << "What index (starting at 0) would you like to delete?: " && !(cin >> delIndex)) {

		cin.clear();
		cin.ignore();
		cout << "Invalid input; try again" << endl;

	
	}

	// Gets user input on whether they want to delete the index or replace it with 0
	char delChoice = 'z';
	while (toupper(delChoice) != 'D' && toupper(delChoice) != 'R' && toupper(delChoice) != 'Q') {
		cout << "Press D to delete or R to replace index with 0 (Q to cancel): ";
		cin >> delChoice;
	}

	if (toupper(delChoice) == 'R') {
		numbers[delIndex] = 0;
		cout << "Number successfully replaced with 0" << endl << endl;
	}
	else if (toupper(delChoice) == 'D') {
		numbers.erase(numbers.begin() + delIndex);
		cout << "Number successfully erased" << endl << endl;
	}
	else if (toupper(delChoice) == 'Q') {
		cout << "Cancelled operation" << endl << endl;
	}

	return numbers;

}