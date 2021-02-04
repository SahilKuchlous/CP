#include <iostream>
using namespace std;
#define MAXN 200005
int n, q;
string s, e;
int segtree[4*MAXN];
int lazy[4*MAXN];
void push (int x, int l, int r) {
	if (lazy[x] == 0) return;
	if (lazy[x] == 1) {
		segtree[x] = 0;
	} else {
		segtree[x] = r-l+1;
	}
	if (l != r) {
		lazy[2*x+1] = lazy[x];
		lazy[2*x+2] = lazy[x];
	}
	lazy[x] = 0;
}
void update (int x, int l, int r, int a, int b, int t) {
	push(x, l, r);
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		lazy[x] = t;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, t);
	update(2*x+2, m+1, r, a, b, t);
	segtree[x] = segtree[2*x+1]+segtree[2*x+2];
}
int query (int x, int l, int r, int a, int b) {
	push(x, l, r);
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return query(2*x+1, l, m, a, b)+query(2*x+2, m+1, r, a, b);
}
void init () {
	for (int i=0; i<4*n; i++) {
		lazy[i] = 0;
	}
}
void solve () {
	cin >> n >> q;
	init();
	cin >> s >> e;
	pair<int, int> rng[q];
	for (int i=0; i<q; i++) {
		cin >> rng[i].first >> rng[i].second;
		rng[i].first--; rng[i].second--;
	}
	for (int i=0; i<n; i++) {
		if (e[i] == '0') {
			update(0, 0, n-1, i, i, 1);
		} else {
			update(0, 0, n-1, i, i, 2);
		}
	}
	bool pos = true;
	for (int i=q-1; i>=0; i--) {
		int sz = rng[i].second-rng[i].first+1;
		int cnt = query(0, 0, n-1, rng[i].first, rng[i].second);
		if (cnt == sz/2.0) {
			pos = false;
		} else if (cnt < sz/2.0) {
			update(0, 0, n-1, rng[i].first, rng[i].second, 1);
		} else {
			update(0, 0, n-1, rng[i].first, rng[i].second, 2);
		}
	}
	for (int i=0; i<n; i++) {
		int val = query(0, 0, n-1, i, i);
		if (val != s[i]-'0') {
			pos = false;
		}
	}
	if (pos) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}