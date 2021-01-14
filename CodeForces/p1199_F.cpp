#include <iostream>
using namespace std;
int dp[51][51][51][51];
int main () {
	int n;
	cin >> n;
	char grid[n][n];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> grid[i][j];
			dp[i][j][i+1][j+1] = (grid[i][j]=='#'?1:0);
		}
	}
	for (int xl=1; xl<=n; xl++) {
		for (int yl=1; yl<=n; yl++) {
			for (int x=0; x<=n-xl; x++) {
				for (int y=0; y<=n-yl; y++) {
					if (xl == 1 && yl == 1) {
						dp[x][y][x+1][y+1] = (grid[x][y]=='#'?1:0);
						continue;
					}
					dp[x][y][x+xl][y+yl] = max(xl, yl);
					for (int i=x+1; i<x+xl; i++) {
						dp[x][y][x+xl][y+yl] = min(dp[x][y][x+xl][y+yl], dp[x][y][i][y+yl]+dp[i][y][x+xl][y+yl]);
					}
					for (int i=y+1; i<y+yl; i++) {
						dp[x][y][x+xl][y+yl] = min(dp[x][y][x+xl][y+yl], dp[x][y][x+xl][i]+dp[x][i][x+xl][y+yl]);
					}
				}
			}
		}
	}
	cout << dp[0][0][n][n] << endl;
}