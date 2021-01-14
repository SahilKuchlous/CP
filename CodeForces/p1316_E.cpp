#include <iostream>
#include <algorithm>
using namespace std;
struct psn {
	int aud;
	int plr[10];
	bool operator < (const psn &p) const {
		return aud > p.aud;
	}
};
int n, p, k;
psn ppl[100100];
long long dp[100100][128];
int main () {
	cin >> n >> p >> k;
	for (int i=0; i<n; i++) {
		cin >> ppl[i].aud;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<p; j++) {
			cin >> ppl[i].plr[j];
		}
	}
	sort(ppl, ppl+n);
	dp[0][0] = 0;
	for (int i=1; i<(1<<p); i++) {
		dp[0][i] = -1;
	}
	for (int i=1; i<=n; i++) {
		for (int j=0; j<(1<<p); j++) {
			dp[i][j] = -1;
			int cnt = 0;
			for (int k=0; k<p; k++) {
				if ((j & (1<<k)) > 0 && dp[i-1][j-(1<<k)] > -1) {
					cnt++;
					dp[i][j] = max(dp[i][j], dp[i-1][j-(1<<k)]+ppl[i-1].plr[k]);
				}
			}
			if (dp[i-1][j] > -1) {
				if (i-cnt-1 < k) {
					dp[i][j] = max(dp[i][j], dp[i-1][j]+ppl[i-1].aud);
				} else {
					dp[i][j] = max(dp[i][j], dp[i-1][j]);
				}
			}
		}
	}
	cout << dp[n][(1<<p)-1] << endl;
}