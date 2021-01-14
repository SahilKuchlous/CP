#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;
int n, m;
map< int, vector<int> > adj;
set<int> ap;
int back[10010];
int num[10010];
int cnt;
void dfs (int v, int par) {
	num[v] = cnt++;
	back[v] = num[v];
	int c = 0;
	for (auto i: adj[v]) {
		if (num[i] == -1) {
			dfs(i, v);
			c++;
			back[v] = min(back[v], back[i]);
			if (back[i] >= num[v] && par != -1) {
				// cout << v << endl;
				ap.insert(v);
			}
		} else {
			if (i != par) {
				back[v] = min(back[v], num[i]);
			}
		}
	}
	if (par == -1) {
		if (c > 1) {
			ap.insert(v);
		}
	}
}
int main () {
	while (true) {
		adj.clear();
		ap.clear();
		cin >> n >> m;
		if (n == 0 && m == 0) {
			break;
		}
		int x, y;
		for (int i=0; i<m; i++) {
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		for (int i=1; i<=n; i++) {
			num[i] = -1;
			back[i] = -1;
		}
		cnt = 1;
		dfs(1, -1);
		cout << ap.size() << endl;
	}
}