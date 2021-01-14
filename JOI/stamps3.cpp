#include <iostream>
using namespace std;
#define MAXN 210
int n;
long long l;
long long dist[MAXN];
long long tm[MAXN];
long long dp[MAXN][MAXN][2][MAXN];
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> l;
	for (int i=1; i<=n; i++) {
		cin >> dist[i];
	}
	dist[n+1] = l;
	for (int i=1; i<=n; i++) {
		cin >> tm[i];
	}
	for (int i=0; i<=n+1; i++) {
		for (int j=0; j<=n+1; j++) {
			for (int k=0; k<=n+1; k++) {
				dp[i][j][0][k] = dp[i][j][1][k] = 1e16;
			}
		}
	}
	dp[0][n+1][0][0] = dp[0][n+1][1][0] = 0;
	for (int i=0; i<n; i++) {
		for (int j=n+1; j>i+1; j--) {
			for (int k=0; k<=n; k++) {
				long long d1 = min(dp[i][j][0][k]+dist[i+1]-dist[i], dp[i][j][1][k]+dist[i+1]+l-dist[j]);
				dp[i+1][j][0][k+(d1<=tm[i+1])] = min(dp[i+1][j][0][k+(d1<=tm[i+1])], d1);
				long long d2 = min(dp[i][j][1][k]+dist[j]-dist[j-1], dp[i][j][0][k]+dist[i]+l-dist[j-1]);
				dp[i][j-1][1][k+(d2<=tm[j-1])] = min(dp[i][j-1][1][k+(d2<=tm[j-1])], d2);
			}
		}
	}
	for (int i=0; i<=n+1; i++) {
		for (int j=0; j<=n+1; j++) {
			for (int k=0; k<=n; k++) {
				if (dp[i][j][0][k] < 1e16 || dp[i][j][1][k] < 1e16) {
					o = max(o, k);
				}
 			}
		}
	}
	cout << o << endl;
}