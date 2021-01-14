#include <iostream>
#include <map>
#include <vector>
#include <deque>
using namespace std;
int tl[10001];
map< int, vector<int> > adj;
int cost, n, x;
long long k;
deque<int> path;
long long c;
int d;
void dfs (int node, int par) {
	c += tl[node];
	path.push_back(node);
	if (c > k) {
		for (int i=d; i<path.size(); i++) {
			if (tl[path[i]]-(c-k) > 0) {
				tl[path[i]] -= (c-k);
				cost += (c-k)*2;
				c = k;
				break;
			} else {
				cost += tl[path[i]]*2;
				c -= tl[path[i]];
				tl[path[i]] = 0;
				d++;
			}
		}
	}
	/*
	cout << node << " - ";
	for (int i=1; i<=n; i++) {
		cout << tl[i] << " ";
	}
	cout << "- " << d;
	cout << endl;
	*/
	for (auto i: adj[node]) {
		if (i != par) {
			dfs(i, node);
		}
	}
	path.pop_back();
	c -= tl[node];
	if (d > path.size()) {
		d = path.size();
	}
}
int main () {
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		cin >> n >> x >> k;
		for (int i=1; i<=n; i++) {
			cin >> tl[i];
		}
		int u, v;
		for (int i=0; i<n-1; i++) {
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		cost = 0;
		path.empty();
		c = 0;
		d = 0;
		dfs(x, 0);
		cout << cost << endl;
	}
}