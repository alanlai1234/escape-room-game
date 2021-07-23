#ifndef _SRC_
#define _SRC_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <unordered_map>
#include <json/json.h>
#include <stdio.h>
#define cont cin.get()

using namespace std;

// for use of listing possible actions
typedef struct OP{
	string v; //verb
	string n; // noun
}option;

unordered_map<string, int> vd, nd;
vector<string> v_key, n_key;
vector<pair<string, int>> pocket;

void rungame();
int input(vector<option>&);
int parse(string&, vector<option>&);
bool search(vector<int>, int);

#endif
