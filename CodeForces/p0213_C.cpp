#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int grid[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> grid[i][j];
		}
	}
	int dp[2*n][n][n];
	dp[0][0][0] = grid[0][0];
	for (int i=1; i<n; i++) {
		for (int p1=0; p1<=i; p1++) {
			for (int p2=0; p2<=i; p2++) {
				dp[i][p1][p2] = grid[p1][i-p1];
				if (p1 != p2) dp[i][p1][p2] += grid[p2][i-p2];
				int best = -1e8;
				if (p1 > 0 && p2 > 0) {
					best = max(best, dp[i-1][p1-1][p2-1]);
				}
				if (p1 > 0 && p2 < i) {
					best = max(best, dp[i-1][p1-1][p2]);
				}
				if (p1 < i && p2 > 0) {
					best = max(best, dp[i-1][p1][p2-1]);
				}
				if (p1 < i && p2 < i) {
					best = max(best, dp[i-1][p1][p2]);
				}
				dp[i][p1][p2] += best;
			}
		}
	}
	for (int i=n; i<2*n-1; i++) {
		for (int p1=0; p1<=2*n-2-i; p1++) {
			for (int p2=0; p2<=2*n-2-i; p2++) {
				dp[i][p1][p2] = grid[i-(n-p1-1)][n-p1-1];
				if (p1 != p2) dp[i][p1][p2] += grid[i-(n-p2-1)][(n-p2-1)];
				dp[i][p1][p2] += max(max(dp[i-1][p1][p2], dp[i-1][p1+1][p2]), max(dp[i-1][p1][p2+1], dp[i-1][p1+1][p2+1]));
			}
		}
	}
	cout << dp[2*n-2][0][0] << endl;
}