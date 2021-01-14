#include <iostream>
#include <vector>
using namespace std;
#define MAXN 300005
int n, m;
vector<int> adj[MAXN];
int lo[MAXN], hi[MAXN];
int segtree[4*MAXN];
void init (int x, int l, int r) {
	if (l == r) {
		segtree[x] = lo[l];
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
void update (int x, int l, int r, int p, int v) {
	if (p < l || r < p) return;
	if (l == r) {
		segtree[x] = v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
int query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return MAXN;
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return min(query(2*x+1, l, m, a, b), query(2*x+2, m+1, r, a, b));
}
int segtree2[4*MAXN];
void init2 (int x, int l, int r) {
	if (l == r) {
		segtree2[x] = hi[l];
		return;
	}
	int m = (l+r)/2;
	init2(2*x+1, l, m);
	init2(2*x+2, m+1, r);
	segtree2[x] = max(segtree2[2*x+1], segtree2[2*x+2]);
}
int query2 (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return -1;
	if (a <= l && r <= b) return segtree2[x];
	int m = (l+r)/2;
	return max(query2(2*x+1, l, m, a, b), query2(2*x+2, m+1, r, a, b));
}
int dp[MAXN];
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		lo[i] = hi[i] = i;
	}
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
		hi[ai] = max(hi[ai], bi);
		lo[bi] = min(lo[bi], ai);
	}
	init(0, 0, n-1);
	for (int i=0; i<n; i++) {
		lo[i] = query(0, 0, n-1, lo[i], i);
		update(0, 0, n-1, i, lo[i]);
	}
	init2(0, 0, n-1);
	for (int i=0; i<n; i++) {
		hi[i] = query2(0, 0, n-1, lo[i], i);
	}
	for (int i=0; i<n; i++) {
		if (hi[i] > i) continue;
		dp[i+1] = dp[lo[i]]+1;
		o += dp[i+1];
	}
	cout << o << endl;
}