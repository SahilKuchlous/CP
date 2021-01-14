#include <iostream>
using namespace std;
int a, n, m;
bool rain[2005];
int loc[2005];
int cost[2005];
long long dp[2005][2005];
long long best[2005];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> a >> n >> m;
	int ai, bi;
	for (int i=0; i<n; i++) {
		cin >> ai >> bi;
		ai++; bi++;
		for (int j=ai+1; j<=bi; j++) {
			rain[j] = true;
		}
	}
	for (int i=1; i<=m; i++) {
		cin >> loc[i] >> cost[i];
		loc[i]++;
	}
	int prv = 0;
	for (int i=1; i<=a+1; i++) {
		best[i] = 1e12;
		if (!rain[i]) {
			dp[i][0] = best[prv];
			best[i] = min(best[i], dp[i][0]);
		} else {
			dp[i][0] = 1e12;
			prv = i;
		}
		for (int j=1; j<=m; j++) {
			if (loc[j] >= i) {
				dp[i][j] = 1e12;
				continue;
			}
			dp[i][j] = best[loc[j]]+cost[j]*(i-loc[j]);
			best[i] = min(best[i], dp[i][j]);
		}
	}
	if (best[a+1] < 1e12) {
		cout << best[a+1] << endl;
	} else {
		cout << -1 << endl;
	}
}