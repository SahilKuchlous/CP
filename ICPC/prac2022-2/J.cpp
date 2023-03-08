#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAXN 205
vector<int> times;
int dp[2*MAXN][MAXN];

int main () {
	int t;
	cin >> t;
	while (t--) {
		times.clear();

		int n;
		cin >> n;
		int inp;
		for (int i=0; i<n; i++) {
			cin >> inp;
			times.push_back(inp);
		}
		sort(times.begin(), times.end());

		int ans = 10000005;
		for (int i=1; i<=2*n; i++) {
			for (int j=0; j<min(i, n+1); j++) {
				dp[i][j] = min(dp[i-1][j], dp[i-1][j-1]+abs(times[j-1]-i));
			}
			if (i <= n) {
				dp[i][i] = dp[i-1][i-1]+abs(times[i-1]-i);
			}
			if (i >= n) {
				ans = min(ans, dp[i][n]);
			}
		}
		cout << ans << endl;
	}
}