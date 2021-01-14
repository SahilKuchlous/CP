#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n+1];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int dp[n+1][61];
	for (int i=-30; i<=30; i++) {
		dp[0][i+30] = -1e8;
	}
	int o = 0;
	for (int i=1; i<=n; i++) {
		for (int j=-30; j<a[i]; j++) {
			dp[i][j+30] = -1e8;
		}
		dp[i][a[i]+30] = max(0, dp[i-1][a[i]+30]) + a[i];
		for (int j=a[i]+1; j<=30; j++) {
			dp[i][j+30] = dp[i-1][j+30]+a[i];
		}
		o = max(o, dp[i][0]+30);
		for (int j=-29; j<=30; j++) {
			dp[i][j+30] = max(dp[i][j+30], dp[i][j+29]);
			o = max(o, dp[i][j+30]-j);
		}
	}
	cout << o << endl;
}