#include "game.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <boost>

typedef struct option{
	string verb;
	string noun;
}option;

vector<string> global

typedef struct Trie{
	unordered_map<char, Trie*> next;
	char ch;
	int leaf;
	string global; // if is leaf then there is a common word
}trie;

unordered_map<string, int> pocket;

int main(){
	// build tree
	trie* nnode= new trie;
	trie* vnode= new trie;
}

int input(option *op){
START:
	cout << ">>";
	string inp;
	cin >> inp;
	if(inp=="pocket"){
		cout << "inventory: ";
		for(auto it=pocket.begin();it!=pocket.end();++it)
			printf("%s : %d", it->first, it->second);
		goto START;
	else if(inp=="help"){
		//TODO
		cout << "help page: ";
		goto START;
	}
	else if(inp=="exit"){
		cout << "game over.\n";
		return -1;
	}
	return 1;
}

/* return the position in the options array
if there is no verb or noun, pass a empty string*/
int parse(string buf, vector<options> act){

}
