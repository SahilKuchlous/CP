#include <iostream>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int dp[n][m];
	int presum[n][m];
	long long ans;
	presum[0][0] = 1;
	for (int i=0; i<m; i++) {
		dp[0][i] = 1;
		if (i != 0) presum[0][i] = presum[0][i-1]+1;
	}
	for (int i=1; i<n; i++) {
		presum[i][0] = 1;
		for (int j=0; j<m; j++) {
			dp[i][j] = presum[i-1][j];
			dp[i][j] %= 1000000007;
			if (j != 0) {
				ans = presum[i][j-1]+dp[i][j];
				ans %= 1000000007;
				presum[i][j] = ans;
			}
		}
	}
	long long o = 1;
	for (int i=0; i<n; i++) {
		for (int j=1; j<m; j++) {
			if (i == n-1) {
				o += dp[i][j];
			} else {
				o += ((long long)dp[i][j])*presum[n-i-2][j-1];
			}
			o %= 1000000007;
		}
	}
	cout << o << endl;
}