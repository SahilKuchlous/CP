#include <iostream>
using namespace std;
#define MAXN 500005
int n;
int a[MAXN];
pair<int, int> segtree[4*MAXN];
void init (int x, int l, int r) {
	segtree[x] = make_pair(0, 1);
	if (l == r) return;
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
}
void update (int x, int l, int r, int p, pair<int, int> v) {
	if (l > p || r < p) return;
	if (l == r) {
		if (v <= segtree[x]) return;
		segtree[x] = v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (b < l || a > r) return make_pair(0, 1);
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	pair<int, int> o = make_pair(0, 1);
	o = max(o, query(2*x+1, l, m, a, b));
	o = max(o, query(2*x+2, m+1, r, a, b));
	return o;
}
int segtree2[4*MAXN];
void init2 (int x, int l, int r) {
	if (l == r) {
		segtree2[x] = a[l];
		return;
	}
	int m = (l+r)/2;
	init2(2*x+1, l, m);
	init2(2*x+2, m+1, r);
	segtree2[x] = max(segtree2[2*x+1], segtree2[2*x+2]);
}
int query2 (int x, int l, int r, int a, int b) {
	if (b < l || a > r) return -1;
	if (a <= l && r <= b) return segtree2[x];
	int m = (l+r)/2;
	return max(query2(2*x+1, l, m, a, b), query2(2*x+2, m+1, r, a, b));
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			a[i]--;
		}
		init(0, 0, n-1);
		init2(0, 0, n-1);
		int o = 0;
		for (int i=0; i<n; i++) {
			pair<int, int> best = query(0, 0, n-1, 0, a[i]);
			int cur = best.first+1;
			int mx = query2(0, 0, n-1, -best.second+1, i-1);
			if (mx >= a[i]) cur++;
			o = max(o, cur);
			update(0, 0, n-1, a[i], make_pair(cur, -i));
		}
		cout << o << '\n';
	}
}