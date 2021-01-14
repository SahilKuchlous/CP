#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int dp[n][3];
	dp[0][0] = 0;
	dp[0][1] = a[0];
	dp[0][2] = a[0];
	for (int i=1; i<n; i++) {
		dp[i][0] = max(dp[i-1][0], max(dp[i-1][1], dp[i-1][2]));
		dp[i][1] = a[i]+dp[i-1][0];
		dp[i][2] = a[i]+dp[i-1][1];
	}
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
}