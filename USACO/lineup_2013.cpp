#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("lineup.in");
ofstream fout("lineup.out");
int n, k;
int a[100100];
map<int, int> p;
map< int, vector<int> > pos;
long long segtree[400100];
int ans = 0;
void update (int x, int l, int r, int a, int b, int v) {
	if (b < l || r < a) {
		return;
	}
	if (a <= l && r <= b) {
		segtree[x] += v;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b, v);
	update(2*x+2, m+1, r, a, b, v);
}
long long query (int x, int l, int r, int v) {
	if (v < l || v > r) {
		return 0;
	}
	if (l == r) {
		return segtree[x];
	}
	int m = (l+r)/2;
	long long o = segtree[x];
	o += query(2*x+1, l, m, v);
	o += query(2*x+2, m+1, r, v);
	return o;
}
int binsearch (int i) {
	int l=0, r=i, m, o;
	while (l <= r) {
		m = (l+r)/2;
		if (query(0, 0, n, m) <= k+1) {
			r = m-1;
		} else {
			o = m;
			l = m+1;
		}
	}
	return o;
}
int main () {
	fin >> n >> k;
	for (int i=1; i<=n; i++) {
		fin >> a[i];
		pos[a[i]].push_back(i);
		p[a[i]] = 0;
	}
	for (int i=0; i<4*n; i++) {
		segtree[i] = 0;
	}
	update(0, 0, n, 0, 0, 1e6);
	for (int i=1; i<=n; i++) {
		update(0, 0, n, p[a[i]]+1, i, 1);
		int e = binsearch(i);
		int cnt = lower_bound(pos[a[i]].begin(), pos[a[i]].end(), i)-lower_bound(pos[a[i]].begin(), pos[a[i]].end(), e)+1;
		ans = max(ans, cnt);
		p[a[i]] = i;
	}
	fout << ans << endl;
}