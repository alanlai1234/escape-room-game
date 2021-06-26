#include "system.cpp"
#define cont cin.get()

void rungame();

int main(){
	rungame();
}

void rungame(){
	string nextmsg="(press enter to continue)\n", errmsg="don't understand your command\n";

	cout << "welcome to escape room\n" << nextmsg;
	cont;
}
