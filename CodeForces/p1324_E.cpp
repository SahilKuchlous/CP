#include <iostream>
using namespace std;
int main () {
	int n, h, l, r;
	cin >> n >> h >> l >> r;
	int a[n+1];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int dp[n+1][h];
	dp[0][0] = 0;
	for (int i=1; i<h; i++) {
		dp[0][i] = -1e8;
	}
	int o = 0;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<h; j++) {
			if (l <= j && j <= r) {
				dp[i][j] = 1;
			} else {
				dp[i][j] = 0;
			}
			dp[i][j] += max(dp[i-1][(j-a[i]+h)%h], dp[i-1][(j-a[i]+1+h)%h]);
			o = max(o, dp[i][j]);
		}
	}
	cout << o << endl;
}