#include "game.cpp"
#include "system.cpp"

int main(){
	Json::Value root;
	Json::Reader reader;
	ifstream in;

	// parse verb dict
	in.open("words/vdict.json");
	if(!reader.parse(in, root, false)){
		cout << "data error\n";
		return 0;
	}
	v_key=root.getMemberNames();
	for(int a=0;a<v_key.size();++a){
		if(root[v_key[a]].size()==0)
			vd[root[v_key[a]].asString()]=a;
		for(auto i:root[v_key[a]])
			vd[i.asString()]=a;
	}

	// parse noun dict
	//Json::Reader reader2;
	ifstream in2;
	in2.open("words/ndict.json");
	if(!reader.parse(in2, root, false)){
		cout << "data error (ndict)\n";
		return 0;
	}
	n_key=root.getMemberNames();
	for(int a=0;a<n_key.size();++a){
		if(root[n_key[a]].size()==0)
			nd[root[n_key[a]].asString()]=a;
		for(auto i:root[n_key[a]])
			nd[i.asString()]=a;
	}

	// start
	rungame();
	return 1;
}
