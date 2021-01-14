#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("promote.in");
ofstream fout("promote.out");
vector<int> adj[100100];
vector<int> ord;
int cur_t = 0;
int in_t[100100];
int out_t[100100];
void dfs (int x, int p) {
	ord.push_back(x);
	in_t[x] = cur_t;
	cur_t++;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x);
		}
	}
	out_t[x] = cur_t-1;
}
int segtree[400100];
void update (int x, int l, int r, int p) {
	if (p < l || p > r) return;
	segtree[x]++;
	if (l == r) return;
	int m = (l+r)/2;
	update(2*x+1, l, m, p);
	update(2*x+2, m+1, r, p);
}
int query (int x, int l, int r, int a, int b) {
	if (r < a || l > b) return 0;
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	int o = query(2*x+1, l, m, a, b);
	o += query(2*x+2, m+1, r, a, b);
	return o;
}
int main () {
	int n;
	fin >> n;
	pair<int, int> val[n];
	for (int i=0; i<n; i++) {
		fin >> val[i].first;
		val[i].second = i;
	}
	sort(val, val+n, greater< pair<int, int> >());
	int ai;
	for (int i=1; i<n; i++) {
		fin >> ai;
		ai--;
		adj[ai].push_back(i);
		adj[i].push_back(ai);
	}
	dfs(0, -1);
	int o[n];
	for (int i=0; i<n; i++) {
		o[val[i].second] = query(0, 0, n-1, in_t[val[i].second], out_t[val[i].second]);
		update(0, 0, n-1, in_t[val[i].second]);
	}
	for (int i=0; i<n; i++) {
		fout << o[i] << endl;
	}
}