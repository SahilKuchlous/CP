#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int dp[n+1];
	dp[0] = 0;
	dp[1] = 1;
	for (int i=1; i<n; i++) {
		dp[i+1] = 301;
		for (int j=0; j<=i; j++) {
			bool pal = true;
			for (int k=0; k<=i-j; k++) {
				if (a[j+k] != a[i-k]) {
					pal = false;
					break;
				}
			}
			if (pal) {
				dp[i+1] = min(dp[i+1], dp[j]+1);
			}
		}
	}
	cout << dp[n] << endl;
}