#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n, k;
	cin >> n >> k;
	k--;
	long long a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	long long dp[n];
	for (int i=0; i<=k; i++) {
		dp[i] = 0;
	}
	if (k+1 < n) {
		dp[k+1] = a[k+1];
	}
	for (int i=k+2; i<n; i++) {
		dp[i] = a[i]+max(dp[i-1], dp[i-2]);
	}
	/*
	for (int i=0; i<n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	*/
	if (n > 1) {
		if (k <= n-2) {
			dp[n-2] = max(dp[n-2], dp[n-1]+a[n-2]);
		} else {
			dp[n-2] = dp[n-1]+a[n-2];
		}
	}
	for (int i=n-3; i>=k; i--) {
		dp[i] = max(dp[i], a[i]+max(dp[i+1], dp[i+2]));
	}
	for (int i=k-1; i>=0; i--) {
		if (i+2 < n) {
			dp[i] = a[i]+max(dp[i+1], dp[i+2]);
		}
	}
	/*
	for (int i=0; i<n; i++) {
		cout << dp[i] << " ";
	}
	cout << endl;
	*/
	cout << dp[0] << endl;
}