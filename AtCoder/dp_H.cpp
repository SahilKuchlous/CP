#include <iostream>
using namespace std;
#define MOD 1000000007
int h, w;
char grid[1100][1100];
long long dp[1100][1100];
int main () {
	cin >> h >> w;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			cin >> grid[i][j];
		}
	}
	dp[1][1] = 1;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			if (i == 1 && j == 1) continue;
			if (grid[i][j] == '.') dp[i][j] = (dp[i-1][j]+dp[i][j-1])%MOD;
		}
	}
	cout << dp[h][w] << endl;
}