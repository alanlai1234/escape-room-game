#include "src.cpp"

void rungame(){
	string nextmsg="(press enter to continue)\n", errmsg="don't understand your command\n";

	// welcome
	cout << "welcome to escape room\n" << nextmsg;
	cont;
	//......

	cout << "\n----------------------------------------------\n";

	// start
	cout << "You are in a room with a shelf and a table with few things on it.\n";
A:
	vector<option> tmp{{"look","table"}, {"open", "shelf"}, {"look", "paper"}, {"choose", "pen"}, {"choose", "key"}, {"go", "left"}, {"look", "note"}};

	switch(input(tmp)){
		case 0:
			cout << "There is a pen and a note paper with words on it.\n";
			goto A;
		case 1:
			cout << "there's a pile of papers in it, and a key on top of them.\n";
			goto A;
		case 2:
			cout << "message:\nI'll be back in just a minute, just to get some papers printed. And the bathroom is in the west side of the room.\n(a paper added to your inventory)\n";
			pocket.push_back(pair<string, int>{"note message", 1});
			goto A;
		case 3:
			cout << "(a pen added to your inventory)\n";
			pocket.push_back(pair<string, int>{"pen", 1});
			goto A;
		case 4:
			cout << "(a key added to your inventory)\n";
			pocket.push_back(pair<string, int>{"key", 1});
			goto A;
		case 5:
			break;
		case 100:
			return;
		default:
			cout << errmsg;
			goto A;
	}
}
