#include <iostream>
#include <iomanip>
using namespace std;
int n;
double p[3000];
double dp[3000][3000];
double ans = 0;
int main () {
	cout << fixed;
	cout << setprecision(10);
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> p[i];
	}
	dp[0][0] = 1;
	for (int i=1; i<=n; i++) {
		dp[i][0] = dp[i-1][0]*(1.0-p[i-1]);
		for (int j=1; j<=n; j++) {
			dp[i][j] = dp[i-1][j-1]*p[i-1]+dp[i-1][j]*(1.0-p[i-1]);
		}
	}
	for (int i=n/2+1; i<=n; i++) {
		ans += dp[n][i];
	}
	cout << ans << endl;
}