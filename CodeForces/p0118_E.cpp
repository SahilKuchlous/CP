#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m;
vector< pair<int, int> > o;
set<int> adj[100100];
int tin[100100];
int t = 0;
int low[100100];
bool bridge = false;
bool vis[100100];
void dfs (int x, int p) {
	vis[x] = true;
	tin[x] = low[x] = t;
	t++;
	for (auto i: adj[x]) {
		if (!vis[i]) {
			o.push_back(make_pair(x, i));
			dfs(i, x);
			if (low[i] > tin[x]) bridge = true;
			low[x] = min(low[x], low[i]);
		} else if (i != p && tin[i] < tin[x]) {
			o.push_back(make_pair(x, i));
			low[x] = min(low[x], tin[i]);
		}
	}
}
int main () {
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
	dfs(1, 0);
	if (bridge) {
		cout << 0 << endl;
	} else {
		for (auto i: o) {
			cout << i.first << " " << i.second << endl;
		}
	}
}