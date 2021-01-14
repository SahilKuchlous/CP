#include <iostream>
using namespace std;
long long dp[1<<20][21];
long long cnt[21][21];
long long cur[21];
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=n-1; i>=0; i--) {
		cur[a[i]]++;
		for (int j=1; j<=20; j++) {
			cnt[a[i]][j] += cur[j];
			if (a[i] != j) dp[0][j] += cur[j];
		}
	}
	for (int i=1; i<(1<<20); i++) {
		long long best_cnt = 1e16;
		int best_val = 0;
		for (int j=0; j<20; j++) {
			if (i & (1<<j)) {
				if (best_cnt > dp[i-(1<<j)][0]+dp[i-(1<<j)][j+1]) {
					best_cnt = dp[i-(1<<j)][0]+dp[i-(1<<j)][j+1];
					best_val = j;
				}
			}
		}
		dp[i][0] = best_cnt;
		for (int j=1; j<=20; j++) {
			dp[i][j] = dp[i-(1<<best_val)][j] - cnt[best_val+1][j];
		}
	}
	cout << dp[(1<<20)-1][0] << endl;
}