#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("haybales.in");
ofstream fout("haybales.out");
int n, q;
long long org[200100];
long long segsum[1000000];
long long segmin[1000000];
long long lazy[10000000];
void create (int x, int l, int r) {
	lazy[x] = 0;
	if (l == r) {
		segsum[x] = segmin[x] = org[l];
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segsum[x] = segsum[2*x+1]+segsum[2*x+2];
	segmin[x] = min(segmin[2*x+1], segmin[2*x+2]);
}
void lazy_func (int x, int l, int r) {
	if (lazy[x] > 0) {
		segsum[x] += (r-l+1)*lazy[x];
		segmin[x] += lazy[x];
		if (l != r) {
			lazy[2*x+1] += lazy[x];
			lazy[2*x+2] += lazy[x];
		}
		lazy[x] = 0;
	}
}
void update (int a, int b, int v, int x, int l, int r) {
	if (r < l) {
		return;
	}
	lazy_func(x, l, r);
	if (b < l || a > r) {
		return;
	}
	if (a <= l && r <= b) {
		lazy[x] += v;
		lazy_func(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(a, b, v, 2*x+1, l, m);
	update(a, b, v, 2*x+2, m+1, r);
	segsum[x] = segsum[2*x+1]+segsum[2*x+2];
	segmin[x] = min(segmin[2*x+1], segmin[2*x+2]);
}
long long qury_sum (int a, int b, int x, int l, int r) {
	if (r < l) {
		return 0;
	}
	lazy_func(x, l, r);
	if (b < l || a > r) {
		return 0;
	}
	if (a <= l && r <= b) {
		return segsum[x];
	}
	int m = (l+r)/2;
	long long o = 0;
	o += qury_sum(a, b, 2*x+1, l, m);
	o += qury_sum(a, b, 2*x+2, m+1, r);
	return o;
}
long long qury_min (int a, int b, int x, int l, int r) {
	if (r < l) {
		return 1e12;
	}
	lazy_func(x, l, r);
	if (b < l || a > r) {
		return 1e12;
	}
	if (a <= l && r <= b) {
		return segmin[x];
	}
	int m = (l+r)/2;
	long long o = 1e12;
	o = min(o, qury_min(a, b, 2*x+1, l, m));
	o = min(o, qury_min(a, b, 2*x+2, m+1, r));
	return o;
}
int main () {
	fin >> n >> q;
	for (int i=0; i<n; i++) {
		fin >> org[i];
	}
	create(0, 0, n-1);
	char t;
	int a, b, c;
	for (int i=0; i<q; i++) {
		fin >> t >> a >> b;
		a--;
		b--;
		if (t == 'P') {
			fin >> c;
			update(a, b, c, 0, 0, n-1);
		} else if (t == 'S') {
			fout << qury_sum(a, b, 0, 0, n-1) << endl;
		} else if (t == 'M') {
			fout << qury_min(a, b, 0, 0, n-1) << endl;
		}
	}
}