#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
int cnt[200100];
set< pair<int, int> > grps[200100];
set< pair<int, int> > ord;
bool pos = true;
vector<int> o;
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> cnt[i];
	}
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		grps[ai].insert(make_pair(i, bi));
		grps[bi].insert(make_pair(i, ai));
	}
	for (int i=0; i<n; i++) {
		ord.insert(make_pair(grps[i].size()-cnt[i], i));
	}
	while (ord.size() > 0) {
		pair<int, int> cur = *ord.begin();
		ord.erase(ord.begin());
		if (cur.first > 0) {
			pos = false;
			break;
		}
		for (auto i: grps[cur.second]) {
			o.push_back(i.first);
			ord.erase(make_pair(grps[i.second].size()-cnt[i.second], i.second));
			grps[i.second].erase(make_pair(i.first, cur.second));
			ord.insert(make_pair(grps[i.second].size()-cnt[i.second], i.second));
		}
	}
	reverse(o.begin(), o.end());
	if (pos) {
		cout << "ALIVE" << endl;
		for (auto i: o) cout << i+1 << " ";
		cout << endl;
	} else {
		cout << "DEAD" << endl;
	}
}