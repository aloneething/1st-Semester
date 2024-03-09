# include <iostream>
# include "customer_function.h"
# include "game.cpp"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void customerfunction ()
	{
	char choice;
	
	cout <<"\n\033[1mWelcome to CDS. Please choose from the provided options.\033[0m \n\n1. Search and Order\n2. Make a Complaint\n3. Search Items\n4. Schedule an Order\n5. See Pending Notifications\n6. " << HIGHLIGHT_YELLOW << "Wanna play a game?" << HIGHLIGHT_END << "\n\nEnter the specified number: ";
	start:	cin >> choice;
	cin.ignore ();
	
	switch (choice)
		{
		
		case '1':
			{
			
			customer_order ();
			break;
			}
			
		case '2':
			{
			
			complaint ();
			break;
			}
			
		case '3':
			{
			
			search_all_c ();
			break;
			}
			
		case '4':
			{
			
			online_order_customer ();
			break;
			}
			
		case '5':
			{
			
			noti_c ();
			break;
			}
			
		case '6':
			{
			
			//For Bonus Marks
			rock_paper_scissors ();
			break;
			}
			
		default:
			{
			cout << HIGHLIGHT_RED << "\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
			goto start;
			}
		
		}
	
	}
