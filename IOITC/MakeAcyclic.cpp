#include <iostream>
using namespace std;
#define MAXN 21
int n, m;
int adj[MAXN];
int dp[1<<MAXN];
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai] |= (1<<bi);
	}
	for (int i=1; i<(1<<n); i++) {
		dp[i] = 1e8;
		for (int j=0; j<n; j++) {
			if ((i & (1<<j)) == 0) continue;
			int score = dp[i-(1<<j)];
			int bad = i&adj[j];
			for (int k=0; k<n; k++) {
				if (bad & (1<<k)) score++;
			}
			dp[i] = min(dp[i], score);
		}
	}
	cout << dp[(1<<n)-1] << endl;
}