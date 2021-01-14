#include <iostream>
using namespace std;
#define MOD 1000000007
int n, k;
int a[110];
long long dp[110][100010];
int main () {
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		dp[i][0] = 1;
		for (int j=1; j<=k; j++) {
			dp[i][j] = (dp[i][j-1]+dp[i-1][j])%MOD;
			if (j-a[i]-1 >= 0) dp[i][j] = (MOD+dp[i][j]-dp[i-1][j-a[i]-1])%MOD;
		}
	}
	cout << dp[n][k] << endl;
}