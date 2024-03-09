# include <iostream>
# include <cstring>
# include "employeefunction.cpp"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void employee ()
	{
	char user [20];
	char pass [20];
	int counter = 0, i = 0;
	char username [15][20];
	char password [15][20];
	char head [100];
	
	cout << "\n\nWelcome to " << HIGHLIGHT_GREEN << "\033[1mEmployee's Portal!\033[0m " << HIGHLIGHT_END;
	cout << "Login Through Here.";
	
	fstream login;
	login.open ("employee_login.txt", ios::in | ios::app);
	
	login.getline (head, 100, '\n');
	
	while (counter == 0)
		{
		cout << "\n\nEmail: ";
		cin.getline (user, 20);
		cout << "Password: ";
		cin.getline (pass, 20);
		
		while (login >> username [i] >> password [i])
			{
			i++;
			}
			
		for (int j = 0; j < i; j++)
			{
			if (strcmp(user, username [j]) == 0 && strcmp(pass, password [j]) == 0)
				{
				cout << HIGHLIGHT_GREEN << "\nLogin Successful." << HIGHLIGHT_END << endl;
				counter++;
				employeefunction ();
			        break;
			        }
			}
				
		if (counter == 0)
			{
			cout << HIGHLIGHT_RED <<"\nWrong Email or Password." << HIGHLIGHT_END << "\nPlease try again.";
			}

		}
		
	}
