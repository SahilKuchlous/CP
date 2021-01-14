#include <iostream>
using namespace std;
#define MAXN 5005
#define MOD 1000000007
int n, k;
int a[MAXN];
long long dp[MAXN][MAXN];
long long ttl[MAXN];
long long o;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		dp[0][i] = 1;
	}
	for (int i=1; i<=k; i++) {
		for (int j=0; j<n; j++) {
			dp[i][j] = 0;
			if (j > 0) dp[i][j] = (dp[i][j]+dp[i-1][j-1])%MOD;
			if (j < n-1) dp[i][j] = (dp[i][j]+dp[i-1][j+1])%MOD;
		}
	}
	for (int i=0; i<=k; i++) {
		for (int j=0; j<n; j++) {
			ttl[j] = (ttl[j]+dp[i][j]*dp[k-i][j]%MOD)%MOD;
		}
	}
	while (t--) {
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		o = 0;
		for (int i=0; i<n; i++) {
			o = (o+a[i]*ttl[i]%MOD)%MOD;
		}
		cout << o << endl;
	}
}