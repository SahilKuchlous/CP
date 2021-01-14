#include <iostream>
using namespace std;
#define MAXN 1000
int n, m, k;
bool grid[MAXN][MAXN];
int cnt = 0;
bool done[MAXN][MAXN];

bool o = false;
void solve () {
	if (cnt > k) return;
	int org_x, org_y, sx, sy;
	bool flag = false;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			if (grid[i][j] && !done[i][j]) {
				org_x = i; org_y = j; flag = true; break;
			}
		}
		if (flag) break;
	}
	if (!flag) {
		o = true;
		return;
	}
	// Maximise h
	int h = n, w = org_y;
	sx = org_x; sy = org_y;
	for (int i=sx; i<n; i++) {
		if (!grid[i][sy]) {
			h = i;
			break;
		}
	}
	while (sy > 0) {
		flag = true;
		for (int i=sx; i<h; i++) {
			if (!grid[i][sy-1]) flag = false;
		}
		if (!flag) break;
		sy--;
	}
	while (w < m-1) {
		flag = true;
		for (int i=sx; i<h; i++) {
			if (!grid[i][w+1]) flag = false;
		}
		if (!flag) break;
		w++;
	}
	w++;
	for (int i=sx; i<h; i++) {
		for (int j=sy; j<w; j++) {
			done[i][j] = true;
		}
	}
	cnt++;
	solve();
	for (int i=sx; i<h; i++) {
		for (int j=sy; j<w; j++) {
			done[i][j] = false;
		}
	}
	cnt--;
	// Maximise w
	h = org_x, w = m;
	sx = org_x; sy = org_y;
	for (int j=sy; j<m; j++) {
		if (!grid[sx][j]) {
			w = j;
			break;
		}
	}
	while (sx > 0) {
		flag = true;
		for (int j=sy; j<w; j++) {
			if (!grid[sx-1][j]) flag = false;
		}
		if (!flag) break;
		sx--;
	}
	while (h < n-1) {
		flag = true;
		for (int j=sy; j<w; j++) {
			if (!grid[h+1][j]) flag = false;
		}
		if (!flag) break;
		h++;
	}
	h++;
	for (int i=sx; i<h; i++) {
		for (int j=sy; j<w; j++) {
			done[i][j] = true;
		}
	}
	cnt++;
	solve();
	for (int i=sx; i<h; i++) {
		for (int j=sy; j<w; j++) {
			done[i][j] = false;
		}
	}
	cnt--;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	char inp;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> inp;
			grid[i][j] = inp-'0';
		}
	}
	solve();
	if (o) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl; 
	}
}