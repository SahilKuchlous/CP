// Figure out why this works.
#include <iostream>
using namespace std;
#define MOD 1000000007
int n;
string s;
long long dp[3005][3005], presum[3005][3005];
long long ans = 0;
int main () {
	cin >> n >> s;
	dp[1][1] = 1;
	for (int i=2; i<=n; i++) {
		for (int j=1; j<=i; j++) {
			presum[i-1][j] = (presum[i-1][j-1]+dp[i-1][j])%MOD;
		}
		if (s[i-2] == '<') {
			for (int j=1; j<=i; j++) {
				dp[i][j] = presum[i-1][j-1];
			}
		} else {
			for (int j=1; j<=i; j++) {
				dp[i][j] = (presum[i-1][i-1]-presum[i-1][j-1]+MOD)%MOD;
			}
		}
		for (int j=1; j<=i; j++) cout << dp[i][j] << " ";
		cout << endl;
	}
	for (int i=1; i<=n; i++) {
		ans = (ans+dp[n][i])%MOD;
	}
	cout << ans << endl;
}