#include <iostream>
using namespace std;
#define MAXN 3005
int n, m;
char grid[MAXN][MAXN];
bool l[MAXN][MAXN], u[MAXN][MAXN];
int dp[MAXN][3];
int o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] != 'G') continue;
			if (i > 0 && i < n-1 && grid[i-1][j] == 'R' && grid[i+1][j] == 'W') u[i][j] = true;
			if (j > 0 && j < m-1 && grid[i][j-1] == 'R' && grid[i][j+1] == 'W') l[i][j] = true;
		}
	}
	for (int i=0; i<m; i++) {
		int x = 0, y = i;
		int dist = min(i, n-1);
		dp[0][0] = 0;
		dp[0][1] = l[x][y];
		dp[0][2] = u[x][y];
		x++; y--;
		for (int j=1; j<=dist; j++) {
			dp[j][0] = max(dp[j-1][0], max(dp[j-1][1], dp[j-1][2]));
			dp[j][1] = max(dp[j-1][0], dp[j-1][1])+l[x][y];
			dp[j][2] = max(dp[j-1][0], dp[j-1][2])+u[x][y];
			x++; y--;
		}
		o += max(dp[dist][0], max(dp[dist][1], dp[dist][2]));
	}
	for (int i=n-2; i>=0; i--) {
		int x=n-i-1, y = m-1;
		int dist = min(i, m-1);
		dp[0][0] = 0;
		dp[0][1] = l[x][y];
		dp[0][2] = u[x][y];
		x++; y--;
		for (int j=1; j<=dist; j++) {
			dp[j][0] = max(dp[j-1][0], max(dp[j-1][1], dp[j-1][2]));
			dp[j][1] = max(dp[j-1][0], dp[j-1][1])+l[x][y];
			dp[j][2] = max(dp[j-1][0], dp[j-1][2])+u[x][y];
			x++; y--;
		}
		o += max(dp[dist][0], max(dp[dist][1], dp[dist][2]));
	}
	cout << o << endl;
}