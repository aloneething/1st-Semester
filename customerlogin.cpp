# include <iostream>
# include <fstream>
# include <cstring>
# include "customerfunction.cpp"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void customer ()
	{
	char choice;
	
	cout << "\n\nWelcome to " << HIGHLIGHT_GREEN << "\033[1mCustomer's Portal!\033[0m " << HIGHLIGHT_END;
	cout << "\n\nPlease choose from the options below.\n\n1. Register Yourself\n2. Already Registered / Login\n3. Continue as Guest\n\nEnter the specified number: ";
	start:	cin >> choice;
	cin.ignore ();
	
	switch (choice)
		{
		case '1':
			{
			char user_r [20];
			char pass_r [20];
			
			fstream register_c;
			register_c.open ("customer_login.txt", ios::app | ios::out);
			
			cout << "\nRegister Yourself Here.\n";
			cout << "\nYour Preferred Username: ";
			cin.getline (user_r, 20);
			cout << "Your Preferred Password: ";
			cin.getline (pass_r, 20);
			
			if (register_c.is_open ())
				{
				register_c << user_r << "\t" << pass_r << endl;
				}
			else
				{
				cout << "\nFine Not Found." << endl << endl;
				}
			
			register_c.close ();
			}
			
		case '2':
			{
			char user [20];
			char pass [20];
			int count = 0;
			char username [20];
			char password [20];
			
			fstream login_c;
			login_c.open ("customer_login.txt", ios::in);
			
			cout << "\nLogin Through Here.\n";
			
			while (count == 0)
				{
				cout << "\nUsername: ";
				cin.getline (user, 20);
				cout << "Password: ";
				cin.getline (pass, 20);
				
				if (login_c.is_open ())
					{
					while (login_c >> username >> password)
						{
						if (strcmp(user, username) == 0 && strcmp(pass, password) == 0)	
							{
							count++;
							break;
							}
						}
					
					if (count > 0)
						{
						cout << HIGHLIGHT_GREEN << "\nLogin Successful." << HIGHLIGHT_END << endl;
						customerfunction ();
						}
					else
						{
						cout << HIGHLIGHT_RED <<"\nWrong Email or Password." << HIGHLIGHT_END << "\nPlease try again.";
						}
					}
				else 
					{
					cout << "\nFine Not Found." << endl << endl;
					}
				}
			break;
			}
			
		case '3':
			{
			customerfunction ();
			break;
			}
			
		default:
			{
			cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
			goto start;
			}
			
		}
	}
