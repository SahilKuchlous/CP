#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
vector<int> adj[500100];
int timer = 0;
int in_t[500100], out_t[500100];
int ord[500100];
void dfs (int x, int p) {
	ord[timer] = x;
	in_t[x] = timer;
	timer++;
	for (auto i: adj[x]) {
		if (i != p) {
			dfs(i, x);
		}
	}
	out_t[x] = timer;
}
int segtree1[2000100];
void update1 (int x, int l, int r, int a, int b, int v) {
	if (r < a || l > b) {
		return;
	}
	if (a <= l && r <= b) {
		segtree1[x] = v;
		return;
	}
	int m = (l+r)/2;
	update1(2*x+1, l, m, a, b, v);
	update1(2*x+2, m+1, r, a, b, v);
}
int query1 (int x, int l, int r, int p) {
	if (p < l || p > r) {
		return 0;
	}
	if (l == r) {
		return segtree1[x];
	}
	int m = (l+r)/2;
	int o = segtree1[x];
	o = max(o, query1(2*x+1, l, m, p));
	o = max(o, query1(2*x+2, m+1, r, p));
	return o;
}
int segtree2[2000100];
void update2 (int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	segtree2[x] = v;
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update2(2*x+1, l, m, p, v);
	update2(2*x+2, m+1, r, p, v);
}
int query2 (int x, int l, int r, int a, int b) {
	if (r < a || l > b) {
		return 0;
	}
	if (a <= l && r <= b) {
		return segtree2[x];
	}
	int m = (l+r)/2;
	int o = 0;
	o = max(o, query2(2*x+1, l, m, a, b));
	o = max(o, query2(2*x+2, m+1, r, a, b));
	return o;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	int ai, bi;
	for (int i=0; i<n-1; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs(0, 0);
	cout << endl;
	int q;
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi;
		bi--;
		if (ai == 1) {
			update1(0, 0, n-1, in_t[bi], out_t[bi]-1, i+1);
		} else if (ai == 2) {
			update2(0, 0, n-1, in_t[bi], i+1);
		} else {
			int v1 = query1(0, 0, n-1, in_t[bi]);
			int v2 = query2(0, 0, n-1, in_t[bi], out_t[bi]-1);
			cout << (v1 > v2) << endl;
		}
	}
}