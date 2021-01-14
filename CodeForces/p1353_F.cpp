#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m;
long long grid[100][100];
long long dp[100][100];
long long vis[100][100];
void solve (int x, int y, long long h) {
	if (vis[x][y] == h) return;
	vis[x][y] = h;
	if (grid[x][y] < h) {
		dp[x][y] = 1e18;
		return;
	}
	if (x == n-1 && y == m-1) {
		dp[x][y] = grid[x][y]-h;
		return;
	}
	dp[x][y] = 1e18;
	if (x < n-1) {
		solve(x+1, y, h);
		dp[x][y] = min(dp[x][y], dp[x+1][y]);
	}
	if (y < m-1) {
		solve(x, y+1, h);
		dp[x][y] = min(dp[x][y], dp[x][y+1]);
	}
	if (dp[x][y] < 1e18) dp[x][y] += grid[x][y]-h;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		vector<long long> heights;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> grid[i][j];
				grid[i][j] -= i+j;
				heights.push_back(grid[i][j]);
				vis[i][j] = 1e18;
			}
		}
		sort(heights.begin(), heights.end());
		heights.resize(unique(heights.begin(), heights.end())-heights.begin());
		long long o = 1e18;
		for (auto h: heights) {
			solve(0, 0, h);
			o = min(o, dp[0][0]);
		}
		cout << o << endl;
	}
}