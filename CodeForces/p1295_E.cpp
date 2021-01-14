#include <iostream>
using namespace std;
long long presum[200100];
long long segtree[800100];
long long upd[800100];
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x] = presum[l];
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
void update (int x, int l, int r, int a, int b, int v) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		upd[x] += v;
		segtree[x] += v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]) + upd[x];
}
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
		a[i]--;
	}
	int cost[n];
	for (int i=0; i<n; i++) {
		cin >> cost[i];
	}
	int pos[n];
	for (int i=0; i<n; i++) {
		pos[a[i]] = i;
	}
	presum[0] = cost[0];
	for (int i=1; i<n; i++) {
		presum[i] = presum[i-1]+cost[i];
	}
	create(0, 0, n-2);
	long long o = segtree[0];
	for (int i=0; i<n; i++) {
		update(0, 0, n-2, 0, pos[i]-1, cost[pos[i]]);
		update(0, 0, n-2, pos[i], n-2, -cost[pos[i]]);
		o = min(o, segtree[0]);
	}
	cout << o << endl;
}