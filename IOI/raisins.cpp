#include <iostream>
#include <queue>
using namespace std;
int n, m;
int grid[50][50];
int presum[50][50];
long long dp[50][50][50][50];
int calc_sum (int x1, int y1, int x2, int y2) {
	if (x2 < x1 || y2 < y1) return 0;
	int r = presum[x2][y2];
	if (x1 > 0) r -= presum[x1-1][y2];
	if (y1 > 0) r -= presum[x2][y1-1];
	if (x1 > 0 && y1 > 0) r += presum[x1-1][y1-1];
	return r;
}
int main () {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			presum[i][j] = grid[i][j];
			if (i > 0) presum[i][j] += presum[i-1][j];
			if (j > 0) presum[i][j] += presum[i][j-1];
			if (i > 0 && j > 0) presum[i][j] -= presum[i-1][j-1];
		}
	}
	for (int sx=0; sx<n; sx++) {
		for (int sy=0; sy<m; sy++) {
			for (int x1=0; x1+sx<n; x1++) {
				for (int y1=0; y1+sy<m; y1++) {
					if (sx == 0 && sy == 0) {
						dp[x1][y1][x1][y1] = 0;
						continue;
					}
					int x2 = x1+sx;
					int y2 = y1+sy;
					dp[x1][y1][x2][y2] = calc_sum(x1, y1, x2, y2);
					long long best = 1e14;
					for (int i=x1; i<x2; i++) {
						best = min(best, dp[x1][y1][i][y2]+dp[i+1][y1][x2][y2]);
					}
					for (int i=y1; i<y2; i++) {
						best = min(best, dp[x1][y1][x2][i]+dp[x1][i+1][x2][y2]);
					}
					if (best < 1e14) dp[x1][y1][x2][y2] += best;
					// cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << dp[x1][y1][x2][y2] << endl;
				}
			}
		}
	}
	cout << dp[0][0][n-1][m-1] << endl;
}