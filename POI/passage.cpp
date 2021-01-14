#include <iostream>
using namespace std;
int max_w, n;
int wt[16], tm[16];
int dp[(1<<16)];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> max_w >> n;
	for (int i=0; i<n; i++) {
		cin >> tm[i] >> wt[i];
	}
	for (int i=1; i<(1<<n); i++) {
		int cur_w = 0, cur_t = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) {
				cur_w += wt[j];
				cur_t = max(cur_t, tm[j]);
			}
		}
		if (cur_w <= max_w) {
			dp[i] = cur_t;
			continue;
		}
		dp[i] = 1e8;
		for (int j=i; j>0; j=(j-1)&i) {
			dp[i] = min(dp[i], dp[j]+dp[i^j]);
		}
	}
	cout << dp[(1<<n)-1] << endl;
}