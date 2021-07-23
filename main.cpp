#include "game.cpp"
#include "system.cpp"

int main(){
	Json::Value root;
	Json::Reader reader;
	ifstream in;

	// parse verb dict
	in.open("vdict.json");
	if(!reader.parse(in, root, false)){
		cout << "data error\n";
		return 0;
	}
	v_key=root.getMemberNames();
	for(int a=0;a<v_key.size();++a){
		for(auto i:root[v_key[a]])
			vd[i.asString()]=a;
	}

	// parse noun dict
	//Json::Reader reader2;
	ifstream in2;
	in2.open("ndict.json");
	if(!reader.parse(in2, root, false)){
		cout << "data error (ndict)\n";
		return 0;
	}
	n_key=root.getMemberNames();
	for(int a=0;a<n_key.size();++a){
		for(auto i:root[n_key[a]])
			nd[i.asString()]=a;
	}

	// start
	rungame();
	return 1;
}
