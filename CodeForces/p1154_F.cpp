#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int n, m, k;
int inp[200005];
vector<int> a;
int presum[2005];
int sales[2005];
int dp[2005];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		cin >> inp[i];
	}
	sort(inp, inp+n);
	for (int i=0; i<k; i++) {
		a.push_back(inp[i]);
	}
	reverse(a.begin(), a.end());
	for (int i=1; i<=k; i++) {
		presum[i] = presum[i-1]+a[i-1];
	}
	int ai, bi;
	for (int i=0; i<=k; i++) {
		sales[i] = 1e6;
	}
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		if (ai > k) continue;
		bi = ai-bi;
		sales[ai] = min(sales[ai], bi);
	}
	for (int i=1; i<=k; i++) {
		dp[i] = dp[i-1]+a[i-1];
		for (int j=0; j<=i; j++) {
			if (sales[j] == 1e6) continue;
			int score = dp[i-j]+presum[i-j+sales[j]]-presum[i-j];
			dp[i] = min(dp[i], score);
		}
	}
	cout << dp[k] << endl;
}	