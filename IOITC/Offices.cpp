#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m;
set<int> adj[100000];
bool vis[100000];
int c = 0;
set<int> o;
set<int> bound;
set<int> upd;
/*
void bfs (int x) {
	bound.clear();
	bound.insert(x);
	while (bound.size() > 0) {
		upd.clear();
		for (auto i: bound) {
			vis[i] = true;
			c++;
		}
		for (auto i: bound) {
			for (int j=1; j<=n; j++) {
				if (adj[i].find(j) == adj[i].end() && !vis[j]) {
					upd.insert(j);
				}
			}
		}
		bound = upd;
	}
}
*/
void dfs (int x) {
	c++;
	vis[x] = true;
	for (int j=1; j<=n; j++) {
		if (adj[x].find(j) == adj[x].end() && !vis[j]) {
			dfs(j);
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	for (int i=1; i<=n; i++) {
		vis[i] = false;
	}
	int ps;
	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			ps = c;
			dfs(i);
			o.insert(c-ps);
		}
	}
	cout << o.size() << endl;
	for (auto i: o) {
		cout << i << " ";
	}
	cout << endl;
}