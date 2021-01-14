#include <iostream>
using namespace std;
int n, m, r, s;
int grid[30][30];
int presum[30][30];
int sum (int x1, int y1, int x2, int y2) {
	return presum[x2+1][y2+1]-presum[x2+1][y1]-presum[x1][y2+1]+presum[x1][y1];
}
int divs[30];
int totals[30];
int o;
bool check (int bit, int val) {
	divs[0] = 0;
	int cnt = 1;
	for (int i=0; i<n; i++) {
		if (bit & (1<<i)) {
			divs[cnt] = i+1;
			cnt++;
		}
	}
	divs[cnt] = n;
	for (int i=0; i<r+1; i++) {
		totals[i] = 0;
	}
	cnt = 0;
	for (int i=0; i<m; i++) {
		int top = 0;
		for (int j=0; j<r+1; j++) {
			totals[j] += sum(divs[j], i, divs[j+1]-1, i);
			top = max(top, totals[j]);
		}
		if (top <= val) continue;
		for (int j=0; j<r+1; j++) {
			totals[j] = 0;
		}
		cnt++;
		if (cnt > s) break;
		i--;
	}
	if (cnt > s) return false;
	return true;
}
int main () {
	cin >> n >> m >> r >> s;
	for (int i=0; i<n; i++) {
		for (int j=0; j<m; j++) {
			cin >> grid[i][j];
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			presum[i][j] = grid[i-1][j-1]+presum[i-1][j]+presum[i][j-1]-presum[i-1][j-1];
		}
	}
	o = sum(0, 0, n-1, m-1);
	for (int i=0; i<(1<<(n-1)); i++) {
		int cnt = 0;
		for (int j=0; j<n; j++) {
			if (i & (1<<j)) cnt++;
		}
		if (cnt != r) continue;
		int l = 0, r = 1e9, m, best;
		while (l <= r) {
			m = (l+r)/2;
			if (check(i, m)) {
				best = m;
				r = m-1;
			} else {
				l = m+1;
			}
		}
		o = min(o, best);
	}
	cout << o << endl;
}