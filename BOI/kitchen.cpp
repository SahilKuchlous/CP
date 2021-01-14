#include <iostream>
#include <algorithm>
using namespace std;
int n, m, k;
int req[310];
int pow[310];
int ttl = 0;
int main () {
	cin >> n >> m >> k;
	if (m < k) {
		cout << "Impossible" << endl;
		return 0;
	}
	for (int i=0; i<n; i++) {
		cin >> req[i];
		ttl += req[i];
		if (req[i] < k) {
			cout << "Impossible" << endl;
			return 0;
		}
	}
	for (int i=0; i<m; i++) {
		cin >> pow[i];
	}
	sort(pow, pow+m);
	int dp[100000];
	for (int i=0; i<100000; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;
	for (int i=0; i<m; i++) {
		for (int j=99999; j>=0; j--) {
			if (dp[j] > -1 && dp[j+pow[i]] == -1) dp[j+pow[i]] = dp[j]+min(n, pow[i]);
		}
	}
	for (int i=ttl; i<100000; i++) {
		if (dp[i] >= n*k) {
			cout << i-ttl << endl;
			return 0;
		}
	}
	cout << "Impossible" << endl;
}