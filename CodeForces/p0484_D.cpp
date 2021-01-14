#include <iostream>
#include <vector>
using namespace std;
int n;
long long val[1000100];
long long dp[1000100];
vector< pair<long long, int> > min_v, max_v;
long long segtree[4000100];
long long lazy[4000100];
void push (int x, int l, int r) {
	segtree[x] += lazy[x];
	if (l != r) {
		lazy[2*x+1] += lazy[x];
		lazy[2*x+2] += lazy[x];
	}
	lazy[x] = 0;
}
void upd1 (int x, int l, int r, int p, long long v) {
	push(x, l, r);
	if (p < l || r < p) return;
	if (l == r) {
		segtree[x] = v;
		return;
	}
	int m = (l+r)/2;
	upd1(2*x+1, l, m, p, v);
	upd1(2*x+2, m+1, r, p, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
void upd2 (int x, int l, int r, int a, int b, long long v) {
	push(x, l, r);
	if (r < a || b < l) return;
	if (a <= l && r <= b) {
		lazy[x] = v;
		push(x, l, r);
		return;
	}
	int m = (l+r)/2;
	upd2(2*x+1, l, m, a, b, v);
	upd2(2*x+2, m+1, r, a, b, v);
	segtree[x] = max(segtree[2*x+1], segtree[2*x+2]);
}
signed main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	for (int i=1; i<=n; i++) {
		cin >> val[i];
	}
	min_v.push_back(make_pair(-1e10, 0));
	max_v.push_back(make_pair(1e10, 0));
	for (int i=1; i<=n; i++) {
		while (min_v.back().first >= val[i]) {
			upd2(0, 0, n, min_v[min_v.size()-2].second, min_v.back().second-1, min_v.back().first-val[i]);
			min_v.pop_back();
		}
		min_v.push_back(make_pair(val[i], i));
		while (max_v.back().first <= val[i]) {
			upd2(0, 0, n, max_v[max_v.size()-2].second, max_v.back().second-1, val[i]-max_v.back().first);
			max_v.pop_back();
		}
		max_v.push_back(make_pair(val[i], i));
		dp[i] = segtree[0];
		upd1(0, 0, n, i, dp[i]);
	}
	cout << dp[n] << endl;
	return 0;
}
