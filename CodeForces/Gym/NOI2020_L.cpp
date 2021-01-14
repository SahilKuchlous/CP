#include <iostream>
using namespace std;
int n, m;
pair< long long, long long > segtree[4000000];
long long lazy_open[4000000];
long long lazy_closed[4000000];
int lazy_flip[4000000];
int balls[4000000];
bool open[4000000];
void init (int x, int l, int r) {
	lazy_open[x] = 0;
	lazy_closed[x] = 0;
	lazy_flip[x] = 1;
	if (l == r) {
		segtree[x] = make_pair(open[l], balls[l]);
		return;
	}
	int m = (l+r)/2;
	init(2*x+1, l, m);
	init(2*x+2, m+1, r);
	segtree[x].first = segtree[2*x+1].first+segtree[2*x+2].first;
	segtree[x].second = segtree[2*x+1].second+segtree[2*x+2].second;
}
void update (int x, int l, int r) {
	if (lazy_open[x] > 0) {
		segtree[x].second += lazy_open[x]*segtree[x].first;
		if (l < r) {
			if (lazy_flip[2*x+1] == 1) {
				lazy_open[2*x+1] += lazy_open[x];
			} else {
				lazy_closed[2*x+1] += lazy_open[x];
			}
			if (lazy_flip[2*x+2] == 1) {
				lazy_open[2*x+2] += lazy_open[x];
			} else {
				lazy_closed[2*x+2] += lazy_open[x];
			}
		}
		lazy_open[x] = 0;
	}
	if (lazy_closed[x] > 0) {
		segtree[x].second += lazy_closed[x]*(r-l+1-segtree[x].first);
		if (l < r) {
			if (lazy_flip[2*x+1] == 1) {
				lazy_closed[2*x+1] += lazy_closed[x];
			} else {
				lazy_open[2*x+1] += lazy_closed[x];
			}
			if (lazy_flip[2*x+2] == 1) {
				lazy_closed[2*x+2] += lazy_closed[x];
			} else {
				lazy_open[2*x+2] += lazy_closed[x];
			}
		}
		lazy_closed[x] = 0;
	}
	if (lazy_flip[x] == -1) {
		segtree[x].first = r-l+1-segtree[x].first;
		lazy_flip[x] *= -1;
		if (l < r) {
			lazy_flip[2*x+1] *= -1;
			lazy_flip[2*x+2] *= -1;
		}
	}
}
void flip (int x, int l, int r, int a, int b) {
	if (lazy_open[x] > 0 || lazy_closed[x] > 0 || lazy_flip[x] == -1) {
		update(x, l, r);
	}
	update(x, l, r);
	if (a <= l && r <= b) {
		lazy_flip[x] = lazy_flip[x]*-1;
		update(x, l, r);
		return;
	}
	if (l > b || r < a) {
		return;
	}
	int m = (l+r)/2;
	flip(2*x+1, l, m, a, b);
	flip(2*x+2, m+1, r, a, b);
	segtree[x].first = segtree[2*x+1].first+segtree[2*x+2].first;
}
void add (int x, int l, int r, int a, int b, int v) {
	if (lazy_open[x] > 0 || lazy_closed[x] > 0 || lazy_flip[x] == -1) {
		update(x, l, r);
	}
	if (a <= l && r <= b) {
		lazy_open[x] += v;
		update(x, l, r);
		return;
	}
	if (l > b || r < a) {
		return;
	}
	int m = (l+r)/2;
	add(2*x+1, l, m, a, b, v);
	add(2*x+2, m+1, r, a, b, v);
	segtree[x].second = segtree[2*x+1].second+segtree[2*x+2].second;
}
long long query (int x, int l, int r, int a, int b) {
	if (lazy_open[x] > 0 || lazy_closed[x] > 0 || lazy_flip[x] == -1) {
		update(x, l, r);
	}
	if (a <= l && r <= b) {
		return segtree[x].second;
	}
	if (l > b || r < a) {
		return 0;
	}
	long long o = 0;
	int m = (l+r)/2;
	o += query(2*x+1, l, m, a, b);
	o += query(2*x+2, m+1, r, a, b);
	return o;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> balls[i];
	}
	for (int i=0; i<n; i++) {
		cin >> open[i];
	}
	init(0, 0, n-1);
	int type, a, b, v;
	for (int i=0; i<m; i++) {
		cin >> type >> a >> b;
		a--;
		b--;
		if (type == 1) {
			flip(0, 0, n-1, a, b);
		} else if (type == 2) {
			cin >> v;
			add(0, 0, n-1, a, b, v);
		} else if (type == 3) {
			cout << query(0, 0, n-1, a, b) << endl;
		}
	}
}