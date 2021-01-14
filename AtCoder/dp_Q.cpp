#include <iostream>
using namespace std;
int n;
int ht[200100], val[200100];
long long segtree[800100];
void update (int x, int l, int r, int p, long long v) {
	if (p < l || p > r) return;
	segtree[x] = max(segtree[x], v);
	if (l == r) return;
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
}
long long query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return max(query(2*x+1, l, m, a, b), query(2*x+2, m+1, r, a, b));
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> ht[i];
		ht[i]--;
	}
	for (int i=0; i<n; i++) {
		cin >> val[i];
	}
	long long ans = 0;
	for (int i=0; i<n; i++) {
		long long cur = query(0, 0, n-1, 0, ht[i])+val[i];
		update(0, 0, n-1, ht[i], cur);
		ans = max(ans, cur);
	}
	cout << ans << endl;
}