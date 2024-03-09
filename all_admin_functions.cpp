# include <iostream>
# include <fstream>
# include <iomanip>
# include <cstdlib>
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void bubbleSort (char** name, int* items, int* price, int n)
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
	
void see_stock ()
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
	int *items = new int [size];
	int *price = new int [size];
	int sr_no = 1, i = 0;
	
	for (int m = 0; m < size; m++)
		{
		name [m] = new char [100];
		}
	
	if (file.is_open ())
		{
		file.getline (head, 200, '\n');
		
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
	bubbleSort (name, items, price, i);
	
	file.close ();
	
	//Highlighting the menu
	cout << HIGHLIGHT_BLACK << head << HIGHLIGHT_END << endl << endl;
	
	
	for (int j = 0; j < i; j++, sr_no++)
		{
		//Highlighting if the stock is zero
		if (items [j] == 0)
			{
			cout << setw (9) << left << sr_no << HIGHLIGHT_RED << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * 	price [j]) << HIGHLIGHT_END << endl << endl;
			}
			
		else if (items [j] <= 20 && items [j] > 0)
			{
			cout << setw (9) << left << sr_no << HIGHLIGHT_YELLOW << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * 	price [j]) << HIGHLIGHT_END << endl << endl;
			}
			
		else
			{
			//Printing the menu
			cout << setw (9) << left << sr_no << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << endl << 	endl;
			}
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


void add ()
	{
	char name [20] = {0};
	int items;
	int price;
	
	fstream file;
	file.open ("stock.txt", ios::out | ios::app);
	
	cout << "\n\033[1m(Note: If there are spaces in the name, use underscore(s) instead.)\033[0m \n";
	
	cout << "\nEnter the Stock's Name: ";
	cin.getline (name, 20);
	
	cout << "Enter Stock's Quantity: ";
	cin >> items;
	
	cout << "Enter the Price per Piece: ";
	cin >> price;
	
	file << name << " " << items << " " << price << endl;
	
	cout << "\nStock Added Successfully." << endl << endl;
	
	}

void remove ()
	{
	
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
		file.getline (head, 200, '\n');
		
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
		
	bubbleSort (name, items, price, i);
		
	int remove;
	cout << "\nEnter the stock number you want to remove: ";
	again1:	cin >> remove;
	
	fstream file_r;
	file_r.open ("stock.txt", ios::out);
	
	remove -= 1;
	
	if (remove >= 0 && remove < i)
		{
		if (file_r.is_open ())
			{
			file_r << head << endl;
			
			for (int j = 0; j < i; j++)
				{
				if (j != remove)
					{
					file_r << name[j] << " " << items[j] << " " << price[j] << endl;
					}
				}
			
			cout << "\nStock Updated." << endl << endl;
			
			}
		else
			{
			cout << "\nFile not Found." << endl << endl;
			}
		}
	else
		{
		cout << HIGHLIGHT_RED <<"\nStock not found." << HIGHLIGHT_END << " Please enter again: ";
		goto again1;
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
		
	file_r.close ();
	
	}
	
void update_price ()
	{	

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
		file.getline (head, 200, '\n');
		
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
		
	bubbleSort (name, items, price, i);	
	
	fstream file_;
	file_.open ("stock.txt", ios::out);
	
	if (file_.is_open ())
		{
		int stock;
		int upd_price;
		cout << "\nEnter the stock's number: ";
		stock_no:	cin >> stock;
		stock -= 1;
		
		if (stock >= 0 && stock < i)
			{
			for (int j = 0; j < i; j++)
				{
				if (stock == j)
					{
					cout << "Enter the updated price: ";
					cin >> upd_price;
					
					price [j] = upd_price;
					}
				}
				
			file_ << head << endl;
			
			for (int k = 0; k < i; k++)
				{
				file_ << name[k] << " " << items[k] << " " << price[k] << endl;
				}
				
			file_.close ();
			cout << "\nPrice Updated Successfully." << endl << endl;
			}
		else
			{
			cout << HIGHLIGHT_RED <<"\nYou have exceeded the stock's limit." << HIGHLIGHT_END << " Please enter again: ";
			goto stock_no;
			}
		}
	else
		{
		cout << "\nFile Not Found." << endl << endl;
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
	
void update_items ()
	{
	
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
		file.getline (head, 200, '\n');
		
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
		
	bubbleSort (name, items, price, i);	
	
	fstream file_;
	file_.open ("stock.txt", ios::out);
	
	if (file_.is_open ())
		{
		int stock;
		int upd_items;
		cout << "\nEnter the stock's number: ";
		stock_no:	cin >> stock;
		stock -= 1;
		
		if (stock >= 0 && stock < i)
			{
			for (int j = 0; j < i; j++)
				{
				if (stock == j)
					{
					cout << "Enter the amount of Stock Items: ";
					again:	cin >> upd_items;
					if ((items [j] + upd_items) > 1000)
						{
						cout << HIGHLIGHT_RED <<"\n(Available Stock + New Stock) cannot exceed the limit i.e. 1000." << HIGHLIGHT_END << "\nPlease enter again: ";
						goto again;
						}
					else
						{
						items [j] = (items [j] + upd_items);
						}
					}
				}
				
			file_ << head << endl;
			
			for (int k = 0; k < i; k++)
				{
				file_ << name[k] << " " << items[k] << " " << price[k] << endl;
				}
				
			file_.close ();
			cout << "\nStock Items Ordered Successfully." << endl << endl;
			}
		else
			{
			cout << HIGHLIGHT_RED <<"\nYou have exceeded the stock's limit." << HIGHLIGHT_END << " Please enter again: ";
			goto stock_no;
			}
		}
	else
		{
		cout << "\nFile Not Found." << endl << endl;
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
	
void stock_noti ()

	{
	cout << endl << endl;
	
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
	
	//To sort the data for displaying purpose	
	bubbleSort (name, items, price, i);
	
	//Highlighting the menu
	cout << HIGHLIGHT_BLACK << head << HIGHLIGHT_END << endl << endl;
	
	
	for (int j = 0; j < i; j++, sr_no++)
		{
		//Highlighting if the stock is zero
		if (items [j] == 0)
			{
			cout << setw (9) << left << sr_no << HIGHLIGHT_RED << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * 	price [j]) << HIGHLIGHT_END << endl << endl;
			}
			
		else if (items [j] <= 20 && items [j] > 0)
			{
			cout << setw (9) << left << sr_no << HIGHLIGHT_YELLOW << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * 	price [j]) << HIGHLIGHT_END << endl << endl;
			}
			
		else
			{
			//Printing the menu
			cout << setw (9) << left << sr_no << setw (20) << left << name [j] << setw (25) << left << items [j] << setw (25) << left << price [j] << setw (25) << (items [j] * price [j]) << endl << 	endl;
			}
		}
	
	int l = 0;
	
	cout << HIGHLIGHT_YELLOW <<"\nSTOCK ALERT: " << HIGHLIGHT_END << endl << endl;
	
	for (int k = 0; k < i; k++)
		{
		if (items [k] <= 20 && items [k] > 0)
			{
			cout << "> " << name [k] << ": " << items [k] << " Left in Stock." << endl;
			l++;
			}
		else if (items [k] == 0)
			{
			cout << "> " << name [k] << ": Out of stock." << endl;
			l++;
			}
		}
	
	if (l == 0)
		{
		cout << "You have " << HIGHLIGHT_GREEN << "no stock alerts" << HIGHLIGHT_END << " for the moment." << endl;
		}
	else
		{
		cout << "\n\033[1mOrder the above mentioned stock please.\033[0m " << endl;
		}
		
	cout << endl;
	
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
	
void search_all_admin ()
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
			cout << HIGHLIGHT_YELLOW << "> " << name [j] << HIGHLIGHT_END << "\n\nQuantity in Stock: " << items [j] << "\nPrice per Item: " << price [j] << endl << endl;
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
	
	
//From Here ----------------------------------------------------------------------------------//Isko DMA me convert krna hai abi
void remove_login_employee ()
{

char head1 [200];
char head2 [200];
char username1 [20][20];
char username2 [20][20];
char password [20][20];
int points [20];
int sr_no = 1, i = 0, j = 0;

fstream file;
file.open ("employee_login.txt", ios::in);

fstream remove;
remove.open ("bestseller.txt", ios::in);

file.getline (head1, 200, '\n');
remove.getline (head2, 200, '\n');

//1st File
if (file.is_open ())
	{
	while (file >> username1 [i] >> password [i])
		{
		file.ignore ();
		i++;
		}
	
	cout << endl <<HIGHLIGHT_BLACK << head1 << HIGHLIGHT_END << endl << endl;
	
	for (int j = 0; j < i; j++, sr_no++)
		{
		cout << setw (9) << left << sr_no << setw (25) << left << username1 [j] << setw (25) << left << password [j] << endl << endl;
		}
	
	file.close ();
	}
else 
	{
	cout << "\nFile Not Found." << endl << endl;
	}

//2nd File
if (remove.is_open ())
	{
	while (remove >> username2 [j] >> points [j])
		{
		file.ignore ();
		j++;
		}
	
	remove.close ();
	}
else 
	{
	cout << "\nFile Not Found." << endl << endl;
	}

//Main Thing Starts From Here

char choice [20];
int counter1 = 0;

fstream file_;
file_.open ("employee_login.txt", ios::out);

fstream remove_;
remove_.open ("bestseller.txt", ios::out);

if (file_.is_open ())
	{
	cout << "\nEnter the Email of employee you want to remove: ";
	enter_ag:	cin.getline (choice, 20);

	for (int k = 0; k < i; k++)
		{
		if (strcmp (choice, username1 [k]) == 0)
			{
			counter1++;
			}
		}
		
	if (counter1 == 0)
		{
		cout << HIGHLIGHT_RED <<"\nUsername not Found." << HIGHLIGHT_END << " Please enter again: ";
		goto enter_ag;
		}
		
	file_ << head1 << endl;
	
	for (int l = 0; l < i; l++)
		{
		if (!strcmp (choice, username1 [l]) == 0)
			{
			file_ << username1 [l] << " " << password [l] << endl;
			}
		}
	file_.close (); 
	
	if (remove_.is_open ())
		{
		
		remove_ << head2 << endl;
		
		for (int l = 0; l < j; l++)
			{
			if (!strcmp (choice, username2 [l]) == 0)
				{
				remove_ << username2 [l] << " " << points [l] << endl;
				}
			}
		remove_.close ();
		
		}
	else
		{
		cout << "\nFile not Found." << endl << endl;
		}
	
	cout << "\nCredential removed Successfully." << endl << endl;
	}
else
	{
	cout << "\nFile Not Found." << endl << endl;	
	}

}
//Till Here ----------------------------------------------------------------------------------//Isko be abi DMA me convert krna hai

void remove_login_customer ()
{

char username [20][20];
char password [20][20];
int sr_no = 1, i = 0;

fstream file;
file.open ("customer_login.txt", ios::in);

if (file.is_open ())
	{
	while (file >> username [i] >> password [i])
		{
		file.ignore ();
		i++;
		}
	
	cout << endl <<HIGHLIGHT_BLACK << "Sr.No    Username                 Password" << HIGHLIGHT_END << endl << endl;
	
	for (int j = 0; j < i; j++, sr_no++)
		{
		cout << setw (9) << left << sr_no << setw (25) << left << username [j] << setw (25) << left << password [j] << endl << endl;
		}
	
	file.close ();
	}
else 
	{
	cout << "\nFile Not Found." << endl << endl;
	}

char choice [20];
int counter = 0;

fstream file_;
file_.open ("customer_login.txt", ios::out);

if (file_.is_open ())
	{
	cout << "\nEnter the Username of the customer you want to remove: ";
	enter_a:	cin.getline (choice, 20);
	
	
	for (int k = 0; k < i; k++)
		{
		if (strcmp (choice, username [k]) == 0)
			{
			counter++;
			}
		}
	
	if (counter == 0)
		{
		cout << HIGHLIGHT_RED << "\nUsername not Found." << HIGHLIGHT_END << " Please enter again: ";
		goto enter_a;
		}
		
	for (int l = 0; l < i; l++)
		{
		if (!strcmp (choice, username [l]) == 0)
			{
			file_ << username [l] << " " << password [l] << endl;
			}
		}
	
	file_.close (); 

	cout << "\nCredential removed Successfully." << endl << endl;
		
	}
	
else
	{
	cout << "\nFile Not Found." << endl << endl;	
	}

}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

void sort_decending (char email [][20], int points [], int n)
	{
	for (int i = 0; i < n - 1; i++)
		{
	        for (int j = 0; j < n - i - 1; j++)
	        	{
            		if (points [j] < points [j + 1])
            			{
                		swap(email [j], email [j + 1]);
                		swap(points [j], points [j + 1]);
            			}
        		}
    		}
	}

//Isko be abi DMA me convert krna hai
void best_sell_admin ()

{

fstream best_s;
best_s.open ("bestseller.txt", ios::in);

char head [100];
char email [20][20];
int points [15];
int i = 0, sr_no = 1;

if (best_s.is_open ())
	{
	best_s.getline (head, 50, '\n');
	
	while (best_s >> email [i] >> points [i])
		{
		i++;
		}
	}
			
sort_decending (email, points, i);

best_s.close ();

cout << endl <<HIGHLIGHT_BLACK << head << HIGHLIGHT_END << endl << endl;
	
//See the best-seller employee
for (int j = 0; j < i; j++, sr_no++)
	{
	if (j == 0)
		{
		cout << setw (9) << left << sr_no << HIGHLIGHT_GREEN << setw (25) << left << email [j] << setw (25) << left << points [j] << HIGHLIGHT_END << endl << endl;
		}
	else
		{
		cout << setw (9) << left << sr_no << setw (25) << left << email [j] << setw (25) << left << points [j] << endl << endl;
		}
	}
	
}

void noti_a ()
	{
	char c;
			
	cout << "\n\033[1mYou want to:\033[0m \n\n1. See Existing Notifications\n2. Add New Notification\n3. Remove a Notification\n\nEnter a specified number: ";
	start:	cin >> c;
	cin.ignore ();
	
	switch (c)
		{
		case '1':
			{
			cout << endl;
			char noti [200][200];
			int n = 0;
			
			fstream noti_a;
			noti_a.open ("notifications.txt", ios::in);
		
			if (noti_a.is_open ())
				{
				cout << HIGHLIGHT_YELLOW << "\nYou have following notification(s)." << HIGHLIGHT_END << endl << endl;
				while (noti_a.getline (noti [n], 200))
					{
					cout << noti [n] << endl << endl;
					n++;
					}
				}
			else
				{
				cout << "\nUnable to open file." << endl << endl;
				}
		
			break;
			}
					
		case '2':
			{
			char noti [200];
		
			fstream noti_a;
			noti_a.open ("notifications.txt", ios::app);
					
			if (noti_a)
				{
				cout << "\nType your notification here: ";
				cin.getline (noti, 200);
				noti_a << "> " << noti << endl;
				noti_a.close ();
				cout << "\n";
				cout << "Notification Generated Successfully." << endl << endl;
				}
			else
				{
				cout << "\nUnable to open file." << endl << endl;
				}
					
			break;
			}
				
		case '3':
			{
			cout << endl;
			char noti [100][200];
			int n = 0;
			
			fstream noti_a;
			noti_a.open ("notifications.txt", ios::in);
		
			if (noti_a.is_open ())
				{
				cout << HIGHLIGHT_YELLOW << "\nYou have following notification(s)." << HIGHLIGHT_END << endl << endl;
				while (noti_a.getline (noti [n], 200))
					{
					cout << noti [n] << endl << endl;
					n++;
					}
				}
			else
				{
				cout << "\nUnable to open file." << endl << endl;
				}
						
						
			int rn;

			fstream rm_noti;
			rm_noti.open("notifications.txt", ios::out);
					
			cout << "\nWhich n(th) notification you want should be removed: ";
			cin >> rn;
					
			rn = rn -1;
					
			for (int i = 0; i < n; i++)
				{
				if (i != rn)
					{
					rm_noti << noti [i] << endl;
					}
				}

			rm_noti.close ();
						
			cout << "\nOperation performed successfully." << endl << endl;
			break;
			}
				
		default:
			{
			cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please enter again: " << endl << endl;
			goto start;
			}
				
		}
		
	}
	
void login_employee ()
	{
	char choice;
	
	cout << "\n\n\033[1mPlease choose from the following options:\033[0m \n\n1. Add an Employee's Credentials\n2. Remove an Employee's Credentials\n3. Add a Customer's Crefentials\n4. Remove a Customer's Credentials\n\nEnter the specified number: ";
	start2:	cin >> choice;
	cin.ignore ();
			
	switch (choice)
		{
		
		case '1':
			{
	
			fstream login;
			login.open ("employee_login.txt", ios::out | ios::app);
			
			fstream add;
			add.open ("bestseller.txt", ios::out | ios::app);
			
			
			char user [100];
			char pass [100];
			
			if (login.is_open ())
				{
				cout << "\nEnter username: ";
				cin.getline (user, 100);
				cout << "Enter password: ";
				cin.getline (pass, 100);
				login << user << " " << pass << "\n";
				add << user << " " << "0" << "\n";
				login.close ();
				add.close ();
						
				cout << "\nEmployee's Crenentials Added Successfully." << endl << endl;
				}
			else
				{	
				cout << "Unable to reach file.";
				}
			
			break;
			}
					
		case '2':
			{
					
			remove_login_employee ();
			break;
			}
			
		case '3':
			{
			
			fstream login;
			login.open ("customer_login.txt", ios::out | ios::app);
		
			char user [100];
			char pass [100];
			
			if (login.is_open ())
				{
				cout << "\nEnter username: ";
				cin.getline (user, 100);
				cout << "Enter password: ";
				cin.getline (pass, 100);
				login << user << " " << pass << "\n";
				login.close ();
						
				cout << "\nCustomer's Crenentials Added Successfully." << endl << endl;
				}
			else
				{	
				cout << "Unable to reach file.";
				}
			
			break;
			}
		
		case '4':
			{
			
			remove_login_customer ();
			break;
			}
					
		default:
			{
					
			cout << HIGHLIGHT_RED << "\nInvalid Input." << HIGHLIGHT_END << "Please enter again: ";
			goto start2;
			}
			
		}
	}
	
void see_comp ()
	{
	cout << endl;
	char comp [200];
			
	fstream complaint_a;
	complaint_a.open ("complaints.txt", ios::in);
		
	if (complaint_a.is_open ())
		{
		cout << HIGHLIGHT_YELLOW <<"\nYou have following complaint(s)." << HIGHLIGHT_END << endl << endl;
		while (complaint_a.getline (comp, 200))
			{
			cout << comp << endl << endl;
			}
		}
	else
		{
		cout << "\nUnable to open file." << endl << endl;
		}
	}
	
void see_online ()
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
	
void statistics ()
	{
	cout << "\n\033[1mSTATISTICS\033[0m\n\n";
	int all [100], i = 0;
	float sum = 0;
	float avg = 0;
	
	fstream sta;
	sta.open ("avg.txt", ios::in);
	
	if (sta.is_open ())
		{
		while (sta >> all [i])
			{
			i++;
			}
		
		for (int j = 0; j < i; j++)
			{
			sum += all [j];
			}
		
		avg = (sum / i);
	
		cout << "Average amount recieved per order: Rs. " << avg << endl;
		cout << "Number of sales: " << i << endl;
		cout << "Total amount recieved from all orders: Rs. " << sum << endl << endl;
		
		}
	else
		{
		cout << "\nFile not Found." << endl << endl;
		}
	}
