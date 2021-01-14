#include <iostream>
using namespace std;
bool adj[1000][1000];
int dp[1000][1000][2];
int main () {
	int n, m;
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai][bi] = true;
		adj[bi][ai] = true;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			dp[i][j][0] = dp[i][j][1] = (i==j ? 0:-1);
		}
	}
	pair<int, int> cur = make_pair(-1, -1);
	int side = -1;
	for (int l=1; l<n; l++) {
		for (int i=0; i<n; i++) {
			int j = (i+l)%n;
			if (dp[(i+1)%n][j][0] > -1 && adj[i][(i+1)%n]) dp[i][j][0] = 0;
			if (dp[(i+1)%n][j][1] > -1 && adj[i][j]) dp[i][j][0] = 1;
			if (dp[i][(n+j-1)%n][1] > -1 && adj[j][(n+j-1)%n]) dp[i][j][1] = 1;
			if (dp[i][(n+j-1)%n][0] > -1 && adj[j][i]) dp[i][j][1] = 0;
			if (l == n-1 && dp[i][j][0] > -1) {
				cur = make_pair(i, j);
				side = 0;
			}
			if (l == n-1 && dp[i][j][1] > -1) {
				cur = make_pair(i, j);
				side = 1;
			}
		}
	}
	if (side == -1) {
		cout << -1 << endl;
		return 0;
	}
	while (true) {
		if (cur.first == cur.second) {
			cout << cur.first+1 << endl;
			break;
		}
		if (side == 0) {
			side = dp[cur.first][cur.second][side];
			cout << cur.first+1 << endl;
			cur.first = (cur.first+1)%n;
		} else {
			side = dp[cur.first][cur.second][side];
			cout << cur.second+1 << endl;
			cur.second = (n+cur.second-1)%n;
		}
	}
}