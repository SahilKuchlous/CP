#include <iostream>
#include <cmath>
using namespace std;
int segtree[4000000];
void update (int n, int x, int l, int r) {
	if (l == r && l == n) {
		segtree[x] = 1;
		return;
	}
	if (l > n || r < n) {
		return;
	}
	segtree[x]++;
	int m = (l+r)/2;
	update(n, 2*x+1, l, m);
	update(n, 2*x+2, m+1, r);
}
int query (int a, int b, int x, int l, int r) {
	if (a <= l && r <= b) {
		return segtree[x];
	}
	if (b < l || a > r) {
		return 0;
	}
	int o = 0;
	int m = (l+r)/2;
	o += query(a, b, 2*x+1, l, m);
	o += query(a, b, 2*x+2, m+1, r);
	return o;
}
int main () {
	int m;
	cin >> m;
	int a1[m];
	for (int i=0; i<m; i++) {
		cin >> a1[i];
	}
	int n;
	cin >> n;
	int a2[n];
	for (int i=0; i<n; i++) {
		cin >> a2[i];
	}
	int a[n+m+1];
	int pos[n+m+1];
	for (int i=0; i<m; i++) {
		a[i] = a1[i];
	}
	a[m] = 0;
	for (int i=0; i<n; i++) {
		a[m+n-i] = a2[i];
	}
	for (int i=0; i<=m+n; i++) {
		pos[a[i]] = i;
	}
	for (int i=0; i<4000000; i++) {
		segtree[i] = 0;
	}
	long long o = 0;
	for (int i=0; i<m+n; i++) {
		o += abs(pos[i]-pos[i+1])-1-query(min(pos[i], pos[i+1]), max(pos[i],pos[i+1]), 0, 0, n+m);
		// cout << pos[i] << " " << pos[i+1] << " " << o << endl;
		update(pos[i], 0, 0, n+m);
	}
	cout << o << endl;
}