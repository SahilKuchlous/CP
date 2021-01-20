#include <iostream>
#include <algorithm>
using namespace std;
int segtree[800000];
void update (int x, int l, int r, int p) {
	if (r < p || l > p) return;
	if (l == r) {
		segtree[x] = 1;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p);
	update(2*x+2, m+1, r, p);
	segtree[x] = segtree[2*x+1]+segtree[2*x+2];
}
int query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) return 0;
	if (a <= l && r <= b) return segtree[x];
	int m = (l+r)/2;
	return query(2*x+1, l, m, a, b)+query(2*x+2, m+1, r, a, b);
}
int main () {
	int h, w, m;
	cin >> h >> w >> m;
	int x_block[h], y_block[w];
	for (int i=0; i<h; i++) {
		x_block[i] = w;
	}
	for (int i=0; i<w; i++) {
		y_block[i] = h;
	}
	pair<int, int> obs[m];
	for (int i=0; i<m; i++) {
		cin >> obs[i].first >> obs[i].second;
		obs[i].first--; obs[i].second--;
		x_block[obs[i].first] = min(x_block[obs[i].first], obs[i].second);
		y_block[obs[i].second] = min(y_block[obs[i].second], obs[i].first);
	}
	long long o = 0;
	pair<int, int> ord[y_block[0]];
	for (int i=0; i<y_block[0]; i++) {
		o += x_block[i];
		ord[i] = make_pair(x_block[i], i);
	}
	for (int i=y_block[0]; i<h; i++) {
		update(0, 0, h-1, i);
	}
	sort(ord, ord+y_block[0]);
	int pos = 0;
	for (int i=0; i<x_block[0]; i++) {
		while (pos < y_block[0] && ord[pos].first == i) {
			update(0, 0, h-1, ord[pos].second);
			pos++;
		}
		o += query(0, 0, h-1, 0, y_block[i]-1);
	}
	cout << o << endl;
}