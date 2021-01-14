#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int seq[n];
		char inp;
		int total = 0;
		int presum[n+1];
		presum[0] = 0;
		for (int i=0; i<n; i++) {
			cin >> inp;
			seq[i] = inp-'0';
			if (seq[i] == 1) {
				total++;
			}
			presum[i+1] = presum[i]+seq[i];
		}
		int dp[n];
		int o = total;
		int cnt = 0;
		for (int i=0; i<n; i++) {
			if (seq[i] == 1) cnt++;
			dp[i] = 1-seq[i];
			if (i >= k) dp[i] += dp[i-k];
			dp[i] += presum[i]-presum[max(0, i-k+1)];
			dp[i] = min(dp[i], cnt);
			o = min(o, dp[i]+(total-cnt));
		}
		cout << o << endl;
	}
}