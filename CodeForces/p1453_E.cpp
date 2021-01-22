#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 200005
int n;
vector<int> adj[MAXN];
int dp[MAXN];
int o = 1;
void init () {
	o = 0;
	for (int i=0; i<n; i++) {
		adj[i].clear();
	}
}
void dfs (int x, int p) {
	multiset<int> c;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		c.insert(dp[i]);
	}
	if (c.size() == 0) {
		dp[x] = 0;
		return;
	}
	dp[x] = (*c.begin())+1;
	o = max(o, dp[x]);
	c.erase(c.begin());
	for (auto i: c) {
		o = max(o, i+2);
	}
}
void solve () {
	cin >> n;
	init();
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	multiset<int> c;
	for (auto i: adj[0]) {
		dfs(i, 0);
		c.insert(dp[i]);
	}
	if (c.size() > 1) o = max(o, *prev(prev(c.end()))+2);
	if (c.size() > 0) o = max(o, *prev(c.end())+1);
	cout << o << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}