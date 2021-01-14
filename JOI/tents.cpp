#include <iostream>
#define MOD 1000000007
using namespace std;
long long dp[3001][3001];
int main () {
	int n, m;
	cin >> n >> m;
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			if (i == 0 || j == 0) {
				dp[i][j] = 1;
				continue;
			}
			dp[i][j] = dp[i-1][j];
			dp[i][j] = (dp[i][j]+4ll*dp[i-1][j-1]*j)%MOD;
			dp[i][j] = (dp[i][j]+1ll*dp[i-1][max(0, j-2)]*j*(j-1)/2)%MOD;
			dp[i][j] = (dp[i][j]+1ll*dp[max(0, i-2)][j-1]*j*(i-1))%MOD;
		}
	}
	cout << dp[n][m]-1 << endl;
}