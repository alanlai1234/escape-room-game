//idea: use json to parse word dictionary
#include <iostream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <json/json.h>

using namespace std;

vector<pair<string, int>> pocket;

// for use of listing possible actions
typedef struct OP{
	string v; //verb
	string n; // noun
}option;

int inp(vector<option>&);
//int parse(string, vector<option>&);

int inp(vector<option> &a){
START:
	cout << ">>";
	string buf;
	cin >> buf;
	boost::trim_right(buf);
	if(buf == "pocket"){
		cout << "inventory:";
		for(auto p:pocket){
			printf("%d %s", p.second, p.first.c_str());
		}
		goto START;
	}
	else if(buf == "help"){
		cout << "help:\n";
		cout << "input two words in the input line, one verb, and one noun, use your intuition.\n";
		cout << "input 'pocket' to see what's in your inventory.\n";
		cout << "input 'exit' to leave the game.\n";
		goto START;
	}
	else if(buf == "exit"){
		cout << "game over\n";
		return 100;
	}
	//return parse(buf, a);
	return 1;
}

/* return the position in the options array
if there is no verb or noun, pass a empty string*/
//int parse(string& bf, vector<option>& acts){
	//vector<string> split;
	//boost::split(split, bf, boost::is_any_of(" "));
	//vector<int> find;
	//int ans, vflag=0, nflag=0;
	////string vv;
	//for(auto i:split){
		////verb
		//if(!vflag){
			//;
		//}
	//}
//}
