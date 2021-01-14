#include <fstream>
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
ifstream fin("bphoto.in");
ofstream fout("bphoto.out");
int segtree[400000];
void update (int v, int l, int r, int x) {
	if (v < l || v > r) {
		return;
	}
	if (v == l && v == r) {
		segtree[x]++;
		return;
	}
	int m = (l+r)/2;
	update(v, l, m, 2*x+1);
	update(v, m+1, r, 2*x+2);
	segtree[x]++;
}
int query (int a, int b, int l, int r, int x) {
	if (r < a || l > b) {
		return 0;
	}
	if (a <= l && r <= b) {
		return segtree[x];
	}
	int m = (l+r)/2;
	int o = query(a, b, l, m, 2*x+1);
	o += query(a, b, m+1, r, 2*x+2);
	return o;
}
int main () {
	int n;
	fin >> n;
	pair<int, int> ranks[n];
	int h;
	for (int i=0; i<n; i++) {
		fin >> h;
		ranks[i] = make_pair(h, i);
	}
	sort(ranks, ranks+n, greater< pair<int, int> >());
	for (int i=0; i<4*n; i++) {
		segtree[i] = 0;
	}
	int o = 0;
	int left, right;
	for (int i=0; i<n; i++) {
		left = query(0, ranks[i].second, 0, n-1, 0);
		right = query(ranks[i].second, n-1, 0, n-1, 0);
		// cout << ranks[i].first << " " << left << " " << right << endl;
		if (max(left, right) > 2*min(left, right)) {
			// cout << ranks[i].first << endl;
			o++;
		}
		update(ranks[i].second, 0, n-1, 0);
	}
	fout << o << endl;
}