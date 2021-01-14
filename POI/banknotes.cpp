#include <iostream>
#include <vector>
using namespace std;
int n;
int val[200];
int cnt[200];
int k;
int dp[20001];
int freq[20001][200];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i=0; i<n; i++) cin >> val[i];
	for (int i=0; i<n; i++) cin >> cnt[i];
	cin >> k;
	for (int i=1; i<=k; i++) {
		dp[i] = 1e8;
		for (int j=0; j<n; j++) freq[i][j] = 1e5;
		int best = -1;
		for (int j=0; j<n; j++) {
			if (i-val[j] < 0 || freq[i-val[j]][j] == cnt[j]) continue;
			if (dp[i-val[j]]+1 < dp[i]) {
				dp[i] = dp[i-val[j]]+1;
				best = j;
			}
		}
		if (best != -1) {
			for (int j=0; j<n; j++) {
				freq[i][j] = freq[i-val[best]][j];
				if (j == best) freq[i][j]++;
			}
		}
	}
	cout << dp[k] << endl;
	for (int i=0; i<n; i++) {
		cout << freq[k][i] << " ";
	}
	cout << endl;
}