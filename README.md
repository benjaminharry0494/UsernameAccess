# UsernameAccess
Part 2)


Either using C/C++ or C# Write 2   functions, one that reads a text file for some entries that correspond to a username of up to 5 characters and a set of numbers 1-9 for each user that correspond to the screens that user has access to. This function should build up some kind of structure that can be examined later to determine if a user should be allowed access to a screen.
the prototype for this function is:

/*return 0/false if file is not found or incorrectly formatted., otherwise 1/true */
int init_access(char* file_path); C/C++

bool init_access(string file_path); C#

the function then called to determine if a particular username should be allowed to access a screen has the prototype:

/*returns 1/true if a user has access to a given screen or 0/false otherwise*/
int has_access(char* user_name, int screen); C/C++

bool has_access(string user_name, int screen); C#


write the definition for these 2 functions, an example main function that calls them. 
The format of the text file will be as below.

john 1 2 3 4 5

paulc 4 5 6

jo 1 9 8

