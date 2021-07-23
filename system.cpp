#include "src.cpp"

bool search(vector<int> nums, int target){
	for(auto k:nums){
		if(k == target)
			return true;
	}
	
	return false;
}

int input(vector<option> &a){
START:
	cout << ">>";
	string buf;
	getline(cin, buf);
	boost::trim_right(buf);

	if(buf == "pocket"){
		cout << "inventory:\n";
		for(auto p:pocket){
			printf("%d %s\n", p.second, p.first.c_str());
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
	else if(buf.empty())
		goto START;

	return parse(buf, a);
}

/* return the position in the options array
if there is no verb or noun, pass a empty string*/
int parse(string& bf, vector<option> &acts){
	vector<string> split;
	boost::split(split, bf, boost::is_any_of(" "));
	vector<int> find_list;
	int ans, vflag=0, nflag=0;

	for(auto i:split){
		//verb
		cout << ans << "\n";
		if(!vflag){
			auto v_get=vd.find(i);

			if(v_get!=vd.end()){
				for(int ind=0;ind<acts.size();++ind){
					if(acts[ind].v==v_key[v_get->second]){
						if(!nflag){
							find_list.push_back(ind);
							vflag=1;
						}
						else if(search(find_list, ind)){
							vflag=1;
							ans=ind;
							break;
						}
					}
				}
				continue;
			}
		}

		//noun
		if(!nflag){
			auto n_get=nd.find(i);

			if(n_get!=nd.end()){
				for(int ind=0;ind<acts.size();++ind){
					if(acts[ind].n==n_key[n_get->second]){
						if(!vflag){
							find_list.push_back(ind);
							nflag=1;
						}
						else if(search(find_list, ind)){
							nflag=1;
							ans=ind;
							break;
						}
					}
				}
			}
		}
	}

	if(find_list.size()==0 && (!vflag || !nflag))
		return -1;

	return ans;
}
