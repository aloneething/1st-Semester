# include <iostream>
# include <fstream>
# include "admin_function.h"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void adminfunction ()
	{
	char choice1, choice2;
	
	cout << "\n\033[1mPlease choose your preference.\033[0m \n\n1. See Stock\n2. Handle Stock\n3. Add/Remove Staff/Customers' Credential\n4. Handle Notifications\n5. See Online Orders\n6. See Complaints\n7. See Bestseller Employee\n8. Search the Stock\n9. See Statistics\n\nEnter the specified number: ";
	again:	cin >> choice1;
	cin.ignore ();
	
	switch (choice1)
		{
		
		case '1':
			{
			
			stock_noti ();
			break;
			}
			
		case '2':
			{
			
			see_stock ();
			
			cout << "\n\n\033[1mPlease choose from the following options:\033[0m \n\n1. Add a Stock Item\n2. Remove a Stock Item\n3. Update Price of Certain Stock\n4. Order Items of Certain Stock\n\nEnter the specified number: ";
			start1:	cin >> choice2;
			cin.ignore ();
			
			switch (choice2)
				{
				
				case '1':
					{
					
					add ();
					break;
					}
					
				case '2':
					{
					
					remove ();
					break;
					}
					
				case '3':
					{
					
					update_price ();
					break;
					}
					
				case '4':
					{
					
					update_items ();
					break;
					}
					
				default:
					{
					
					cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
					goto start1;
					}
				
				}
				
			break;
			}
			
		case '3':
			{
			
			login_employee ();
			break;
			}
				
		case '4':
			{
			
			noti_a ();
			break;
			}		
						
			
		case '5':
			{
			
			see_online ();
			break;
			}
			
		case '6':
			{
			
			see_comp ();
			break;
			}
			
		case '7':
			{
			
			best_sell_admin ();
			break;
			}
			
		case '8':
			{
			
			search_all_admin ();
			break;
			}
			
		case '9':
			{
			
			statistics ();
			break;
			}
			
		default:
			{
			cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
			goto again;
			}
			
		}
	
	}
