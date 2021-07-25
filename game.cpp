#include "src.cpp"

void rungame(){
	string nextmsg="(press enter to continue)\n", errmsg="don't understand your command\n";
	vector<option> tmp;

	// welcome
	cout << "welcome to escape room\n" << nextmsg;
	cont;
	//......

	cout << "\n----------------------------------------------\n";

	// start
	cout << "You are in a room with a shelf and a table with few things on it.\n";
A:
	tmp = vector<option>{{"look","table"}, {"open", "shelf"}, {"look", "paper"}, {"choose", "pen"}, {"choose", "key"}, {"go", "left"}, {"look", "note"}, {"go", "right"}};

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
		case 6:
			cout << "message:\nI'll be back in just a minute, just to get some papers printed. And the bathroom is in the west side of the room.\n(a paper added to your inventory)\n";
			pocket.push_back(pair<string, int>{"note message", 1});
			goto A;
		case 7:
			// TODO: add more for going right
			cout << "running into the wall...\n";
			goto A;
		case 100:
			return;
		default:
			cout << errmsg;
			goto A;
	}

	cout << "a door is in front of you\n";
B:
	tmp = vector<option>{{"open", "door"}, {"use", "key"}, {"go", "left"}, {"go", "right"}};
	switch input(tmp) {
	case 0:
		cout << "the door is locked, use a key to open.\n";
		goto B;
	case 1:
		cout << "shoot.. the key has been eroded, it's broken! Hold up, there's something at the left, might want to move closer to see it clearly.\n";
		goto B;
	case 2:
		break;
	case 3:
		cout << "You are in a room with a shelf and a table with few things on it.\n";
		goto A;
	case 100:
		return;
	default:
		cout << errmsg;
		goto B;
	}

	//TODO: translate

	//fmt.Println("there is a big bulleton board in front of you, might find some helpful informations.")
//C:
	//switch in([]options{{"look", "board"}}) {
	//case 0:
		//fmt.Println("Oh no, there's too many notes on the bulliton board at the same time, gotta do it in a smart way..")
		//if notegame() {
			//break
		//}else {
			//fmt.Println("you failed, try it again.")
			//goto C
		//}
		
	//case 100:
		//return
	//default:
		//fmt.Println(err_msg)
		//goto C
	//}
}
