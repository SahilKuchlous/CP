#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("team.in");
ofstream fout("team.out");
int main () {
	int n, m, t;
	fin >> n >> m >> t;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	sort(a, a+n);
	int b[m];
	for (int i=0; i<m; i++) {
		fin >> b[i];
	}
	sort(b, b+m);
	long long dp[n+1][m+1][t+1];
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=m; j++) {
			dp[i][j][0] = 1;
		}
	}
	for (int k=1; k<=t; k++) {
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=m; j++) {
				dp[i][j][k] = 0;
			}
		}
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				if (a[i] > b[j]) {
					dp[i+1][j+1][k] = dp[i][j][k-1];
				}
			}
		}
		for (int i=0; i<=n; i++) {
			for (int j=0; j<=m; j++) {
				if (i > 0) dp[i][j][k] += dp[i-1][j][k];
				if (j > 0) dp[i][j][k] += dp[i][j-1][k];
				if (i > 0 && j > 0) dp[i][j][k] -= dp[i-1][j-1][k];
				dp[i][j][k] += 1000000007;
				dp[i][j][k] %= 1000000007;
			}
		}
	}
	fout << dp[n][m][t] << endl;
}