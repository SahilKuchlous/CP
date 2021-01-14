#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 100100
int n, m;
vector<int> adj[MAXN];
vector<int> rev[MAXN];
vector<int> topo;
bool vis[MAXN];
void dfs1 (int x) {
	vis[x] = true;
	for (auto i: adj[x]) {
		if (vis[i]) continue;
		dfs1(i);
	}
	topo.push_back(x);
}
int cnt = 0;
int grp[MAXN];
int sz[MAXN];
int root;
void dfs2 (int x) {
	if (x == 0) root = cnt;
	vis[x] = true;
	grp[x] = cnt;
	sz[cnt]++;
	for (auto i: rev[x]) {
		if (vis[i]) continue;
		dfs2(i);
	}
}
vector<int> scc_adj[MAXN];
vector<int> scc_rev[MAXN];
int val1[MAXN], val2[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		rev[bi].push_back(ai);
	}
	for (int i=0; i<n; i++) {
		if (vis[i]) continue;
		dfs1(i);
	}
	reverse(topo.begin(), topo.end());
	for (int i=0; i<n; i++) vis[i] = false;
	for (auto i: topo) {
		if (vis[i]) continue;
		dfs2(i);
		cnt++;
	}
	for (int i=0; i<n; i++) {
		for (auto j: adj[i]) {
			if (grp[i] == grp[j]) continue;
			scc_adj[grp[i]].push_back(grp[j]);
			scc_rev[grp[j]].push_back(grp[i]);
		}
	}
	for (int i=0; i<cnt; i++) {
		sort(scc_adj[i].begin(), scc_adj[i].end());
		scc_adj[i].resize(unique(scc_adj[i].begin(), scc_adj[i].end())-scc_adj[i].begin());
		sort(scc_rev[i].begin(), scc_rev[i].end());
		scc_rev[i].resize(unique(scc_rev[i].begin(), scc_rev[i].end())-scc_rev[i].begin());
	}
	for (int i=0; i<cnt; i++) {
		val1[i] = val2[i] = -1e8;
		if (i == root) {
			val1[i] = sz[i];
			val2[i] = sz[i];
		}
	}
	for (int i=root+1; i<cnt; i++) {
		for (auto j: scc_rev[i]) {
			if (val1[j] > -1e8) val1[i] = max(val1[i], val1[j]+sz[i]);
		}
	}
	for (int i=root-1; i>=0; i--) {
		for (auto j: scc_adj[i]) {
			if (val2[j] > -1e8) val2[i] = max(val2[i], val2[j]+sz[i]);
		}
	}
	int o = sz[root];
	for (int i=0; i<cnt; i++) {
		for (auto j: scc_adj[i]) {
			o = max(o, val1[i]+val2[j]-sz[root]);
			o = max(o, val2[i]+val1[j]-sz[root]);
		}
	}
	cout << o << endl;
}