#include <iostream>
#include <fstream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("haircut.in");
ofstream fout("haircut.out");
int segtree[400100];
void update (int x, int l, int r, int a, int b) {
	if (a > r || b < l) {
		return;
	}
	if (a <= l && r <= b) {
		segtree[x]++;
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, a, b);
	update(2*x+2, m+1, r, a, b);
}
int query (int x, int l, int r, int v) {
	if (v < l || v > r) {
		return 0;
	}
	if (l == r) {
		return segtree[x];
	}
	int o = segtree[x];
	int m = (l+r)/2;
	o += query(2*x+1, l, m, v);
	o += query(2*x+2, m+1, r, v);
	return o;
}
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	int inv[n];
	long long total = 0;
	multiset< pair<int, int>, greater< pair<int, int> > > cur;
	for (int i=0; i<n; i++) {
		inv[i] = query(0, 0, n, a[i]);
		update(0, 0, n, 0, a[i]-1);
		total += inv[i];
		cur.insert(make_pair(a[i], inv[i]));
	}
	vector<long long> o;
	for (int i=n-1; i>=0; i--) {
		while (cur.size() > 0 && cur.begin()->first >= i) {
			total -= cur.begin()->second;
			cur.erase(cur.begin());
		}
		o.push_back(total);
	}
	reverse(o.begin(), o.end());
	for (auto i: o) {
		fout << i << endl;
	}
}