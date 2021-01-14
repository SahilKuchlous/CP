#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
set<int> vis;
map< int, set<int> > adj;
pair<int, int> dfs (int x) {
	vis.insert(x);
	pair<int, int> r = make_pair(x, x);
	pair<int, int> p;
	for (auto i: adj[x]) {
		if (vis.find(i) == vis.end()) {
			p = dfs(i);
			if (p.first < r.first) {
				r.first = p.first;
			}
			if (p.second > r.second) {
				r.second = p.second;
			}
		}
	}
	return r;
}
int main () {
	int n, m;
	cin >> n >> m;
	int u, v;
	for (int i=0; i<m; i++) {
		cin >> u >> v;
		adj[u].insert(v);
		adj[v].insert(u);
	}
	vector< pair<int, int> > vec;
	for (int i=1; i<=n; i++) {
		if (vis.find(i) == vis.end()) {
			vec.push_back(dfs(i));
		}
	}
	sort(vec.begin(), vec.end());
	int o = 0;
	int e = -1;
	for (auto i: vec) {
		if (i.first < e) {
			o++;
			if (i.second > e) {
				e = i.second;
			}
		} else {
			e = i.second;
		}
	}
	cout << o << endl;
}