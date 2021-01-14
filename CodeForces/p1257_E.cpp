#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int k1, k2, k3;
	cin >> k1 >> k2 >> k3;
	int n = k1+k2+k3;
	int a[n];
	int x;
	for (int i=0; i<k1; i++) {
		cin >> x;
		a[x-1] = 0; 
	}
	for (int i=0; i<k2; i++) {
		cin >> x;
		a[x-1] = 1; 
	}
	for (int i=0; i<k3; i++) {
		cin >> x;
		a[x-1] = 2; 
	}
	int dp[n+1][3];
	dp[0][0] = 0;
	dp[0][1] = 0;
	dp[0][2] = 0;
	for (int i=1; i<=n; i++) {
		dp[i][0] = dp[i-1][0];
		if (a[i-1] != 0) {
			dp[i][0]++;
		}
		dp[i][1] = min(dp[i-1][0], dp[i-1][1]);
		if (a[i-1] != 1) {
			dp[i][1]++;
		}
		dp[i][2] = min(dp[i-1][0], min(dp[i-1][1], dp[i-1][2]));
		if (a[i-1] != 2) {
			dp[i][2]++;
		}
	}
	/*
	cout << endl;
	for (int i=0; i<=n; i++) {
		cout << dp[i][0] << " " << dp[i][1] << " " << dp[i][2] << endl;
	}
	cout << endl;
	*/
	cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << endl;
}