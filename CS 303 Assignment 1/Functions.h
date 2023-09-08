// Functions.h file. This file contains the headers for functions
#pragma once
#include <iostream>
using namespace std;


char menu();

vector<int> readFile(vector<int> &numbers);

int findNumber(vector<int> numbers);

int modNumber(vector<int>& numbers, int* target, int* value);

vector<int> addNumber(vector<int> &numbers);

vector<int> delNumber(vector<int>& numbers);