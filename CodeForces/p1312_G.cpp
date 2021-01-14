#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n;
char val[1000100];
int par[1000100];
vector<int> trie[1000100];
bool func (const int x, const int y) {
	return val[x] < val[y];
}
int q;
int words[1000100];
bool inc[1000100];
int segtree[4000100];
void update (int x, int l, int r, int a, int b, int v) {
	if (r < a || b < l) {
		return;
	}
	if (a <= l && r <= b) {
		segtree[x] = min(segtree[x], v+l-a);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
}
int query (int x, int l, int r, int p) {
	if (p < l || p > r) {
		return 1e8;
	}
	int v = segtree[x]+p-l;
	if (l == r) {
		return v;
	}
	int m = (l+r)/2;
	v = min(v, query(2*x+1, l, m, p));
	v = min(v, query(2*x+2, m+1, r, p));
	return v;
}
int ord[1000100];
int timer = 0;
int in_t[1000100], out_t[1000100];
int depth[1000100];
void dfs (int x, int p) {
	in_t[x] = timer;
	if (inc[x]) {
		ord[timer] = x;
		timer++;
	}
	if (p > -1) depth[x] = depth[p]+1;
	for (auto i: trie[x]) {
		dfs(i, x);
	}
	out_t[x] = timer-1;
	update(0, 0, q, in_t[x], out_t[x], depth[x]+1);
}
void dfs2 (int x, int p) {
	if (p > -1) depth[x] = depth[p]+1;
	if (inc[x]) {
		depth[x] = min(depth[x], query(0, 0, q, in_t[x]));
	}
	update(0, 0, q, in_t[x], out_t[x], depth[x]+1);
	for (auto i: trie[x]) {
		dfs2(i, x);
	}
}
int main () {
	cin >> n;
	int ai;
	char bi;
	for (int i=1; i<=n; i++) {
		cin >> ai >> bi;
		par[i] = ai;
		trie[ai].push_back(i);
		val[i] = bi;
	}
	for (int i=0; i<=n; i++) {
		sort(trie[i].begin(), trie[i].end(), func);
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> words[i];
		inc[words[i]] = true;
	}
	for (int i=0; i<4*n; i++) {
		segtree[i] = 1e8;
	}
	depth[0] = 0;
	dfs(0, -1);
	dfs2(0, -1);
	for (int i=0; i<q; i++) {
		cout << depth[words[i]] << " ";
	}
	cout << endl;
}