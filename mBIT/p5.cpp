#include <iostream>
using namespace std;
#define MAXN 1005
long long n, k;
long long a[MAXN];
long long b[MAXN];
long long dp[MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> k;
	for (int i=1; i<=n; i++) {
		cin >> a[i];
		b[i] = k-a[i]+1;
	}
	for (int i=1; i<=n; i++) {
		dp[i] = dp[i-1]+min(a[i], b[i]);
		long long cost = a[i];
		for (int j=i-1; j>0; j--) {
			if (a[j] > a[j+1]) {
				cost += a[j]-a[j+1];
			}
			dp[i] = min(dp[i], dp[j-1]+cost);
		}
		cost = b[i];
		for (int j=i-1; j>0; j--) {
			if (b[j] > b[j+1]) {
				cost += b[j]-b[j+1];
			}
			dp[i] = min(dp[i], dp[j-1]+cost);
		}
		cout << dp[i] << endl;
	}
	cout << dp[n] << endl;
}