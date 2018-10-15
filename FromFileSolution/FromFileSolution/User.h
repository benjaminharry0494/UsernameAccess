#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <sstream> 
#include <vector>
#include "ctype.h"

using namespace std;

// basic class for user with getters / setters
class User
{
private:
	char* Username;
	string Access;

	void setUsername(char* Username);

	void setAccess(string Access);

public:
	User();
	User(char* username, string access);
	~User();

	char* getUsername();
	string getAccess();
};

