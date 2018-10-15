#include "Main.h"


// main
int main()
{
	// calls to get data from txt doc
	getFileData();
	// calls to open UI 
	welcomeCin();

	return 0;

}

void welcomeCin() 
{
	Restart:
		cout << "Please enter a valid username to check for the screens they have access to:" << endl;
		cout << "Or simply type exit to exit." << endl;
		std::cin >> inputName;

		errorCheck = incorrect_input(inputName);
		// validation check
		if (!errorCheck)
		{
			std::cout << "Please enter a valid username." << std::endl;
			Sleep(1500);
			system("cls");
			goto Restart;
		}

		//cast from string to char* to parse into next function
		char* input_str;
		input_str = new char[inputName.size() + 1];
		memcpy(input_str, inputName.c_str(), inputName.size() + 1);


		cout << "Please enter the screen you want to check: " << endl; 
		std::cin >> inputNumber;
		// returns true / false 
		accessCheck	= has_access(input_str, inputNumber);
		if (!accessCheck) 
		{
			std::cout << "The username does not have access to this screen." << std::endl;
			std::cout << "-------------------------------------------------------" << std::endl;
			goto Restart;
		}
		if (accessCheck) 
		{
			std::cout << "The username does have access to this screen." << std::endl;
			std::cout << "-------------------------------------------------------" << std::endl;
			goto Restart;
		}
}

void getFileData() 
{

	//open file to read
	fileobj.open("Text.txt");

	if (fileobj.fail()) 
	{
		// if file can't open exits program
		std::cout << "Unable to find file path" << std::endl;
		exit(EXIT_FAILURE);
	}
	else 
	{

		string lines;
		string emptyString;

		// run for each line of the txt file
		while (getline(fileobj, lines)) 
		{
			lineCount++;
			// checks for length of document
			if (lineCount >= maxUsers) 
			{
				std::cout << "Document contains too many entries.." << std::endl;
				std::cout << "System closing in two seconds..." << std::endl;
				system("cls");
				exit(EXIT_FAILURE);
			}

			int positionOfIndex = 0;

			int spacePosition[5];
			// search for first part of string to seperate numbers from username
				for (int i = 0; i < lines.length(); i++)
				{
					if (lines[i] == ' ')
					{
						spacePosition[positionOfIndex] = i;
						positionOfIndex++;
					}
				}
			// substring for username
			string username = lines.substr(0, spacePosition[0]);
			arrayOfUsernames.push_back(username);

			// Successfully aquires access information
			string access = lines.substr(spacePosition[0]);
			arrayOfNumbers.push_back(access);
			
			// successfully converts username to char*
			char *usernameFinal;
			usernameFinal = new char[username.size() + 1];
			memcpy(usernameFinal, username.c_str(), username.size() + 1);

			// arrayOfUsernames.size() == arrayOfNumbers.size() - process both strings into seperate class for getters / setters
			for (int i = 0; i < arrayOfUsernames.size(); i++)
			{
				users.push_back(User(usernameFinal, access));
			}

			// check for validation in txt document. Better to have it above but is a small change.
			init_access(usernameFinal);
		}

	}


}

int init_access(char* file_path) 
{
	
	std::string file_pathstr(file_path);

	if (fileobj.fail()) 
	{
		std::cout << "Unable to find file path..." << std::endl;
		std::cout << "System closing in two seconds..." << std::endl;
		system("cls");
		exit(EXIT_FAILURE);
		return 0;
	}
	// checks for valid documentation of usernames
	if (file_pathstr.length() > 5) 
	{
		std::cout << "Invalid format..." << std::endl;
		std::cout << "System closing in two seconds..." << std::endl;
		system("cls");
		exit(EXIT_FAILURE);
	}
	// if exit is saved into document closes document 
	if (file_pathstr == "exit" || file_pathstr == "Exit") 
	{
		std::cout << "Invalid username please change exit is a system command..." << std::endl;
		std::cout << "System closing in two seconds..." << std::endl;
		system("cls");
		exit(EXIT_FAILURE);
	}
}

bool incorrect_input(string inputName)
{


	// returns invalid
	if (inputName.length() > 5)
	{
		return false;
	}
	if (inputName.length() < 1) 
	{
		return false;
	}
	// exit command
	if (inputName == "exit" || inputName == "Exit") 
	{
		exit(EXIT_FAILURE);
	}

	// if name matches name on array of usernames >> valid input 
	for (int i = 0; i < arrayOfUsernames.size(); i++)
	{
		if (arrayOfUsernames[i] == inputName) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

}

int has_access(char* user_name, int screen)
{
	char* temp;

	for (int i = 0; i < users.size(); i++)
	{
		// temporary value for stringstream 
		temp = users[i].getUsername();
		// if entered value matches value in class
		if (temp == user_name)
		{
			// getAccess returns long string with numbers
			string temp_str = users[i].getAccess();
			// checks for integer values and if found sets numberCheck to temp_str
			numberCheck << temp_str;
			// second temporary string for numbercheck to hold later
			string temp_str2;
			int tempInt = 0;
			//while it isn't at the end of stringsteam number check continue 
			while (!numberCheck.eof())
			{
				// number check into tempstring 2
				numberCheck >> temp_str2;
				// searches for integers in temp_str2 and sets them as temp int
					if (stringstream(temp_str2) >> tempInt)
					{
						// if temp int == user input
						if (tempInt == screen)
						{
							return true;
						}
					}
					return false;
			}
		}
	}
}

// from previous version where was working through logic 

//void outputUsernameData(string inputName) 
//{
//	for (int i = 0; i < arrayOfUsernames.size(); i++) 
//	{
//		if (arrayOfUsernames[i] == inputName) 
//		{
//			cout << "Username: " << arrayOfUsernames[i] << endl;
//			cout << "Has access to screens: " << arrayOfNumbers[i] << endl;
//			cout << "---------------------------------------------------------" << arrayOfNumbers[i] << endl;
//		}
//	}
//
//}
//
//void extractNumbersAsInts(int input)
//{
//
//	for (int i = 0; i < arrayOfNumbers.size(); i++) 
//	{
//		string test = arrayOfNumbers[i];
//		int testInt = 0;
//
//		numberCheck << test;
//		string temp;
//		int tempInt = 0;
//
//		while (!numberCheck.eof())
//		{
//			numberCheck >> temp;
//			
//			if (stringstream(temp) >> tempInt) 
//			{
//				cout << tempInt << endl;
//			}
//			temp = "";
//		}
//	}
//}