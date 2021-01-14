#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN 80
#define MAXM 100005
int n, m;
pair<int, int> pts[MAXN];
int dp[MAXM][MAXN];
int best[MAXM];
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		cin >> pts[i].first >> pts[i].second;
		dp[0][i] = 1e8;
	}
	sort(pts, pts+n);
	for (int i=1; i<=m; i++) {
		best[i] = 1e8;
		for (int j=0; j<n; j++) {
			if (i <= pts[j].first) {
				dp[i][j] = min(dp[i-1][j], best[i-1]+max(0, pts[j].first-pts[j].second-i));
			} else {
				int l = pts[j].first-(i-pts[j].first);
				if (l <= 0) {
					dp[i][j] = max(0, i-(pts[j].first+pts[j].second));
				} else {
					dp[i][j] = dp[l][j];
				}
			}
			best[i] = min(best[i], dp[i][j]);
		}
	}
	cout << best[m] << endl;
}