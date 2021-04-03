#include <iostream>
using namespace std;
#define MAXN 105
int n;
long long x;
int a[MAXN];
int dp[MAXN][MAXN];
int temp[MAXN][MAXN];
int main () {
	cin >> n >> x;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	for (int i=0; i<n; i++) {
		temp[1][0] = max(temp[1][0], a[i]);
		for (int j=1; j<=n; j++) {
			for (int k=0; k<j; k++) {
				if (dp[j-1][k] > 0) temp[j][(k+a[i])%j] = max(temp[j][(k+a[i])%j], dp[j-1][k]+a[i]);
			}
		}
		for (int j=1; j<=n; j++) {
			for (int k=0; k<j; k++) {
				dp[j][k] = temp[j][k];
			}
		}
	}
	long long o = 1e18;
	for (int j=1; j<=n; j++) {
		if (dp[j][x%j] > 0) o = min(o, (x-dp[j][x%j])/j);
	}
	cout << o << endl;
}