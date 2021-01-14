#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream fin("nocross.in");
ofstream fout("nocross.out");
int segtree[400100];
void update (int x, int l, int r, int p, int v) {
	if (p < l || p > r) {
		return;
	}
	segtree[x] = max(segtree[x], v);
	if (l == r) {
		return;
	}
	int m = (l+r)/2;
	update(2*x+1, l, m, p, v);
	update(2*x+2, m+1, r, p, v);
}
int query (int x, int l, int r, int p) {
	if (l > p) {
		return 0;
	}
	if (r <= p) {
		return segtree[x];
	}
	int m = (l+r)/2;
	int o = query(2*x+1, l, m, p);
	o = max(o, query(2*x+2, m+1, r, p));
	return o;
}
int main () {
	int n;
	fin >> n;
	int seq_l[n+1], pos_l[n+1];
	for (int i=1; i<=n; i++) {
		fin >> seq_l[i];
		pos_l[seq_l[i]] = i;
	}
	int seq_r[n+1], pos_r[n+1];
	for (int i=1; i<=n; i++) {
		fin >> seq_r[i];
		pos_r[seq_r[i]] = i;
	}
	vector<int> opts[n+1];
	for (int i=1; i<=n; i++) {
		for (int j=max(1, seq_l[i]-4); j<=min(n, seq_l[i]+4); j++) {
			opts[i].push_back(pos_r[j]);
		}
		sort(opts[i].begin(), opts[i].end(), greater<int>());
	}
	int dp[n+1];
	for (int i=0; i<=n; i++) {
		dp[i] = 0;
	}
	int o = 0;
	for (int i=1; i<=n; i++) {
		for (auto j: opts[i]) {
			int ans = query(0, 0, n-1, j-1);
			o = max(o, ans+1);
			update(0, 0, n-1, j, ans+1);
		}
	}
	fout << o << endl;
}