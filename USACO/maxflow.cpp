#include <iostream>
#include <fstream>
#include <set>
using namespace std;
ifstream fin("maxflow.in");
ofstream fout("maxflow.out");
int n, k;
set<int> adj[100100];
int euler[200100];
int depth[100100];
int first_occ[100100];
int parent[100100];
int ec = 0;
pair<int, int> segtree[1000000];
int presum[100100];
int best = 0;
void dfs (int v, int p, int d) {
	parent[v] = p;
	euler[ec] = v;
	depth[v] = d;
	first_occ[v] = ec;
	ec++;
	for (auto i: adj[v]) {
		if (i != p) {
			dfs(i, v, d+1);
			euler[ec] = v;
			ec++;
		}
	}
}
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x] = make_pair(depth[euler[l]], euler[l]);
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
pair<int, int> query (int a, int b, int x, int l, int r) {
	if (b < l || a > r) {
		return make_pair(1e9, 1e9);
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	pair<int, int> o = make_pair(1e9, 1e9);
	o = min(o, query(a, b, 2*x+1, l, m));
	o = min(o, query(a, b, 2*x+2, m+1, r));
	return o;
}
int sln (int v, int p) {
	int score = presum[v];
	for (auto i: adj[v]) {
		if (i != p) score += sln(i, v);
	}
	best = max(best, score);
	return score;
}
int main () {
	fin >> n >> k;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		fin >> ai >> bi;
		ai--;
		bi--;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	dfs(0, -1, 0);
	create(0, 0, 2*n-2);
	int s, t;
	for (int i=0; i<k; i++) {
		fin >> s >> t;
		s--;
		t--;
		presum[s]++;
		presum[t]++;
		int lca = query(min(first_occ[s], first_occ[t]), max(first_occ[s], first_occ[t]), 0, 0, 2*n-2).second;
		presum[lca]--;
		if (lca != 0) {
			presum[parent[lca]]--;
		}
	}
	sln(0, -1);
	fout << best << endl;
}