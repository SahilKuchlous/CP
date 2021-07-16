#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000005
int n;
int a[MAXN];
void solve () {
	cin >> n;
	char inp;
	vector<int> ones;
	for (int i=0; i<n; i++) {
		cin >> inp;
		a[i] = inp-'0';
		if (a[i] == 1) {
			ones.push_back(i);
		}
	}
	for (int m=1; m<=n; m++) {
		int dp[n+1];
		dp[0] = 0;
		for (int i=1; i<=n; i++) {
			dp[i] = -1;
		}
		int ptr = 0;
		bool odd = false;
		for (int i=0; i<n; i++) {
			if (a[i] == 1) odd = !odd;
			if (ptr < ones.size() && ones[ptr] == i-m) {
				odd = !odd;
				ptr++;
			}
			if (odd) {
				if (dp[max(0, i-m+1)] == -1) {
					if (ptr+1 < ones.size() && ones[ptr+1]+1 <= n && dp[ones[ptr+1]+1] != -1) {
						dp[i+1] = dp[ones[ptr+1]+1]+1;
					} else {
						dp[i+1] = -1;
					}
				} else {
					dp[i+1] = dp[max(0, i-m+1)]+1;
				}
			} else {
				if (ptr >= ones.size() || ones[ptr]+1 > n || dp[ones[ptr]+1] == -1) {
					dp[i+1] = -1;
				} else {
					dp[i+1] = dp[ones[ptr]+1]+1;
				}
			}
		}
		cout << dp[n] << " ";
	}
	cout << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}
/*
void solve () {
	cin >> n;
	char inp;
	for (int i=0; i<n; i++) {
		cin >> inp;
		a[i] = inp-'0';
	}
	for (int m=1; m<=n; m++) {
		int dp[n+1];
		dp[0] = 0;
		for (int i=0; i<n; i++) {
			int sum = 0;
			dp[i+1] = -1;
			for (int j=i; j>=max(0, i-m+1); j--) {
				sum += a[j];
				if (sum%2 == 1 && dp[j] > -1) {
					dp[i+1] = min(dp[i+1], dp[j]+1);
					if (dp[i+1] == -1) dp[i+1] = dp[j]+1;
				}
			}
		}
		cout << dp[n] << " ";
	}
	cout << endl;
}
*/