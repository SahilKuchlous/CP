#include <iostream>
using namespace std;
int n;
int grid[100][100];
long long memo[100][100];
long long rec (int x, int y) {
	if (x >= n || y >= n) return 0;
	if (memo[x][y] != -1) return memo[x][y];
	if (grid[x][y] == 0) return 0;
	memo[x][y] = rec(x+grid[x][y], y)+rec(x, y+grid[x][y]);
	return memo[x][y];
}
int main () {
	cin >> n;
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			cin >> grid[i][j];
			memo[i][j] = -1;
		}
	}
	memo[n-1][n-1] = 1;
	cout << rec(0, 0) << endl;
}