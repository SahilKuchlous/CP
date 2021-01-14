#include <iostream>
#include <vector>
using namespace std;
int query (vector<int> V);
#define MAXN 2000
vector<int> adj[MAXN];
vector<int> v;
int dist[MAXN];
int l1, l2;
int diam;
vector<int> opts;
void dfs (int x, int p, int d) {
	dist[x] = d;
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs(i, x, d+1);
	}
}
int findHiddenVertex (int n, vector<int> parents) {
	if (n == 1) return 1;
	if (n == 2) {
		if (query({1}) == 0) return 1;
		return 2;
	}
	for (int i=1; i<=n; i++) {
		adj[i].clear();
	}
	for (int i=0; i<n-1; i++) {
		adj[i+2].push_back(parents[i]);
		adj[parents[i]].push_back(i+2);
	}
	dfs(1, 1, 0);
	l1 = 1;
	for (int i=1; i<=n; i++) {
		if (dist[i] > dist[l1]) l1 = i;
	}
	dfs(l1, l1, 0);
	l2 = l1;
	for (int i=1; i<=n; i++) {
		if (dist[i] > dist[l2]) l2 = i;
	}
	int d1 = query({l1});
	if (d1 == 0) return l1;
	int d2 = query({l2});
	if (d2 == 0) return l2;
	int org;
	if (d1 >= d2) {
		org = d1/2;
	} else {
		l1 = l2;
		org = d2/2;
	}
	opts.clear();
	for (int i=1; i<=n; i++) {
		if (i != l1) opts.push_back(i);
	}
	int l = 0, r = opts.size()-1, m;
	while (l < r) {
		int m = (l+r)/2;
		v = {l1};
		for (int i=l; i<=m; i++) {
			v.push_back(opts[i]);
		}
		if (query(v) == org) {
			r = m;
		} else {
			l = m+1;
		}
	}
	return opts[l];
}