#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int cost[n][3];
	for (int i=0; i<n; i++) {
		for (int j=0; j<3; j++) {
			cin >> cost[i][j];
		}
	}
	int dp[n][3];
	dp[0][0] = cost[0][0];
	dp[0][1] = cost[0][1];
	dp[0][2] = cost[0][2];
	for (int i=1; i<n; i++) {
		dp[i][0] = max(dp[i-1][1], dp[i-1][2])+cost[i][0];
		dp[i][1] = max(dp[i-1][0], dp[i-1][2])+cost[i][1];
		dp[i][2] = max(dp[i-1][0], dp[i-1][1])+cost[i][2];
	}
	cout << max(dp[n-1][0], max(dp[n-1][1], dp[n-1][2])) << endl;
}