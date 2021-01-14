#include <iostream>
using namespace std;
int n, m, k;
bool grid[1100][1100];
int grp[1100][1100];
int size[1000100];
int cnt = 0;
int dfs (int x, int y) {
	grp[x][y] = cnt;
	int total = 0;
	if (!grid[x-1][y]) {
		total++;
	} else if (grp[x-1][y] == -1) {
		total += dfs(x-1, y);
	}
	if (!grid[x+1][y]) {
		total++;
	} else if (grp[x+1][y] == -1) {
		total += dfs(x+1, y);
	}
	if (!grid[x][y-1]) {
		total++;
	} else if (grp[x][y-1] == -1) {
		total += dfs(x, y-1);
	}
	if (!grid[x][y+1]) {
		total++;
	} else if (grp[x][y+1] == -1) {
		total += dfs(x, y+1);
	}
	return total;
}
int main () {
	cin >> n >> m >> k;
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> inp;
			if (inp == '*') {
				grid[i][j] = false;
			} else {
				grid[i][j] = true;
			}
			grp[i][j] = -1;
		}
	}
	int xi, yi;
	for (int i=0; i<k; i++) {
		cin >> xi >> yi;
		xi--;
		yi--;
		if (grp[xi][yi] == -1) {
			size[cnt] = dfs(xi, yi);
			cnt++;
		}
		cout << size[grp[xi][yi]] << endl;
	}
}