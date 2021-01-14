#include <iostream>
using namespace std;
int n;
long long a[410];
long long dp[410][410];
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int sz=1; sz<n; sz++) {
		for (int i=0; i<n-sz; i++) {
			dp[i][i+sz] = 1e16;
			for (int j=i; j<i+sz; j++) {
				dp[i][i+sz] = min(dp[i][i+sz], dp[i][j]+dp[j+1][i+sz]);
			}
			for (int j=i; j<=i+sz; j++) {
				dp[i][i+sz] += a[j];
			}
		}
	}
	cout << dp[0][n-1] << endl;
}