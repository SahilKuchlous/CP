#include <iostream>
using namespace std;
int n, m;
bool grid[1010][1010];
bool rows[1010], cols[1010];
bool empt_r[1010], empt_c[1010];
int cnt = 0;
bool vis[1010][1010];
void dfs (int x, int y) {
	if (x < 0 || x > n-1 || y < 0 || y > m-1) return;
	if (vis[x][y] || !grid[x][y]) return;
	vis[x][y] = true;
	dfs(x-1, y);
	dfs(x+1, y);
	dfs(x, y-1);
	dfs(x, y+1);
}
int main () {
	cin >> n >> m;
	char ai;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> ai;
			grid[i][j] = (ai=='#' ? true:false);
		}
	}
	bool pos = true;
	bool black, white;
	for (int i=0; i<n; i++) {
		black = white = false;
		for (int j=0; j<m; j++) {
			if (grid[i][j]) {
				if (!white) {
					black = true;
				} else {
					pos = false;
				}
			} else {
				if (black) white = true;
			}
		}
		if (black) {
			rows[i] = true;
		} else {
			empt_r[i] = true;
		}
	}
	for (int j=0; j<m; j++) {
		black = white = false;
		for (int i=0; i<n; i++) {
			if (grid[i][j]) {
				if (!white) {
					black = true;
				} else {
					pos = false;
				}
			} else {
				if (black) white = true;
			}
		}
		if (black) {
			cols[j] = true;
		} else {
			empt_c[j] = true;
		}
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (empt_r[i] && empt_c[j]) {
				rows[i] = cols[j] = true;
			}
		}
	}
	for (int i=0; i<n; i++) {
		if (!rows[i]) pos = false;
	}
	for (int j=0; j<m; j++) {
		if (!cols[j]) pos = false;
	}
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] && !vis[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}
	cout << (pos ? cnt:-1) << endl;
}