#include <iostream>
#include <set>
using namespace std;
#define MAXN 400005
set<int> opts[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	pair<int, int> a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	set< pair<int, int> > ord;
	for (int i=0; i<n; i++) {
		opts[a[i].first].insert(i);
		opts[a[i].second].insert(i);
	}
	for (int i=0; i<MAXN; i++) {
		if (opts[i].size() > 0) {
			ord.insert(make_pair(opts[i].size(), i));
		}
	}
	int o = 0;
	while (ord.size() > 0) {
		pair<int, int> cur = *ord.begin();
		ord.erase(ord.begin());
		o++;
		int ind = *opts[cur.second].begin();
		opts[cur.second].clear();
		if (a[ind].first != cur.second) {
			ord.erase(make_pair(opts[a[ind].first].size(), a[ind].first));
			opts[a[ind].first].erase(ind);
			if (opts[a[ind].first].size() > 0) ord.insert(make_pair(opts[a[ind].first].size(), a[ind].first));
		}
		if (a[ind].second != cur.second) {
			ord.erase(make_pair(opts[a[ind].second].size(), a[ind].second));
			opts[a[ind].second].erase(ind);
			if (opts[a[ind].second].size() > 0) ord.insert(make_pair(opts[a[ind].second].size(), a[ind].second));
		}
	}
	cout << o << endl;
}