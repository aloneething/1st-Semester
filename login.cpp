# include <iostream>
# include <fstream>
# include <string>
# include "admin.h"
# include "employee.h"
# include "customer.h"
# include "HADITH.cpp"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void login ()
	{
	char status;

	cout << "\n\033[1mCafé Digital System\033[0m\n\nChoose your status:\n\n1. Admin\n2. Employee\n3. Student/Staff\n\n" << HIGHLIGHT_YELLOW << "OR" << HIGHLIGHT_END << "\n\n4. Hadith of the Day\n\nEnter your preference: ";
	start:    cin >> status;
	cin.ignore ();
	
	switch (status)
		{
		
		case '1':
			{
			
			admin ();
			break;
			}
		
		case '2':
			{
			
			employee ();
			break;
			}
			
		case '3':
			{
			
			customer ();
			break;
			}
			
		case '4':
			{
			
			good_things ();
			break;
			}
			
		default:
			{
			cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
			goto start;
			}
			
		}
	}
