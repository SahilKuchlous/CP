#include <iostream>
using namespace std;
#define MAXN 20
int n;
bool adj[MAXN][MAXN];
int dp[1000005];
int main () {
	cin >> n;
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> inp;
			adj[i][j] = (inp == 'Y');
		}
	}
	for (int i=0; i<(1<<n); i++) {
		bool vis[n];
		for (int i=0; i<n; i++) {
			vis[i] = false;
		}
		for (int j=0; j<n; j++) {
			if (i&(1<<j)) {
				vis[j] = 1;
				for (int k=0; k<n; k++) {
					if (adj[j][k]) vis[k] = true;
				}
			}
		}
		bool full = true;
		for (int i=0; i<n; i++) {
			if (!vis[i]) full = false;
		}
		if (full) {
			dp[i] = 1;
		}
	}
	for (int i=0; i<(1<<n); i++) {
		if (dp[i] == 0) continue;
		for (int j=i; j>0; j=(j-1)&i) {
			if (dp[j] == 0 && dp[i-j] == 0) continue;
			dp[i] = max(dp[i], dp[j]+dp[i-j]);
		}
	}
	cout << dp[(1<<n)-1] << endl;
}