#include <iostream>
using namespace std;
unsigned nChoosek( unsigned n, unsigned k )
{
    if (k > n) return 0;
    if (k * 2 > n) k = n-k;
    if (k == 0) return 1;

    int result = n;
    for( int i = 2; i <= k; ++i ) {
        result *= (n-i+1);
        result /= i;
    }
    return result;
}
int main () {
	int n, m;
	cin >> n >> m;
	m = 2*m;
	long long dp[n+1][m+1];
	for (int i=1; i<=m; i++) {
		dp[1][i] = 1;
	}
	for (int i=2; i<=n; i++) {
		dp[i][1] = dp[i-1][1]+1;
	}
	for (int i=2; i<=n; i++) {
		for (int j=2; j<=m; j++) {
			dp[i][j] = dp[i-1][j]+dp[i][j-1];
			dp[i][j] %= 1000000007;
		}
	}
	cout << dp[n][m] << endl;
}