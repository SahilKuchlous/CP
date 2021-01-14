#include <iostream>
using namespace std;
#define MAXN 2005
int n, m;
int grid[MAXN][MAXN];
int min_v = 1e9, max_v = -1;
bool check (int x) {
	int pos = m;
	int cur = max_v;
	for (int i=0; i<n; i++) {
		for (int j=0; j<pos; j++) {
			if (grid[i][j]-min_v > x) {
				pos = j;
				break;
			}
		}
		for (int j=pos; j<m; j++) {
			cur = min(cur, grid[i][j]);
		}
	}
	if (max_v-cur <= x) return true;
	pos = m;
	cur = max_v;
	for (int i=n-1; i>=0; i--) {
		for (int j=0; j<pos; j++) {
			if (grid[i][j]-min_v > x) {
				pos = j;
				break;
			}
		}
		for (int j=pos; j<m; j++) {
			cur = min(cur, grid[i][j]);
		}
	}
	if (max_v-cur <= x) return true;
	pos = -1;
	cur = max_v;
	for (int i=0; i<n; i++) {
		for (int j=m-1; j>pos; j--) {
			if (grid[i][j]-min_v > x) {
				pos = j;
				break;
			}
		}
		for (int j=pos; j>=0; j--) {
			cur = min(cur, grid[i][j]);
		}
	}
	if (max_v-cur <= x) return true;
	pos = -1;
	cur = max_v;
	for (int i=n-1; i>=0; i--) {
		for (int j=m-1; j>pos; j--) {
			if (grid[i][j]-min_v > x) {
				pos = j;
				break;
			}
		}
		for (int j=pos; j>=0; j--) {
			cur = min(cur, grid[i][j]);
		}
	}
	if (max_v-cur <= x) return true;
	return false;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
			min_v = min(min_v, grid[i][j]);
			max_v = max(max_v, grid[i][j]);
		}
	}
	int l = 0, r = 1e9, m, o;
	while (l <= r) {
		m = (l+r)/2;
		if (check(m)) {
			r = m-1; o = m;
		} else {
			l = m+1;
		}
	}
	cout << o << endl;
}