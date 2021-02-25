#include <iostream>
using namespace std;
#define MOD 100000007
int a[2][105];
long long dp[105][105][205][2];
void solve () {
	int n, m, p;
	cin >> n >> m >> p;
	for (int i=0; i<n; i++) {
		cin >> a[0][i];
	}
	for (int i=0; i<m; i++) {
		cin >> a[1][i];
	}
	dp[0][0][0][0] = 1;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			for (int k=1; k<=p; k++) {
				dp[i][j][k][0] = dp[i][j][k][1] = 0;
				if (i > 0) {
					if (i > 1 && a[0][i-2] == a[0][i-1]) {
						dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][j][k][0]) % MOD;
					} else {
						dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][j][k-1][0]) % MOD;
					}
					if (j > 0 && a[1][j-1] == a[0][i-1]) {
						dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][j][k][1]) % MOD;
					} else {
						dp[i][j][k][0] = (dp[i][j][k][0] + dp[i-1][j][k-1][1]) % MOD;
					}
				}
				if (j > 0) {
					if (i > 0 && a[0][i-1] == a[1][j-1]) {
						dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j-1][k][0]) % MOD;
					} else {
						dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j-1][k-1][0]) % MOD;
					}
					if (j > 1 && a[1][j-2] == a[1][j-1]) {
						dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j-1][k][1]) % MOD;
					} else {
						dp[i][j][k][1] = (dp[i][j][k][1] + dp[i][j-1][k-1][1]) % MOD;
					}
				}
			}
		}
	}
	cout << (dp[n][m][p][0]+dp[n][m][p][1])%MOD << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}