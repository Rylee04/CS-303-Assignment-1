// CS 303 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Ryan Lee
// CS 303 Assignemnt 1
// Due date: 9/11
#include <iostream>
#include <vector>
#include "Functions.h"
using namespace std;


int main() {
    
    // Initializing our array of numbers
    vector<int> numbers;
    // Calling the readFile function to open the text file containing the list of integers and populating the array
    readFile(numbers);

    // Prints the menu and gets user input
    char choice = menu();

    // If block determining what to perform based on user input
    while (choice != '5') {
        if (choice == '1') {
            // Calls findNumber function to find a specific number in the file
            findNumber(numbers);
        }
        else if (choice == '2') {

            // Try/catch block checking if user input is an integer
            try {

                // Asking user for the target index to modify
                int target = -1;
                if (cout << "Which index (starting at 0) would you like to modify?: " && !(cin >> target)) {
                    throw runtime_error("error");
                }

                // Asking user for the integer to change the target index into
                int value = -1;
                if (cout << "What integer would you like to change it to?: " && !(cin >> value)) {
                    throw runtime_error("error");
                }

                // Calls the modNumber function
                cout << "The number " << modNumber(numbers, &target, &value) << " at index " << target << " was changed to " << value << endl << endl;
            
            }
            catch (...)  {

                // Catches thrown exception and clears user input
                cerr << "Invalid input" << endl << endl;
                cin.clear();

            }
        }
        else if (choice == '3') {
            // Calls the addNumber function to add a number to the end of the list
            addNumber(numbers);
        }
        else if (choice == '4') {
            // Calls the delNumber function to either delete or replace an index with 0
            delNumber(numbers);
        }

        // Prints menu and gets input again until '5' is inputted
        choice = menu();

    }

    








    
    





}