#include <iostream>
#include <algorithm>
using namespace std;
long long k;
int m, n;
long long presum[2010][2010];
int o;
int dp[2010][2010];
long long hori (int x, int y1, int y2) {
	return presum[x][y2]-presum[x][y1-1]-presum[x-1][y2]+presum[x-1][y1-1];
}
long long vert (int x1, int x2, int y) {
	return presum[x2][y]-presum[x1-1][y]-presum[x2][y-1]+presum[x1-1][y-1];
}
int calc (int x1, int y1, int x2, int y2) {
	if (x1 > x2) return 0;
	if (dp[y1][y2] > 0) return dp[y1][y2];
	if (hori(x1, y1, y2) <= k) return dp[y1][y2] = calc(x1+1, y1, x2, y2);
	if (hori(x2, y1, y2) <= k) return dp[y1][y2] = calc(x1, y1, x2-1, y2);
	dp[y1][y2] = 1e8;
	if (vert(x1, x2, y1) <= k) dp[y1][y2] = min(dp[y1][y2], calc(x1, y1+1, x2, y2)+1);
	if (vert(x1, x2, y2) <= k) dp[y1][y2] = min(dp[y1][y2], calc(x1, y1, x2, y2-1)+1);
	return dp[y1][y2];
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> k >> m >> n;
	int ai;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			cin >> ai;
			presum[i][j] = ai+presum[i][j-1]+presum[i-1][j]-presum[i-1][j-1];
		}
	}
	o = m+n-1;
	o = min(o, calc(1, 1, n, m)+n);
	for (int i=0; i<=max(n, m); i++) {
		for (int j=0; j<=max(n, m); j++) {
			dp[i][j] = 0;
		}
	}
	for (int i=0; i<=max(n, m); i++) {
		for (int j=0; j<i; j++) {
			swap(presum[i][j], presum[j][i]);
		}
	}
	o = min(o, calc(1, 1, m, n)+m);
	cout << o << endl;
}