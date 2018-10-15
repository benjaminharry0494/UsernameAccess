#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream> 
#include <vector>
#include <limits>
#include "ctype.h"
#include "User.h"

using namespace std;

ifstream fileobj; // Text document object

string inputName; // input data

int lineCount = 0; // counts lines of document

int maxUsers = 40;

int inputNumber;  // input data 

stringstream numberCheck; //stringstream to search for ints in strings

bool errorCheck; // basic checking
bool accessCheck; // basic checking

vector <User> users; // stores strings for usernames and number data down below

vector <string> arrayOfUsernames; // stores first part of a string until a space, max 5 characters

vector <string> arrayOfNumbers; // stores remainer of string

void getFileData(); // scans document

void welcomeCin(); // UI and user input 

int init_access(char*); // checks document validation and link

bool incorrect_input(string); // checks input from user

//void outputUsernameData(string); // from previous version where was working through logic 

int has_access(char*, int); // searches username that corresponds to screen in class

//void extractNumbersAsInts(int); // from previous version where was working through logic 



