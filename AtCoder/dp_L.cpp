#include <iostream>
using namespace std;
int n;
int a[3100];
long long dp[3100][3100];
bool vis[3100][3100];
long long solve (int s, int e) {
	if (s == e) return a[s];
	if (vis[s][e]) return dp[s][e];
	vis[s][e] = true;
	dp[s][e] = max(a[s]-solve(s+1, e), a[e]-solve(s, e-1));
	return dp[s][e];
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	cout << solve(0, n-1) << endl;
}