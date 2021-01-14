#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct qs {
	int l, r, x, y;
};
int segtree[800100][110];
void init (int x, int l, int r) {
	for (int i=1; i<=100; i++) {
		segtree[x][i] = i;
	}
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
}
void update (int x, int l, int r, int p, int v1, int v2) {
	if (l > p || r < p) {
		return;
	}
	if (l == r) {
		segtree[x][v1] = v2;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v1, v2);
	update(2*x+2, m+1, r, p, v1, v2);
	for (int i=1; i<=100; i++) {
		segtree[x][i] = segtree[2*x+2][segtree[2*x+1][i]];
	}
}
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int m;
	cin >> m;
	qs qry[m];
	vector<int> st[n], ed[n];
	for (int i=0; i<m; i++) {
		cin >> qry[i].l >> qry[i].r >> qry[i].x >> qry[i].y;
		qry[i].l--; qry[i].r--;
		st[qry[i].l].push_back(i);
		ed[qry[i].r].push_back(i);
	}
	init(0, 0, m-1);
	for (int i=0; i<n; i++) {
		for (auto j: st[i]) {
			update(0, 0, m-1, j, qry[j].x, qry[j].y);
		}
		cout << segtree[0][a[i]] << " ";
		for (auto j: ed[i]) {
			update(0, 0, m-1, j, qry[j].x, qry[j].x);
		}
	}
	cout << endl;
}