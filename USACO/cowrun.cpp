#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("cowrun.in");
ofstream fout("cowrun.out");
int main () {
	int n;
	fin >> n;
	int a[n+1];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	a[n] = 0;
	sort(a, a+n+1);
	int mid = 0;
	for (int i=0; i<n+1; i++) {
		if (a[i] == 0) {
			mid = i;
		}
	}
	long long dp[n+1][n+1];
	for (int i=mid; i>=0; i--) {
		for (int j=mid; j<=n; j++) {
			if (i == j) {
				dp[i][j] = 0;
				continue;
			}
			dp[i][j] = dp[j][i] = 1e14;
			if (j > mid) {
				dp[i][j] = min(dp[i][j], dp[i][j-1]+(a[j]-a[j-1])*(n-j+i+1));
				dp[i][j] = min(dp[i][j], dp[j-1][i]+(a[j]-a[i])*(n-j+i+1));
			}
			if (i < mid) {
				dp[j][i] = min(dp[j][i], dp[j][i+1]+(a[i+1]-a[i])*(n-j+i+1));
				dp[j][i] = min(dp[j][i], dp[i+1][j]+(a[j]-a[i])*(n-j+i+1));
			}
		}
	}
	/*
	for (int i=0; i<=n; i++) {
		for (int j=0; j<=n; j++) {
			cout << i << " " << j << " " << dp[i][j] << endl;
		}
	}
	*/
	fout << min(dp[0][n], dp[n][0]) << endl;
}