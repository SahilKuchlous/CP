#include <iostream>
#include <fstream>
using namespace std;
ifstream fin("248.in");
ofstream fout("248.out");
int main () {
	int n;
	fin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		fin >> a[i];
	}
	int o = 0;
	int dp[n][n];
	for (int i=0; i<n; i++) {
		dp[i][i] = a[i];
		o = max(o, dp[i][i]);
	}
	for (int l=1; l<n; l++) {
		for (int s=0; s<n-l; s++) {
			dp[s][s+l] = -1;
			for (int m=s; m<s+l; m++) {
				if (dp[s][m] == dp[m+1][s+l]) {
					dp[s][s+l] = max(dp[s][s+l], dp[s][m]+1);
					o = max(o, dp[s][s+l]);
				}
			}
		}
	}
	fout << o << endl;
}