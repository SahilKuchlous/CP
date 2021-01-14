#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		long long q[n+1];
		for (int i=1; i<=n; i++) {
			cin >> q[i];
		}
		long long p[m+1];
		for (int i=1; i<=m; i++) {
			cin >> p[i];
		}
		long long t[m+1];
		for (int i=1; i<=m; i++) {
			cin >> t[i];
		}
		pair<long long, long long> tp[m+1];
		for (int i=1; i<=m; i++) {
			tp[i] = {t[i], p[i]};
		}
		sort(tp+1, tp+m+1);
		for (int i=1; i<=m; i++) {
			p[i] = tp[i].second;
			t[i] = tp[i].first;
		}
		long long dp[m+1][n+1];
		dp[0][0] = 0;
		for (int i=1; i<=n; i++) {
			dp[0][i] = dp[0][i-1]+q[i];
		}
		for (int i=1; i<=m; i++) {
			if (dp[i-1][0] >= t[i]) {
				dp[i][0] = 1e13;
			} else {
				dp[i][0] = max(dp[i-1][0]+p[i], t[i]);
			}
			for (int j=1; j<=n; j++) {
				if (dp[i-1][j] >= t[i]) {
					dp[i][j] = dp[i][j-1]+q[j];
				} else {
					dp[i][j] = max(dp[i-1][j]+p[i], t[i]);
				}
			}
		}
		if (dp[m][0] == 1e13) {
			cout << -1 << endl;
		} else {
			cout << dp[m][n] << endl;
		}
	}
}