#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; cin >> T;
	vector<string> S1;
	vector<set<char>> S2;
	set<char> all;
	int totalLength = 0;
	while(T--) {
		string cur; cin >> cur; 
		S1.push_back(cur);
		set<char> temp;
		for(auto c : cur) {temp.insert(c); all.insert(c);}
		S2.push_back(temp);
		if(temp.size() != cur.size()) {
			cout << "SMTH WRONG" << endl; return 0;
		}
	}
	string cur = "";
	while(cur.size() < all.size()) {
		bool found = false;
		char can = NULL;
		for(int i = 0; i < S2.size(); i++) {
			if(S2[i].size() == 0) continue;
			char curC = S1[i].back();
			bool valid = true;
			for(int j = 0; j < S2.size(); j++) {
				if(S2[j].find(curC) != S2[j].end() && S1[j].back() != curC) {
					valid = false; break;
				}
			}
			if(valid) {
				can = curC; found = true; break;
			}
		}
		if(!found) {
			cout << "SMTH WRONG"  << endl; return 0;
		}
		for(int i = 0; i < S1.size(); i++) {
			if(S1[i].back() == can) {
				S1[i].pop_back();
				S2[i].erase(can);
			}
		}
		cur += can;
	}
	for(int i = 0; i < cur.size() / 2;i++) {
		swap(cur[i], cur[cur.size()-1-i]);
	}
	cout << cur << endl;
	return 0;
}

/*

5
SMH
TON
RNG
WRO
THG

*/
