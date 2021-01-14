#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("marathon.in");
ofstream fout("marathon.out");
int n, q;
pair<int, int> points[100100];
pair<int, int> segtree[400100];
int dist (pair<int, int> p1, pair<int, int> p2) {
	return abs(p1.first-p2.first) + abs(p1.second-p2.second);
}
pair<int, int> merge (pair<int, int> p1, pair<int, int> p2, int s1, int s2, int m) {
	pair<int, int> o;
	o.second = p1.second+p2.second+dist(points[m], points[m+1]);
	o.first = o.second;
	if (s1 > 1) o.first = min(o.first, p1.second+p2.second-dist(points[m-1], points[m])+dist(points[m-1], points[m+1]));
	if (s2 > 1) o.first = min(o.first, p1.second+p2.second-dist(points[m+1], points[m+2])+dist(points[m], points[m+2]));
	if (s1 > 2) o.first = min(o.first, p1.first+p2.second+dist(points[m], points[m+1]));
	if (s2 > 2) o.first = min(o.first, p1.second+p2.first+dist(points[m], points[m+1]));
	return o;
}
void create (int x, int l, int r) {
	if (l == r) {
		segtree[x].first = segtree[x].second = 0;
		return;
	}
	int m = (l+r)/2;
	create(2*x+1, l, m);
	create(2*x+2, m+1, r);
	segtree[x] = merge(segtree[2*x+1], segtree[2*x+2], m-l+1, r-m, m);
}
void update (int x, int l, int r, int v) {
	if (v < l || v > r) {
		return;
	}
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, v);
	update(2*x+2, m+1, r, v);
	segtree[x] = merge(segtree[2*x+1], segtree[2*x+2], m-l+1, r-m, m);
}
pair<int, int> query (int x, int l, int r, int a, int b) {
	if (r < a || b < l) {
		return make_pair(-1, -1);
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	pair<int, int> p1 = query(2*x+1, l, m, a, b);
	pair<int, int> p2 = query(2*x+2, m+1, r, a, b);
	if (p1.second == -1) return p2;
	if (p2.second == -1) return p1;
	return merge(p1, p2, m-max(a, l)+1, min(b, r)-m, m);
}
int main () {
	fin >> n >> q;
	for (int i=0; i<n; i++) {
		fin >> points[i].first >> points[i].second;
	}
	char ti;
	int ai, bi, ci;
	create(0, 0, n-1);
	for (int i=0; i<q; i++) {
		fin >> ti;
		if (ti == 'Q') {
			fin >> ai >> bi;
			ai--;
			bi--;
			fout << query(0, 0, n-1, ai, bi).first << endl;
		} else {
			fin >> ai >> bi >> ci;
			ai--;
			points[ai] = make_pair(bi, ci);
			update(0, 0, n-1, ai);
		}
	}
}