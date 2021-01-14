// Overcounting
#include <iostream>
using namespace std;
#define MOD 1000000007
#define MAXN 205
int n;
string s;
int ttl = 0, min_v = 0;
long long dp[MAXN][2*MAXN][MAXN]; // Number of sequences of length i with sum j such that min sum in sequence is k
long long o = 0;
int main () {
	cin >> n >> s;
	for (auto i: s) {
		ttl += (i=='(' ? 1:-1);
		min_v = min(min_v, ttl);
	}
	n *= 2;
	dp[0][n][n] = 1;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<=2*n; j++) {
			for (int k=0; k<=j; k++) {
				if (j > 0) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j-1][k])%MOD;
				if (j < 2*n) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j+1][k])%MOD;
				if (j == k) dp[i][j][k] = (dp[i][j][k]+dp[i-1][j+1][k+1])%MOD;
			}
		}
	}
	for (int i=0; i<=n-s.length(); i++) {
		for (int j=n+min_v; j<=2*n; j++) {
			if (dp[i][j][n] == 0) continue;
			int rem_len = n-s.length()-i;
			int rem_sum = -(j-n)-ttl;
			o = (o + dp[i][j][n]*dp[rem_len][n+rem_sum][n+rem_sum]%MOD)%MOD;
		}
	}
	cout << o << endl;
}