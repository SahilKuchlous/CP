#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
ifstream fin("snakes.in");
ofstream fout("snakes.out");
int main () {
	int n, k;
	fin >> n >> k;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	long long pfx[n];
	pfx[0] = a[0];
	for (int i=1; i<n; i++) {
		pfx[i] = pfx[i-1]+a[i];
	}
	long long dp[n][k+1];
	for (int i=0; i<n; i++) {
		for (int j=0; j<=k; j++) {
			dp[i][j] = 1e11;
		}
	}
	for (int i=0; i<=k; i++) {
		dp[0][i] = 0;
	}
	int m;
	int x = 0;
	for (int i=1; i<n; i++) {
		x = max(a[i], x);
		dp[i][0] = x*(i+1)-pfx[i];
		m = a[i];
		for (int l=i-1; l>=0; l--) {
			for (int j=1; j<=k; j++) {
				dp[i][j] = min(dp[i][j], dp[l][j-1]+m*(i-l)-pfx[i]+pfx[l]);
			}
			m = max(m, a[l]);
		}
	}
	/*
	for (int i=0; i<=k; i++) {
		for (int j=0; j<n; j++) {
			cout << dp[j][i] << " ";
		}
		cout << endl;
	}
	*/
	fout << dp[n-1][k] << endl;
} 