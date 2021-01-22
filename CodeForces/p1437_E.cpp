#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define MAXN 500005
using namespace std;
int n, k;
int a[MAXN];
vector<int> coords;
bool fix[MAXN];
int dp[MAXN];
set<int> cur;
int segtree[4*MAXN];
void reset (int x, int l, int r, int p) {
	if (p < l || p > r) return;
	if (l == r) {
		segtree[x] = 1e8;
		return;
	}
	int m = (l+r)/2;
	reset(2*x+1, l, m, p);
	reset(2*x+2, m+1, r, p);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
void update (int x, int l, int r, int p, int v) {
	if (p < l || p > r) return;
	if (l == r) {
		segtree[x] = min(segtree[x], v);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
int query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return 1e8;
	if (a <= b && r <= b) return segtree[x];
	int m = (l+r)/2;
	return min(query(2*x+1, l, m, a, b), query(2*x+2, m+1, r, a, b));
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i] -= i;
		coords.push_back(a[i]);
	}
	sort(coords.begin(), coords.end());
	coords.resize(unique(coords.begin(), coords.end())-coords.begin());
	for (int i=0; i<n; i++) {
		a[i] = lower_bound(coords.begin(), coords.end(), a[i])-coords.begin();
	}
	int inp;
	for (int i=0; i<k; i++) {
		cin >> inp;
		inp--;
		fix[inp] = true;
	}
	for (int i=0; i<4*n; i++) {
		segtree[i] = 1e8;
	}
	update(0, 0, n-1, 0, 1);
	cur.insert(0);
	for (int i=0; i<n; i++) {
		int best = query(0, 0, n-1, 0, a[i]);
		dp[i] = best+i-1;
		if (fix[i]) {
			for (auto j: cur) {
				reset(0, 0, n-1, j);
			}
			cur.clear();
		}
		update(0, 0, n-1, a[i], dp[i]-i);
		cur.insert(a[i]);
	}
	if (segtree[0] > n) {
		cout << -1 << endl;
		return 0;
	}
	cout << segtree[0]+n-1 << endl;
}