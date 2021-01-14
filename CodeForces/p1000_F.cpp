#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[500000];
int q;
pair< pair<int, int>, int> qry[500000];
int pre[500001];
pair<int, int> segtree[2000000];
void init (int x, int l, int r) {
	segtree[x] = make_pair(n, l);
	if (l == r) return;
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
}
void update (int x, int l, int r, int p, int v) {
	if (p < l || p > r) return;
	if (l == r) {
		segtree[x].first = v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return make_pair(n, 0);
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return min(query(2*x+1, l, m, a, b), query(2*x+2, m+1, r, a, b));
}
int o[500000];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n;
	int mx = 0;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		mx = max(mx, a[i]);
	}
	for (int i=0; i<=mx; i++) {
		pre[i] = -1;
	}
	cin >> q;
	for (int i=0; i<q; i++) {
		cin >> qry[i].first.second >> qry[i].first.first;
		qry[i].first.second--; qry[i].first.first--;
		qry[i].second = i;
	}
	sort(qry, qry+q);
	int cur = 0;
	init(0, 0, n-1);
	for (int i=0; i<n; i++) {
		update(0, 0, n-1, i, pre[a[i]]);
		if (pre[a[i]] > -1) update(0, 0, n-1, pre[a[i]], n);
		pre[a[i]] = i;
		while (cur < q && qry[cur].first.first == i) {
			pair<int, int> best = query(0, 0, n-1, qry[cur].first.second, qry[cur].first.first);
			if (best.first < qry[cur].first.second) {
				o[qry[cur].second] = a[best.second];
			} else {
				o[qry[cur].second] = 0;
			}
			cur++;
		}
	}
	for (int i=0; i<q; i++) {
		cout << o[i] << endl;
	}
}