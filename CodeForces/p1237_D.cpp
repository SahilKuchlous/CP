#include <iostream>
#include <algorithm>
using namespace std;
int segtree[400001];
int a[100001];
int construct (int l, int r, int i) {
	if (l == r) {
		segtree[i] = a[l];
		return segtree[i];
	}
	int m = (l+r)/2;
	int a = construct(l, m, 2*i+1);
	int b = construct(m+1, r, 2*i+2);
	segtree[i] = max(a, b);
	return segtree[i];
}
int query (int l, int r, int x, int y, int i) {
	if (x <= l && r <= y) {
		return segtree[i];
	}
	if (r < x || l > y) {
		return -1;
	}
	int m = (l+r)/2;
	int a = query(l, m, x, y, 2*i+1);
	int b = query(m+1, r, x, y, 2*i+2);
	return max(a, b);
}
int main () {
	int n;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	construct(0, n-1, 0);
	int x = 0;
	bool imp = false;
	int o[n];
	int m;
	for (int i=0; i<n; i++) {
		if (x < i) {
			x = i;
		}
		int j = x;
		while (true) {
			if (j >= i) {
				m = query(0, n-1, i, j, 0);
			} else {
				m = max(query(0, n-1, i, n-1, 0), query(0, n-1, 0, j, 0));
			}
			if (m*1.0/2 > a[(j+1)%n]) {
				o[i] = j-i+1;
				x = j;
				break;
			}
			j = (j+1)%n;
		}
	}
}