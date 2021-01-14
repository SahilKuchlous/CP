#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
int n;
map< int, vector<int> > grps;
set<int> hts;
set<int> done;
int o;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi;
		grps[bi].push_back(i);
		hts.insert(bi);
	}
	o = n;
	done.insert(n);
	for (auto i: hts) {
		for (int j=0; j<grps[i].size()-1; j++) {
			int nxt = *done.lower_bound(grps[i][j]);
			if (nxt > grps[i][j+1]) o--;
		}
		for (auto j: grps[i]) done.insert(j);
	}
	cout << o << endl;
}