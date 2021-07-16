#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define MAXN 1000005
int n;
bool token[MAXN];
int par[MAXN];
vector<int> adj[MAXN];
int depth[MAXN];
long long ans[MAXN];
priority_queue<int> opts[MAXN];
int ptr[MAXN];
void reset () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
		while (!opts[i].empty()) opts[i].pop();
		ptr[i] = i;
	}
	depth[0] = 0;
}
void dfs (int x, int p) {
	ans[x] = 0;
	depth[x] = depth[p]+1;
	int mx_sz = 0, mx_i = x;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x);
		ans[x] += ans[i];
		if (opts[ptr[i]].size() > mx_sz) {
			mx_sz = opts[ptr[i]].size();
			mx_i = i;
		}
	}
	ptr[x] = ptr[mx_i];
	for (auto i: adj[x]) {
		if (i == p || i == mx_i) continue;
		while (!opts[ptr[i]].empty()) {
			opts[ptr[x]].push(opts[ptr[i]].top());
			opts[ptr[i]].pop();
		}
	}
	if (token[x]) {
		opts[ptr[x]].push(depth[x]);
	} else if (!opts[ptr[x]].empty()) {
		ans[x] += (opts[ptr[x]].top()-depth[x]);
		opts[ptr[x]].pop();
		opts[ptr[x]].push(depth[x]);
	}
}
void solve () {
	cin >> n;
	reset();
	char inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		token[i] = (inp == '1');
	}
	for (int i=1; i<n; i++) {
		cin >> par[i];
		par[i]--;
		adj[i].push_back(par[i]);
		adj[par[i]].push_back(i);
	}
	dfs(0, 0);
	cout << ans[0] << endl;
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