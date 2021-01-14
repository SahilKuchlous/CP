#include <iostream>
using namespace std;
int main () {
	int n, w;
	cin >> n >> w;
	pair<int, int> items[n+1];
	for (int i=1; i<=n; i++) {
		cin >> items[i].first >> items[i].second;
	}
	long long dp[n+1][110000];
	dp[0][0] = 0;
	for (int i=1; i<110000; i++) {
		dp[0][i] = 1e13;
	}
	int best = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<items[i].second; j++) {
			dp[i][j] = dp[i-1][j];
		}
		for (int j=items[i].second; j<110000; j++) {
			dp[i][j] = min(dp[i-1][j], dp[i-1][j-items[i].second]+items[i].first);
			if (dp[i][j] <= w) {
				best = max(best, j);
			}
		}
	}
	cout << best << endl;
}