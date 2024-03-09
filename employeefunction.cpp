# include <iostream>
# include <fstream>
# include "employee_function.h"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void employeefunction ()
	{
	char choice;
	
	cout << "\n\033[1mPlease choose from the provided options.\033[0m \n\n1. Take Order\n2. Search Items\n3. See Online Scheduled Orders\n4. See Pending Notifications\n\nEnter the specified number: ";
	again:	cin >> choice;
	cin.ignore ();
	
	switch (choice)
		{
		
		case '1':
			{
			
			best_sell ();
			break;
			}
			
		case '2':
			{
			
			search_all_employee ();
			break;
			}
			
		case '3':
			{
			
			see_online_e ();
			break;
			}
			
		case '4':
			{
			
			noti_e ();
			break;
			}
			
		default:
			{
			cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
			goto again;
			}
		
		}
		
	}
