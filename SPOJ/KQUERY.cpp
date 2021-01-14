#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, q;
int a[31000];
vector<int> segtree[200000];
void build (int x, int l, int r) {
	if (l == r) {
		segtree[x] = {a[l]};
		return;
	}
	int m = (l+r)/2;
	build(2*x+1, l, m);
	build(2*x+2, m+1, r);
	merge(segtree[2*x+1].begin(), segtree[2*x+1].end(), segtree[2*x+2].begin(), segtree[2*x+2].end(), back_inserter(segtree[x]));
}
int query (int x, int l, int r, int a, int b, int v) {
	if (b < l || r < a) {
		return 0;
	}
	if (a <= l && r <= b) {
		return segtree[x].end() - upper_bound(segtree[x].begin(), segtree[x].end(), v);
	}
	int m = (l+r)/2;
	int o = 0;
	o += query(2*x+1, l, m, a, b, v);
	o += query(2*x+2, m+1, r, a, b, v);
	return o;
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	build(0, 0, n-1);
	int q;
	cin >> q;
	int ai, bi, vi;
	for (int i=0; i<q; i++) {
		cin >> ai >> bi >> vi;
		ai--;
		bi--;
		cout << query(0, 0, n-1, ai, bi, vi) << endl;
	}
}