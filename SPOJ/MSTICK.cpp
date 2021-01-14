#include <iostream>
#include <limits.h>
#include <cmath>
using namespace std;
int n;
int segtree[100001][2];
int b[100001];
void create (int node, int l, int r) {
	if (l == r) {
		segtree[node][0] = b[l];
		segtree[node][1] = b[l];
		return;
	}
	int m = (r+l)/2;
	create(2*node+1, l, m);
	create(2*node+2, m+1, r);
	segtree[node][0] = min(segtree[2*node+1][0], segtree[2*node+2][0]);
	segtree[node][1] = max(segtree[2*node+1][1], segtree[2*node+2][1]);
}
double query (int node, int l, int r, int x, int y, int type) {
	if (l>y || r<x) {
		if (type == 1) {
			return 0;
		} else {
			return INT_MAX;
		}
	}
	if (l>=x && r<=y) {
		return segtree[node][type];
	}
	int m = (r+l)/2;
	int n1 = query(2*node+1, l, m, x, y, type);
	int n2 = query(2*node+2, m+1, r, x, y, type);
	if (type == 0) {
		return min(n1, n2);
	} else {
		return max(n1, n2);
	}
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> b[i];
	}
	create(0, 0, n-1);
	int q;
	cin >> q;
	int x, y;
	double maxl, maxr, maxc, minc;
	double out;
	for (int i=0; i<q; i++) {
		cin >> x >> y;
		if (x > 0) {
			maxl = query(0, 0, n-1, 0, x-1, 1);
		} else {
			maxl = -INT_MAX;
		}
		if (y+1 < n) {
			maxr = query(0, 0, n-1, y+1, n-1, 1);
		} else {
			maxr = -INT_MAX;
		}
		maxc = query(0, 0, n-1, x, y, 1);
		minc = query(0, 0, n-1, x, y, 0);
		// cout << maxl << " " << maxr << " " << maxc << " " << minc << endl;
		out = max(maxl+minc*1.0, max(maxr+minc*1.0, minc+(maxc-minc)*1.0/2));
		if (floor(out) == out) {
			cout << out << ".0" << endl;
		} else {
			cout << out << endl;
		}
	}
}