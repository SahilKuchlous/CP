#include <iostream>
using namespace std;
int main () {
	int n, w;
	cin >> n >> w;
	pair<int, int> items[n+1];
	for (int i=1; i<=n; i++) {
		cin >> items[i].first >> items[i].second;
	}
	long long dp[n+1][w+1];
	for (int i=0; i<=w; i++) {
		dp[0][i] = 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<items[i].first; j++) {
			dp[i][j] = dp[i-1][j];
		}
		for (int j=items[i].first; j<=w; j++) {
			dp[i][j] = max(dp[i-1][j], dp[i-1][j-items[i].first]+items[i].second);
		}
	}
	cout << dp[n][w] << endl;
}