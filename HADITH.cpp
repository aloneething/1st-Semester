# include <iostream>
# include <cstdlib>
# include <ctime>
# define HIGHLIGHT_GREEN "\033[1;32m"
# define HIGHLIGHT_END "\033[0m"
using namespace std;

void good_things ()

{

int num;

srand(time(NULL));
num = (rand () % 10) + 1;

cout << "\n\n\033[1mAllah's Messenger (PBUH) once said:\033[0m";

switch (num)
	{
	
	case 1:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"There are two words which are light on the tongue, heavy on the scale, and loved by the Most Merciful: SubhanAllahi wa Bihamdi, SubhanAllahi al-Azeem.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 2:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"Beware of suspicion, for suspicion is the worst of false tale.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 3:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"Do not hate one another, and do not be jealous of one another, and do not desert each other.\nAnd O, Allah's worshipers! Be brothers. Lo! It is not permissible for any Muslim to desert (not talk to) his brother (Muslim) for more than three days.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 4:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"A slave [of Allah] may utter a word without giving it much thought by which he slips into the fire a distance further than that between East and West.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 5:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"Whoever stands [for Night Prayer] in Ramadan out of faith and hope for reward will be forgiven his past sins.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 6:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"One Umrah to the next is an expiation for whatever happened between them and the only reward for an accepted Hajj is paradise.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
	
	case 7:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"Yawning is from the devil, so whenever one of you yawns, then let him try to suppress it as much as possible.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
	
	case 8:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"The one who looks after a widow or a poor person is like a Mujahid (warrior) who fights for Allah's Cause, or like him who performs prayers all the night and fasts all the day.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 9:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"No fatigue, illness, worry, sorrow, harm, grief, or even the prick of a thorn afflicts a Muslim except that Allah expiates some of his sins by it.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	case 10:
		{
		
		cout << HIGHLIGHT_GREEN << "\n\"The fire is surrounded by [unlawful] desires and paradise by difficulties.\"" << HIGHLIGHT_END << endl << endl;
		break;
		}
		
	}

}
