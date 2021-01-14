#include <iostream>
using namespace std;
int n, m;
bool adj[20][20];
long long dp[(1<<20)][20];
long long o = 0;
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai][bi] = adj[bi][ai] = true;
	}
	for (int i=0; i<(1<<n); i++) {
		for (int j=0; j<n; j++) {
			if ((i & (1<<j)) == 0) {
				dp[i][j] = 0;
				continue;
			}
			int cnt = 0;
			int fst = -1;
			for (int k=0; k<n; k++) {
				if ((i & (1<<k)) == 0) continue;
				cnt++;
				if (fst == -1) fst = k;
				if (adj[j][k]) dp[i][j] += dp[i-(1<<j)][k];
			}
			if (j == fst) dp[i][j] = 0;
			if (cnt == 1) dp[i][j] = 1;
			if (cnt >= 3 && adj[fst][j]) {
				o += dp[i][j];
			}
		}
	}
	cout << o/2 << endl;
}