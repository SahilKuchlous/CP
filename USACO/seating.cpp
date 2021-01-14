#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
ifstream fin("seating.in");
ofstream fout("seating.out");
int n, m;
vector<int> segtree[2000100];
int lazy[2000100];
void create (int x, int l, int r) {
	lazy[x] = -1;
	segtree[x] = {r-l+1, r-l+1, r-l+1};
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
}
void lazy_upd (int x, int l, int r) {
	if (lazy[x] == -1) return;
	if (lazy[x] == 0) {
		segtree[x][0] = segtree[x][1] = segtree[x][2] = r-l+1;
	} else {
		segtree[x][0] = segtree[x][1] = segtree[x][2] = 0;
	}
	if (l != r) {
		lazy[2*x+1] = lazy[2*x+2] = lazy[x];
	}
	lazy[x] = -1;
}
void merge (vector<int>& v, vector<int>& v1, int s1, vector<int>& v2, int s2) {
	v[0] = max(v1[0], max(v2[0], v1[2]+v2[1]));
	if (v1[0] == s1) {
		v[1] = v1[0]+v2[1];
	} else {
		v[1] = v1[1];
	}
	if (v2[0] == s2) {
		v[2] = v1[2]+v2[0];
	} else {
		v[2] = v2[2];
	}
}
void update (int x, int l, int r, int a, int b, int v) {
	lazy_upd(x, l, r);
	if (r < a || l > b) {
		return;
	}
	if (a <= l && r <= b) {
		lazy[x] = v;
		lazy_upd(x, l, r);
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
	merge(segtree[x], segtree[2*x+1], m-l+1, segtree[2*x+2], r-m);
}
int query (int x, int l, int r, int v) {
	lazy_upd(x, l, r);
	if (l == r) {
		if (segtree[x][0] < v) {
			return -1;
		} else {
			return l;
		}
	}
	int m = (l+r)/2;
	lazy_upd(2*x+1, l, m);
	lazy_upd(2*x+2, m+1, r);
	if (segtree[2*x+1][0] >= v) {
		return query(2*x+1, l, m, v);
	}
	if (segtree[2*x+1][2]+segtree[2*x+2][1] >= v) {
		return m-segtree[2*x+1][2]+1;
	}
	if (segtree[2*x+2][0] >= v) {
		return query(2*x+2, m+1, r, v);
	}
	return -1;
}
int main () {
	ios_base::sync_with_stdio(false);
	fin >> n >> m;
	create(0, 0, n-1);
	char ti;
	int pi, ai, bi;
	int o = 0;
	for (int i=0; i<m; i++) {
		fin >> ti;
		if (ti == 'A') {
			fin >> pi;
			int s = query(0, 0, n-1, pi);
			if (s > -1) {
				update(0, 0, n-1, s, s+pi-1, 1);
			} else {
				o++;
			}
		} else {
			fin >> ai >> bi;
			update(0, 0, n-1, ai, bi, 0);
		}
	}
	fout << o << endl;
}