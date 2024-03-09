# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
# include "customer.h"
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void dataSort (char** name, int* items, int* price, int n)
	{
	for (int i = 0; i < n - 1; i++)
		{
	        for (int j = 0; j < n - i - 1; j++)
	        	{
            		if (items[j] > items[j + 1])
            			{
                		swap(items[j], items[j + 1]);
                		swap(name[j], name[j + 1]);
                		swap(price[j], price[j + 1]);
            			}
        		}
    		}
	}
	
void order (char** name, int* items, int* price, int i, int &bill)
	{
	int choice1, choice2;
	string choice4;
	
	start3:	cout << "\nEnter your choice: ";
	start6:	cin >> choice1;
	choice1 -= 1;
	
	while (choice1 < 0)
		{
		cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
		cin >> choice1;
		choice1 -= 1;
		}
		
	for (int j = 0; j < i; j++)
		{
		if (j == choice1)
			{
			if (items[j] == 0)
				{
				cout << "\nYou " << HIGHLIGHT_RED << "cannot purchase" << HIGHLIGHT_END << " as no stock is avalible for this item.\nWould you like to purchase something else? (Yes/No)" << endl;
				cout << "\nYour Choice: ";
				start4:	cin >> choice4;
				
				if (choice4 == "Yes" || choice4 == "yes" || choice4 == "YES")
					{
					goto start3;
					}
				else if (choice4 == "No" || choice4 == "no" || choice4 == "NO")
					{
					cout << "\nThank you for choosing CDS." << endl << endl;
					exit (EXIT_SUCCESS);
					}
				else
					{
					cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
					goto start4;
					}
				
				}
			else
				{	
				cout << "\nEnter quantity: ";
				start5:	cin >> choice2;
				
				if (choice2 > items[j])
					{
					cout << "\nYou " << HIGHLIGHT_RED << "cannot order" << HIGHLIGHT_END << " more than the available stock. Enter again: ";
					goto start5;
					}
				else if (choice2 <= 0)
					{
					cout << HIGHLIGHT_RED << "\nPlease choose a valid amount." << HIGHLIGHT_END << " Enter again: ";
					goto start5;
					}
				else
					{
					items[j] -= choice2;
					bill = bill + (price[j] * choice2);
					}
				}
			}
		}
	}
	
void order_online (char** name, int* items, int* price, int i, int &bill)
	{
	int choice1, choice2;
	static int counter = 0;
	string choice4;
	
	start3:	cout << "\nEnter your choice: ";
	start6:	cin >> choice1;
	choice1 -= 1;
		
	fstream online_;
	online_.open ("online_order.txt", ios::out | ios::app);
	
	while (choice1 < 0 || choice1 >= i)
		{
		cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
		cin >> choice1;
		choice1 -= 1;
		}
		
	for (int j = 0; j < i; j++)
		{
		if (j == choice1)
			{
			if (items[j] == 0)
				{
				cout << "\nYou " << HIGHLIGHT_RED << "cannot purchase" << HIGHLIGHT_END << " as no stock is avalible for this item.\nWould you like to purchase something else? (Yes/No)" << endl;
				cout << "\nYour Choice: ";
				start4:	cin >> choice4;
				
				if (choice4 == "Yes" || choice4 == "yes" || choice4 == "YES")
					{
					goto start3;
					}
				else if (choice4 == "No" || choice4 == "no" || choice4 == "NO")
					{
					if (counter == 0)
						{
						cout << "\nThank you for choosing CDS." << endl << endl;
						online_ << "Nothing." << endl << endl;
						exit (EXIT_SUCCESS);
						}
					else
						{
						return;
						}
						
					}
				else
					{
					cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
					goto start4;
					}
				
				}
			else
				{	
				cout << "\nEnter quantity: ";
				start5:	cin >> choice2;
				
				if (choice2 > items[j])
					{
					cout << "\nYou " << HIGHLIGHT_RED << "cannot order" << HIGHLIGHT_END << " more than the available stock. Enter again: ";
					goto start5;
					}
				else if (choice2 <= 0)
					{
					cout << HIGHLIGHT_RED << "\nPlease choose a valid amount." << HIGHLIGHT_END << " Enter again: ";
					goto start5;
					}
				else
					{
					counter++;
					online_ << "> " << choice2 << " pieces of " << name [j] << endl;
					items[j] -= choice2;
					bill = bill + (price[j] * choice2);
					
					online_.close ();
					}
				}
			}
		}
	}
	
void customer_order ()
{

//1st scope
{
cout << endl;

int size = 0;
char ch;

fstream file;
file.open ("stock.txt", ios::in);

while (file.get(ch))
	{
	if (ch == '\n')
	size++;
	}
	
file.clear(); //reset the end-of-file flag
file.seekg(0, ios::beg); //moving the pointer back to the beginning.

char head [200];

char **name = new char *[size];
int *items = new int[size];
int *price = new int[size];
int sr_no = 1, i = 0;
	
for (int m = 0; m < size; m++)
	{
	name [m] = new char [100];
	}

if (file.is_open ())
	{
	file.getline (head, 500, '\n');
	
	while (file >> name[i] >> items[i] >> price[i])
		{
		file.ignore();
		i++;
    		}
    	}
else
	{
	cout << "\nFile not Found." << endl << endl;
	}

//To sort the data for displaying purpose	
dataSort (name, items, price, i);

file.close ();

//Highlighting the menu
cout << HIGHLIGHT_BLACK << head << HIGHLIGHT_END << endl << endl;

for(int j = 0; j < i; j++, sr_no++)
	{
	//Highlighting if the stock is zero
	if (items [j] == 0)
		{
		cout << setw (9) << left << sr_no << HIGHLIGHT_RED << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << HIGHLIGHT_END << endl << endl;
		}
		
	else if (items [j] <= 20 && items [j] > 0)
		{
		cout << setw (9) << left << sr_no << HIGHLIGHT_YELLOW << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * 	price [j]) << HIGHLIGHT_END << endl << endl;
		}
	
	else
		{
		//Printing the menu
		cout << setw (9) << left << sr_no << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << endl << endl;
		}
	}

//2nd scope	
{
int size = 0;
char ch;
	
fstream file_;
file_.open ("stock.txt", ios::in);
	
while (file_.get(ch))
	{
	if (ch == '\n')
	size++;
	}

file_.clear(); //reset the end-of-file flag
file_.seekg(0, ios::beg); //moving the pointer back to the beginning.
	
char head [200];

char **name = new char *[size];
int *items = new int[size];
int *price = new int[size];
int sr_no = 1, i = 0, bill = 0;

for (int m = 0; m < size; m++)
	{
	name [m] = new char [100];
	}

//Reading From the Stocks File
if (file_.is_open ())
	{
	file_.getline (head, 500, '\n');
	
	while (file_ >> name[i] >> items[i] >> price[i])
		{
		file_.ignore();
		i++;
    		}
    	}
else
	{
	cout << "\nFile not Found." << endl << endl;
	}

//To sort the data for billing purpose	
dataSort (name, items, price, i);

//Updating the menu
order (name, items, price, i, bill);

string choice3;
start1: cout << "\nWould you like to order more? (Yes/No)\nYour choice: ";
start2: cin >> choice3;

if (choice3 == "Yes" || choice3 == "yes" || choice3 == "YES")
	{
	order (name, items, price, i, bill);
	goto start1;
	}
else if (choice3 == "No" || choice3 == "no" || choice3 == "NO")
	{
	cout << "\n\nThank you for ordering." << endl;
	}
else
	{
	cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
	goto start2;
	}

file_.close ();

fstream file_r;
file_r.open ("stock.txt", ios::out);

file_r << head << endl;


//Rewriting into the same file with the same indentation but updated data
for (int j = 0; j < i; j++)
	{
	file_r << name[j] << " " << items[j] << " " << price[j] << endl;
	}
	
cout << "\n\nYour billed amount will be: Rs. " << bill << "\nPlease pay at the window." << endl << endl;
	
	{
	fstream avg;
	avg.open ("avg.txt", ios::out | ios::app);
	
	if (avg.is_open ())
		{
		avg << bill << endl << " ";
		}
	else
		{
		cout << "\nFile not Found." << endl << endl;
		}
	avg.close ();
	}

file_r.close ();

//To delete DMA for 2nd scope
for (int l = 0; l < i; l++)
	{
	delete[] name[l];
	}
		
delete[] name;
delete[] items;
delete[] price;

name = NULL;
items = NULL;
price = NULL;

//End of 2nd Scope
}

//To delete DMA for 1st scope
for (int l = 0; l < i; l++)
	{
	delete[] name[l];
	}
		
delete[] name;
delete[] items;
delete[] price;

name = NULL;
items = NULL;
price = NULL;

//End of 1st Scope	
}

}

//From Here -----------------------------------------------------------------------------------------------------------	
void online_order_customer ()

{
char user_c [20];
int counter_c = 0;
cout << endl << "Enter your username for security purposes: ";
e_again:	cin.getline (user_c, 20);

fstream confirm;
confirm.open ("customer_login.txt", ios::in);

char username [20][20];
char pass [20][20];
int i = 0;

if (confirm.is_open ())
	{
	while (confirm >> username [i] >> pass [i])
		{
		i++;
		}
	}
			
for (int j = 0; j < i; j++)
	{
	if (strcmp (user_c, username [j]) == 0)
		{
		counter_c++;
		}
	}

if (counter_c == 0)
	{
	cout << HIGHLIGHT_RED << "\nInvalid Username." << HIGHLIGHT_END << " Please enter again: ";
	goto e_again;
	}
else
{
cout << HIGHLIGHT_GREEN << "\nUsername Found." << HIGHLIGHT_END << endl << endl;

fstream snip;
snip.open ("online_order.txt", ios::out | ios::app);

if (snip.is_open ())
	{
	snip << endl << HIGHLIGHT_BLACK << user_c << HIGHLIGHT_END << " came and ordered: " << endl << endl;
	}
else 
	{
	cout << "\nFile not Found." << endl << endl;
	}

snip.close ();

int size = 0;
char ch;
	
fstream file;
file.open ("stock.txt", ios::in);
	
while (file.get(ch))
	{
	if (ch == '\n')
	size++;
	}

file.clear(); //reset the end-of-file flag
file.seekg(0, ios::beg); //moving the pointer back to the beginning.
	
char head [200];

char **name = new char *[size];
int *items = new int[size];
int *price = new int[size];
int sr_no = 1, i = 0, bill = 0;
	
for (int m = 0; m < size; m++)
	{
	name [m] = new char [100];
	}

if (file.is_open ())
	{
	file.getline (head, 500, '\n');
	
	while (file >> name[i] >> items[i] >> price[i])
		{
		file.ignore();
		i++;
    		}
    	}
else
	{
	cout << "\nFile not Found." << endl << endl;
	}

//To sort the data for displaying purpose
dataSort (name, items, price, i);

file.close ();

//Highlighting the menu
cout << HIGHLIGHT_BLACK << head << HIGHLIGHT_END << endl << endl;


for(int j = 0; j < i; j++, sr_no++)
	{
	//Highlighting if the stock is zero
	if (items [j] == 0)
		{
		cout << setw (9) << left << sr_no << HIGHLIGHT_RED << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << HIGHLIGHT_END << endl << endl;
		}
		
	else if (items [j] <= 20 && items [j] > 0)
		{
		cout << setw (9) << left << sr_no << HIGHLIGHT_YELLOW << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << HIGHLIGHT_END << endl << endl;
		}
	
	else
		{
		//Printing the menu
		cout << setw (9) << left << sr_no << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << endl << endl;
		}
	}

//From Here Now -------------------------------------------------------------------------------------------------------------
fstream online;
online.open ("online_order.txt", ios::out | ios::app);

if (online.is_open ())
	{
	//Updating the menu
	order_online (name, items, price, i, bill);
	
	string choice3;
	start1: cout << "\nWould you like to order more? (Yes/No)\nYour choice: ";
	start2: cin >> choice3;
	cin.ignore ();
	
	if (choice3 == "Yes" || choice3 == "yes" || choice3 == "YES")
		{
		order_online (name, items, price, i, bill);
		goto start1;
		}
	else if (choice3 == "No" || choice3 == "no" || choice3 == "NO")
		{
		char time [10];
		
		cout << "\nAt what time should your order be delivered: ";
		cin.getline (time, 10);
		online << "\nTime of delivery: " << time << endl;
		
		online << "Total amount: Rs. " << bill << endl << " " ;
		
		{
		fstream avg;
		avg.open ("avg.txt", ios::out | ios::app);
		
		if (avg.is_open ())
			{
			avg << bill << endl << " ";
			}
		else
			{
			cout << "\nFile not Found." << endl << endl;
			}
		avg.close ();
		}
		
		cout << "\n\nYour Order has been placed." << endl;
		}
	else
		{
		cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
		goto start2;
		}
	
	}
else
	{
	cout << "\nFile not Found." << endl << endl;
	}

fstream file_r;
file_r.open ("stock.txt", ios::out);

file_r << head << endl;

//Rewriting into the same file with the same indentation but updated data
for (int j = 0; j < i; j++)
	{
	file_r << name[j] << " " << items[j] << " " << price[j] << endl;
	}
	
cout << "\n\nYour billed amount will be: Rs. " << bill << "\nPlease pay the courier." << endl << endl;

file_r.close ();
online.close ();
file.close ();

//To delete DMA
for (int l = 0; l < i; l++)
	{
	delete[] name[l];
	}
		
delete[] name;
delete[] items;
delete[] price;

name = NULL;
items = NULL;
price = NULL;

}
	
}

void search_all_c ()
	{
	cout << endl;
	
	int size = 0;
	char ch;
	
	fstream file;
	file.open ("stock.txt", ios::in);
	
	while (file.get(ch))
		{
		if (ch == '\n')
		size++;
		}

	file.clear(); //reset the end-of-file flag
	file.seekg(0, ios::beg); //moving the pointer back to the beginning.
	
	char head [200];
	
	char **name = new char *[size];
	int *items = new int[size];
	int *price = new int[size];
	int sr_no = 1, i = 0;
	
	for (int m = 0; m < size; m++)
		{
		name [m] = new char [100];
		}
	
	if (file.is_open ())
		{
		file.getline (head, 500, '\n');
		
		while (file >> name[i] >> items[i] >> price[i])
			{
			file.ignore();
			i++;
	    		}
	    	}
	else
		{
		cout << "\nFile not Found." << endl << endl;
		}

	file.close ();
	
	char search [20];
	cout << "Enter the name of item you want to search: ";
	cin.getline (search, 20);
	
	int l = 0;
	
	for (int j = 0; j < i; j++)
		{
		if (strcmp (search, name [j]) == 0)
			{
			cout << "\n\nWe Found:\n\n";
			cout << "> " << name [j] << ": \n\nQuantity in Stock: " << items [j] << "\nPrice per Item: " << price [j] << endl << endl;
			l++;
			}
		}	
			
	if (l == 0)
		{
		cout << "\nSorry, but we " << HIGHLIGHT_RED << "couldnt find any item" << HIGHLIGHT_END << " that matches your search." << endl << endl;
		}
		
	//To delete DMA
	for (int l = 0; l < i; l++)
		{
		delete[] name[l];
		}
		
	delete[] name;
   	delete[] items;
  	delete[] price;

	name = NULL;
	items = NULL;
	price = NULL;
		
	}
	
void complaint ()
	{
	char comp [200];
		
	fstream complaint;
	complaint.open ("complaints.txt", ios::app);
					
	if (complaint.is_open ())
		{
		cout << "\n\033[1mType your complaint here:\033[0m ";
		cin.getline (comp, 200);
		complaint << "> " << comp << endl;
		complaint.close ();
		cout << "\n";
		cout << "Complaint added Successfully." << endl << endl;
		}
	else
		{
		cout << "\nUnable to open file." << endl << endl;
		}
	}
	
void noti_c ()
	{
	cout << endl;
	char noti [100];
			
	fstream noti_c;
	noti_c.open ("notifications.txt", ios::in);

	if (noti_c.is_open ())
		{
		cout << HIGHLIGHT_YELLOW << "\nYou have following notification(s)." << HIGHLIGHT_END << endl << endl;
		while (noti_c.getline (noti, 100))
			{
			cout << noti << endl << endl;
			}
		}
	else
		{
		cout << "\nUnable to open file." << endl << endl;
		}
	}
					
