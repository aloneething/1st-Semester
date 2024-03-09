# include <iostream>
# include <cstring>
# include "adminfunction.cpp"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void admin ()
	{
	char user [20];
	char pass [20];
	int counter = 0;
	char username [100];
	char password [100];
	
	cout << "\n\nWelcome to " << HIGHLIGHT_GREEN << "\033[1mAdmin's Portal!\033[0m " << HIGHLIGHT_END;
	cout << "Login Through Here.";
	
	while (counter == 0)
		{
		cout << "\n\nUsername: ";
		cin.getline (user, 20);
		cout << "Password: ";
		cin.getline (pass, 20);
		
		fstream login;
		login.open ("admin_login.txt", ios::in | ios::app);
	
		
		while (login >> username >> password)
			{
			if (strcmp(user, username) == 0 && strcmp(pass, password) == 0)
				{
		                counter++;
		                break;
				}
			}
			
		if (counter > 0)
			{
			cout << HIGHLIGHT_GREEN << "\nLogin Successful." << HIGHLIGHT_END << endl;
			adminfunction ();
			}
		else 
			{
			cout << HIGHLIGHT_RED <<"\nWrong Email or Password." << HIGHLIGHT_END << "\nPlease try again.";
			}
		}
		
	}
