#include <iostream>
using namespace std;
#define MAXN 3005
int h, w;
char grid[MAXN][MAXN];
int row[MAXN][MAXN];
int col[MAXN][MAXN];
long long o = 0;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> h >> w;
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			row[i][j] = row[i][j-1];
			if (grid[i][j] == 'O') row[i][j]++;
			col[i][j] = col[i-1][j];
			if (grid[i][j] == 'I') col[i][j]++;
		}
	}
	for (int i=1; i<=h; i++) {
		for (int j=1; j<=w; j++) {
			if (grid[i][j] == 'J') o += (row[i][w]-row[i][j])*(col[h][j]-col[i][j]);
		}
	}
	cout << o << endl;
}