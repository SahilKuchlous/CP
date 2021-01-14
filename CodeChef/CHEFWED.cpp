#include <iostream>
using namespace std;
#define MAXN 1005
int n, k;
int grp[MAXN];
int dp[MAXN];
int freq[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> k;
		for (int i=1; i<=n; i++) {
			cin >> grp[i];
		}
		dp[0] = 0;
		for (int i=1; i<=n; i++) {
			for (int j=1; j<=100; j++) {
				freq[j] = 0;
			}
			int cost = 0;
			dp[i] = dp[i-1]+k;
			for (int j=i; j>0; j--) {
				if (freq[grp[j]]) cost++;
				if (freq[grp[j]] == 1) cost++;
				freq[grp[j]]++;
				dp[i] = min(dp[i], dp[j-1]+cost+k);
			}
		}
		cout << dp[n] << '\n';
	}
}