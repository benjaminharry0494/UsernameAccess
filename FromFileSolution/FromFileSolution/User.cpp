#include "User.h"

User::User(char* username, string access) 
{
	setUsername(username);
	setAccess(access);

}

User::User()
{
}

void User::setUsername(char* username) 
{
	Username = username;
}

void User::setAccess(string access) 
{
	Access = access;
}

string User::getAccess()
{
	return Access;
}

char* User::getUsername() 
{
	return Username;
}

User::~User()
{
}
