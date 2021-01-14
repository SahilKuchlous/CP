#include <iostream>
#include <set>
using namespace std;
int adj[2010][2010];
set< pair<int, int> > tree[2010];
bool pos = true;
void dfs (int s, int x, int p, int d) {
	if (!pos) {
		return;
	}
	if (adj[s][x] != d) {
		pos = false;
		return;
	}
	for (auto i: tree[x]) {
		if (i.first != p) {
			dfs(s, i.first, x, d+i.second);
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> adj[i][j];
		}
	}
	int key[n];
	int par[n];
	bool vis[n];
	for (int i=0; i<n; i++) {
		key[i] = 1e9+1;
		vis[i] = false;
	}
	key[0] = 0;
	par[0] = 0;
	for (int i=0; i<n-1; i++) {
		int min_k = 1e9+1, x = 0;
		for (int j=0; j<n; j++) {
			if (key[j] < min_k && !vis[j]) {
				min_k = key[j];
				x = j;
			}
		}
		vis[x] = true;
		for (int j=0; j<n; j++) {
			if (key[j] > adj[x][j] && !vis[j]) {
				key[j] = adj[x][j];
				par[j] = x;
			}
		}
	}
	for (int i=0; i<n; i++) {
		if (par[i] != i) {
			tree[i].insert(make_pair(par[i], key[i]));
			tree[par[i]].insert(make_pair(i, key[i]));
			if (key[i] == 0) {
				pos = false;
			}
		}
	}
	for (int i=0; i<n; i++) {
		dfs(i, i, -1, 0);
	}
	if (pos) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}