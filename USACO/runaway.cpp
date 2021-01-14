#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("runaway.in");
ofstream fout("runaway.out");
int n;
long long l;
vector< pair<int, long long> > adj[200100];
int dfs_num[200100];
int dfs_ord[200100];
int size[200100];
long long dist[200100];
int cur = 0;
vector<long long> segtree[800100];
void dfs (int x, int p) {
	dfs_num[x] = cur;
	dfs_ord[cur] = x;
	cur++;
	size[x] = 1;
	for (auto i: adj[x]) {
		if (i.first != p) {
			dist[i.first] = dist[x]+i.second;
			dfs(i.first, x);
			size[x] += size[i.first];
		}
	}
}
void build (int x, int l, int r) {
	if (l == r) {
		segtree[x] = {dist[dfs_ord[l]]};
		return;
	}
	int m = (l+r)/2;
	build(2*x+1, l, m);
	build(2*x+2, m+1, r);
	merge(segtree[2*x+1].begin(), segtree[2*x+1].end(), segtree[2*x+2].begin(), segtree[2*x+2].end(), back_inserter(segtree[x]));
}
long long query (int x, int l, int r, int a, int b, long long v) {
	if (r < a || b < l) {
		return 0;
	}
	if (a <= l && r <= b) {
		return upper_bound(segtree[x].begin(), segtree[x].end(), v)-segtree[x].begin();
	}
	int m = (l+r)/2;
	long long ret = 0;
	ret += query(2*x+1, l, m, a, b, v);
	ret += query(2*x+2, m+1, r, a, b, v);
	return ret;
}
int main () {
	fin >> n >> l;
	int pi;
	long long li;
	for (int i=1; i<n; i++) {
		fin >> pi >> li;
		pi--;
		adj[i].push_back(make_pair(pi, li));
		adj[pi].push_back(make_pair(i, li));
	}
	dist[0] = 0;
	dfs(0, 0);
	build(0, 0, n-1);
	for (int i=0; i<n; i++) {
		fout << query(0, 0, n-1, dfs_num[i], dfs_num[i]+size[i]-1, dist[i]+l) << endl;
	}
}