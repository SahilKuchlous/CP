#include <iostream>
using namespace std;
int a[550], b[550];
bool dp[550][550];
int main () {
	int n, k;
	cin >> n >> k;
	long long sum_a = 0, sum_b = 0;
	for (int i=1; i<=n; i++) {
		cin >> a[i] >> b[i];
		sum_a += a[i];
		sum_b += b[i];
	}
	dp[0][0] = true;
	for (int i=1; i<=n; i++) {
		for (int j=0; j<k; j++) {
			dp[i][j] = dp[i-1][(j+k-a[i]%k)%k];
			for (int l=0; l<=min(a[i], k-1); l++) {
				if ((a[i]-l)%k+b[i] >= k) {
					dp[i][j] |= dp[i-1][(j-l+k)%k];
				}
			}
		}
	}
	long long o = 0;
	for (int i=0; i<k; i++) {
		if (dp[n][i]) o = max(o, (sum_a+sum_b-i)/k);
	}
	cout << o << endl;
}