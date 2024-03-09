# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>
# include <cstring>
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void bubbleSort_ (char** name, int* items, int* price, int n)
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

void order_ (char** name, int* items, int* price, int i, int &bill)
	{
	int choice1, choice2;
	static int counter = 0;
	string choice4;
	
	start3:	cout << "\nEnter the customer's choice: ";
	start6:	cin >> choice1;
	choice1 -= 1;
	
	while (choice1 < 0 || choice1 >= i)
		{
		cout << HIGHLIGHT_RED <<"\nStock not Found." << HIGHLIGHT_END << " Please enter again: ";
		cin >> choice1;
		choice1 -= 1;
		}
		
	for (int j = 0; j < i; j++)
		{
		if (j == choice1)
			{
			if (items[j] == 0)
				{
				cout <<"\nThe customer " << HIGHLIGHT_RED << "cannot purchase" << HIGHLIGHT_END << " as no stock is avalible for this item.\nWould he/she like to purchase something else? (Yes/No)" << endl;
				cout << "\nCustomer's Choice: ";
				start4:	cin >> choice4;
				
				if (choice4 == "Yes" || choice4 == "yes" || choice4 == "YES")
					{
					goto start3;
					}
				else if (choice4 == "No" || choice4 == "no" || choice4 == "NO")
					{
					if (counter == 0)
						{
						cout << "\n\033[1mThank you for choosing CDS.\033[0m " << endl << endl;
						exit (EXIT_SUCCESS);
						}
					else
						{
						return;
						}
						
					}
				else
					{
					cout << HIGHLIGHT_RED << "\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
					goto start4;
					}
				
				}
			else
				{	
				cout << "\nEnter quantity: ";
				start5:	cin >> choice2;
				
				if (choice2 > items[j])
					{
					cout << "\nThe customer " << HIGHLIGHT_RED << "cannot order" << HIGHLIGHT_END << " more than the available stock. Enter again: ";
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
					items[j] -= choice2;
					bill = bill + (price[j] * choice2);
					}
				}
			}
		}
	}
	
	
void best_sell ()
											
{
char email_b [20];
int counter_b = 0;
cout << endl << "Enter your email again for security purposes: ";
e_again:	cin.getline (email_b, 20);

fstream bonus;
bonus.open ("bestseller.txt", ios::in);

char head [100];
char email [20][20];
int points [15];
int i = 0;

if (bonus.is_open ())
	{
	bonus.getline (head, 100, '\n');
	
	while (bonus >> email [i] >> points [i])
		{
		i++;
		}
	}
			
for (int j = 0; j < i; j++)
	{
	if (strcmp (email_b, email [j]) == 0)
		{
		counter_b++;
		}
	}

if (counter_b == 0)
	{
	cout << HIGHLIGHT_RED << "\nInvalid Email." << HIGHLIGHT_END << " Please enter again: ";
	goto e_again;
	}
else 
{
bonus.close ();

cout << HIGHLIGHT_GREEN << "\nEmail Found.\n" << HIGHLIGHT_END << endl;

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
bubbleSort_ (name, items, price, i);

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
	
file.close ();

int bill = 0;

//Updating the menu
order_ (name, items, price, i, bill);

string choice;
start1: cout << "\nWould the customer like to order more? (Yes/No)\nCustomer's choice: ";
start2: cin >> choice;

if (choice == "Yes" || choice == "yes" || choice == "YES")
	{
	order_ (name, items, price, i, bill);
	goto start1;
	}
else if (choice == "No" || choice == "no" || choice == "NO")
	{
	cout << "\n\nThank you for taking the customer's order." << endl;
	}
else
	{
	cout << HIGHLIGHT_RED << "\nInvalid Input." << HIGHLIGHT_END << " Please enter again: ";
	goto start2;
	}

fstream file_;
file_.open ("stock.txt", ios::out);

if (file_.is_open ())
	{
	file_ << head << endl;
	
	//Rewriting into the same file with the same indentation but updated data
	for (int j = 0; j < i; j++)
		{
		file_ << name[j] << " " << items[j] << " " << price[j] << endl;
		}
		
	file_.close ();
	
	{	
	cout << "\n\nThe customer's billed amount will be: Rs. " << bill << "\nMake sure to collect it." << 	endl << endl;
	
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
	
	fstream bonus;
	bonus.open ("bestseller.txt", ios::in);
	
	char head [100];
	char email [20][20];
	int points [15];
	int i = 0;
	
	if (bonus.is_open ())
		{
		bonus.getline (head, 50, '\n');
		
		while (bonus >> email [i] >> points [i])
			{
			i++;
			}
			
		//Data is being extracted nicely
		for (int j = 0; j < i; j++)
			{
			if (strcmp (email [j], email_b) == 0)
				{
				points [j] += 2;
				}
			}
		}
	else
		{
		cout << "\nFile not Found." << endl << endl;
		}
		
	bonus.close ();
	
	fstream rewrite;
	rewrite.open ("bestseller.txt", ios::out);
	
	if (rewrite.is_open ())
		{
		rewrite << head << endl;
		
		for (int k = 0; k < i; k++)
			{
			rewrite << email [k] << " " << points [k] << endl;
			}
		}
	else
		{
		cout << "\nFile not Found." << endl << endl;
		}
	
	rewrite.close ();
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
	
}
}

void search_all_employee ()
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
			cout << HIGHLIGHT_YELLOW << "> " << name [j] << HIGHLIGHT_END << ": \n\nQuantity in Stock: " << items [j] << "\nPrice per Item: " << price [j] << endl << endl;
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
	
void noti_e ()
	{
	cout << endl;
	char noti [100];
	
	fstream noti_a;
	noti_a.open ("notifications.txt", ios::in);

	if (noti_a.is_open ())
		{
		cout << HIGHLIGHT_YELLOW << "\nYou have following notification(s)." << HIGHLIGHT_END << endl << endl;
		while (noti_a.getline (noti, 100))
			{
			cout << noti << endl << endl;
			}
		}
	else
		{
		cout << "\nUnable to open file." << endl << endl;
		}
	}
		
void see_online_e ()
	{
	cout << endl;
	char orders [100][200];
	int n = 0;
	
	fstream o_order;
	o_order.open ("online_order.txt", ios::in);
		
	if (o_order.is_open ())
		{
		cout << HIGHLIGHT_YELLOW << "\nYou have following online order(s)." << HIGHLIGHT_END << endl;
		while (o_order.getline (orders [n], 200))
			{
			cout << orders [n] << '\n';
			n++;
			}
		}
	else
		{
		cout << "\nUnable to open file." << endl << endl;
		}
		
	}	
