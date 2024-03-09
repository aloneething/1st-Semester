# include <iostream>
# include <fstream>
# include <cstring>
# include <cstdlib>
# include <iomanip>
# include <ctime>
#define HIGHLIGHT_BLACK "\033[1;47;30m"
#define HIGHLIGHT_GREEN "\033[1;32m"
#define HIGHLIGHT_RED "\033[1;31m"
#define HIGHLIGHT_YELLOW "\033[1;33m"
#define HIGHLIGHT_END "\033[0m"
using namespace std;

void sorting (char name[][20], int items[], int price [], int n)
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
	
void see_stock_prize ()
	{
	cout << endl;
	
	char head [500];
	char name [20][20] = {0};
	int items [20];
	int price [20];
	float t_price [20];
	int sr_no = 1;
	int i = 0;
		
	fstream file;
	file.open ("stock.txt", ios::in);
	
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
	sorting (name, items, price, i);
	
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
	}
	
void order_prize (char name[][20], int items[], int price[], int i)
	{
	int choice1;
	
	start3:	cout << "You can have only one item for free.\nEnter your choice: ";
	choose_a:	cin >> choice1;
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
				cout << "\nYou " << HIGHLIGHT_RED << "cannot have this" << HIGHLIGHT_END << " as no stock is avalible for this item.\nChoose something else: ";
				goto choose_a;
				}
			else
				{
				cout << "\n> " << HIGHLIGHT_YELLOW << name[j] << HIGHLIGHT_END;
				items[j] -= 1;
				}
			}
		}
	}

	
void prize ()

{
cout << endl;

char head [500];
char name [20][20] = {0};
int items [100];
int price [100];
int sr_no = 1;
int i = 0;

fstream file;
file.open ("stock.txt", ios::in);

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
sorting (name, items, price, i);

file.close ();

int choice1;

//Updating the menu
order_prize (name, items, price, i);

fstream file_r;
file_r.open ("stock.txt", ios::out);

file_r << head << endl;

//Rewriting into the same file with the same indentation but updated data
for (int j = 0; j < i; j++)
	{
	file_r << name[j] << " " << items[j] << " " << price[j] << endl;
	}
	
cout << "\n\nThat one's FREE. Play again sometime." << endl << endl;

file_r.close ();

}



void rock_paper_scissors ()

{
char rpc;
int num = 0;

cout << "\n" << HIGHLIGHT_YELLOW << "If you win this game, you can have one item for free." << HIGHLIGHT_END;
cout << "\n\n\"Rock - Paper - Scissors\"";
	
srand(time(NULL));
num = rand() % 3 + 1;
	
cout << "\n\nI've made my choice. ";
cout << "\nEnter P for Paper, S for Scissors, or R for Rock: ";
again:	cin >> rpc;
	
switch (rpc)
	{
	case ('P'):
	case ('p'):
		{
		if (num == 1)
			{
			cout << "\nI choosed Paper.";
			cout << HIGHLIGHT_YELLOW << "\nIt's a draw." << HIGHLIGHT_END << endl << endl;
			}
		else if (num == 2)
			{
			cout << "\nI choosed Scissors.";
			cout << HIGHLIGHT_RED << "\nYOU LOSE." << HIGHLIGHT_END << endl << endl;
			}
		else 
			{
			cout << "\nI choosed Rock.";
			cout << HIGHLIGHT_GREEN << "\nYOU WIN." << HIGHLIGHT_END << endl << endl;
			see_stock_prize ();
			prize ();
			}
		break;
		}
	case ('S'):
	case ('s'):
		{
		if (num == 1)
			{
			cout << "\nI choosed Paper.";
			cout << HIGHLIGHT_GREEN << "\nYOU WIN." << HIGHLIGHT_END << endl << endl;
			see_stock_prize ();
			prize ();
			}
		else if (num == 2)
			{
			cout << "\nI choosed Scissors.";
			cout << HIGHLIGHT_YELLOW << "\nIt's a draw." << HIGHLIGHT_END << endl << endl;
			}
		else 
			{
			cout << "\nI choosed Rock.";
			cout << HIGHLIGHT_RED << "\nYOU LOSE." << HIGHLIGHT_END << endl << endl;
			}
		break;
		}
	case ('R'):
	case ('r'):
		{
		if (num == 1)
			{
			cout << "\nI choosed Paper.";
			cout << HIGHLIGHT_RED << "\nYOU LOSE." << HIGHLIGHT_END << endl << endl;
			}
		else if (num == 2)
			{
			cout << "\nI choosed Scissors.";
			cout << HIGHLIGHT_GREEN << "\nYOU WIN." << HIGHLIGHT_END << endl << endl;
			see_stock_prize ();
			prize ();
			}
		else 
			{
			cout << "\nI choosed Rock.";
			cout << HIGHLIGHT_YELLOW << "\nIt's a draw." << HIGHLIGHT_END << endl << endl;
			}
		break;
		}
	default: 
		{
		cout << HIGHLIGHT_RED <<"\nInvalid Input." << HIGHLIGHT_END << " Please only select R for Rock, P for Paper and S for Scissors." << endl;
		cout << "Please choose again: ";
		goto again;
		}
	}
}
