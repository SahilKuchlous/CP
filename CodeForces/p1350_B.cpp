#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n+1];
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}
		int dp[n+1];
		for (int i=1; i<=n; i++) {
			dp[i] = 1;
		}
		for (int i=1; i<=n; i++) {
			for (int j=2*i; j<=n; j+=i) {
				if (a[j] > a[i]) dp[j] = max(dp[j], dp[i]+1);
			}
		}
		int o = 1;
		for (int i=1; i<=n; i++) {
			o = max(o, dp[i]);
		}
		cout << o << endl;
	}
}