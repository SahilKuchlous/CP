#include "grader.h"
using namespace std;
int up[3001][3001], down[3001][3001];
int sum (int x, int y, int t, int r, int c) {
	int o = (t==0 ? up[x+r][y+c]:down[x+r][y+c]);
	o -= (t==0 ? up[x][y+c]:down[x][y+c]);
	o -= (t==0 ? up[x+r][y]:down[x+r][y]);
	o += (t==0 ? up[x][y]:down[x][y]);
	return o;
}
bool check (int x, int n, int m, int r, int c, int grid[3001][3001]) {
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] > x) {
				up[i+1][j+1] = 1;
			} else {
				up[i+1][j+1] = 0;
			}
			up[i+1][j+1] += up[i][j+1];
			up[i+1][j+1] += up[i+1][j];
			up[i+1][j+1] -= up[i][j];
			if (grid[i][j] < x) {
				down[i+1][j+1] = 1;
			} else {
				down[i+1][j+1] = 0;
			}
			down[i+1][j+1] += down[i][j+1];
			down[i+1][j+1] += down[i+1][j];
			down[i+1][j+1] -= down[i][j];
		}
	}
	for (int i=0; i<=n-r; i++) {
		for (int j=0; j<=m-c; j++) {
			int cnt1 = sum(i, j, 0, r, c);
			int cnt2 = sum(i, j, 1, r, c);
			if (cnt1 <= cnt2) return true;
		}
	}
	return false;
}
int rectangle (int n, int m, int r, int c, int grid[3001][3001]) {
	int left = 1, right = n*m, mid;
	int o = n*m;
	while (left <= right) {
		mid = (left+right)/2;
		if (check(mid, n, m, r, c, grid)) {
			o = mid;
			right = mid-1;
		} else {
			left = mid+1;
		}
	}
	return o;
}