#include <iostream>
using namespace std;
int n, p;
int tin[100100];
pair<long long, long long> segtree[400100];
void update (int x, int l, int r, int p, long long v) {
	if (p < l || p > r) return;
	if (l == r) {
		segtree[x] = {v, p};
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
	segtree[x] = min(segtree[2*x+1], segtree[2*x+2]);
}
pair<long long, long long> query1 (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return {1e16, 1e16};
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return min(query1(2*x+1, l, m, a, b), query1(2*x+2, m+1, r, a, b));
}
pair<long long, long long> query2 (int x, int l, int r, long long v) {
	if (l == r) {
		return segtree[x];
	}
	int m = (l+r)/2;
	if (segtree[2*x+1].first <= v) {
		return query2(2*x+1, l, m, v);
	}
	return query2(2*x+2, m+1, r, v);
}
int main () {
	cin >> n >> p;
	for (int i=0; i<n; i++) {
		cin >> tin[i];
		update(0, 0, n-1, i, tin[i]);
	}
	long long ans[n];
	int pos = -1;
	long long timer = 0;
	for (int i=0; i<n; i++) {
		pair<long long, long long> cur;
		if (pos == -1) {
			if (segtree[0].first <= timer) {
				cur = query2(0, 0, n-1, timer);
			} else {
				cur = segtree[0];
				timer = cur.first;
			}
			pos = cur.second;
			update(0, 0, n-1, pos, 1e16);
			timer += p;
			ans[pos] = timer;
		} else {
			cur = query1(0, 0, n-1, 0, pos);
			if (cur.first >= timer) {
				pos = -1;
				i--;
				continue;
			}
			pos = cur.second;
			update(0, 0, n-1, pos, 1e16);
			timer += p;
			ans[pos] = timer;
		}
	}
	for (int i=0; i<n; i++) {
		cout << ans[i] << " ";
	}
	cout << endl;
}