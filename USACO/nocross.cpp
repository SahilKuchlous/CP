#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
ifstream fin("nocross.in");
ofstream fout("nocross.out");
int main () {
	int n;
	fin >> n;
	int left[n];
	for (int i=0; i<n; i++) {
		fin >> left[i];
	}
	int right[n];
	for (int i=0; i<n; i++) {
		fin >> right[i];
	}
	int dp[n+1][n+1];
	for (int i=0; i<=n; i++) {
		dp[i][0] = dp[0][i] = 0;
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			dp[i][j] = max(dp[i][j-1], dp[i-1][j]);
			if (abs(left[i-1]-right[j-1]) <= 4) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-1]+1);
			}
		}
	}
	fout << dp[n][n] << endl;
}