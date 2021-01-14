#include <iostream>
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	long long dp[n][m];
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			dp[i][j] = 0;
		}
	}
	int xi, yi, di, ti, ei;
	for (int i=0; i<k; i++) {
		cin >> xi >> yi >> di >> ti >> ei;
		if (ti <= xi+yi && ((xi+yi)-ti)%4 == 0) dp[xi][yi] += ei;
		if (ti <= xi+yi && ((xi+yi)-ti)%4 == 1) dp[xi+di][yi-di] += ei;
		if (ti <= xi+di+yi && ((xi+di+yi)-ti)%4 == 2) dp[xi+di][yi] += ei;
		if (ti <= xi+yi+di && ((xi+yi+di)-ti)%4 == 3) dp[xi][yi+di] += ei;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (i == 0 && j == 0) continue;
			if (i == 0) {
				dp[i][j] += dp[i][j-1];
				continue;
			}
			if (j == 0) {
				dp[i][j] += dp[i-1][j];
				continue;
			}
			dp[i][j] += min(dp[i-1][j], dp[i][j-1]);
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cout << dp[i][j] << " ";
		}
		cout << endl;
	}
	cout << dp[n-1][m-1] << endl;
}