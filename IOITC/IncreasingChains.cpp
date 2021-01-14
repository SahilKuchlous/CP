#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAXN 5005
int n, k;
int a[MAXN];
vector<int> pts;
int dp[MAXN][MAXN];
int best;
int segtree[MAXN][4*MAXN];
void update (int i, int x, int l, int r, int p, int v) {
	if (r < p || l > p) return;
	if (l == r) {
		segtree[i][x] = max(segtree[i][x], v);
		return;
	}
	int m = (l+r)/2;
	update(i, 2*x+1, l, m, p, v);
	update(i, 2*x+2, m+1, r, p, v);
	segtree[i][x] = max(segtree[i][2*x+1], segtree[i][2*x+2]);
}
int query (int i, int x, int l, int r, int a, int b) {
	if (r < a || b < l) return -1;
	if (a <= l && r <= b) return segtree[i][x];
	int m = (l+r)/2;
	return max(query(i, 2*x+1, l, m, a, b), query(i, 2*x+2, m+1, r, a, b));
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		pts.push_back(a[i]);
	}
	sort(pts.begin(), pts.end());
	pts.resize(unique(pts.begin(), pts.end())-pts.begin());
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			dp[i][j] = -1;
		}
		for (int j=0; j<4*pts.size(); j++) {
			segtree[i][j] = -1;
		}
	}
	for (int i=0; i<n; i++) {
		dp[i][0] = best+1;
		int pos = lower_bound(pts.begin(), pts.end(), a[i])-pts.begin();
		for (int j=1; j<=i; j++) {
			int val = query(j-1, 0, 0, pts.size()-1, 0, pos);
			if (val > -1) dp[i][j] = val+1;
		}
		for (int j=0; j<=i; j++) {
			if (dp[i][j] == -1) continue;
			update(j, 0, 0, pts.size()-1, pos, dp[i][j]);
		}
		for (int j=k-1; j<n; j++) {
			best = max(best, dp[i][j]);
		}
	}
	cout << best << endl;
}