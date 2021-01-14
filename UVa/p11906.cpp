#include <iostream>
#include <set>
using namespace std;
int r, c, m, n;
int wc;
set< pair<int, int> > w;
int cnt[110][110];
void dfs(int row, int col) {
	if (w.find(make_pair(row, col)) != w.end()) {
		return;
	}
	cnt[row][col]++;
	if (cnt[row][col] > 1) {
		return;
	}
	if (row+m < r) {
		if (col+n < c) {
			dfs(row+m, col+n);
		}
		if (col-n >= 0 && n != 0) {
			dfs(row+m, col-n);
		}
	}
	if (row+n < r && m != n) {
		if (col+m < c) {
			dfs(row+n, col+m);
		}
		if (col-m >= 0 && m != 0) {
			dfs(row+n, col-m);
		}
	}
	if (row-m >= 0 && m != 0) {
		if (col+n < c) {
			dfs(row-m, col+n);
		}
		if (col-n >= 0 && n != 0) {
			dfs(row-m, col-n);
		}
	}
	if (row-n >= 0 && n != 0 && m != n) {
		if (col+m < c) {
			dfs(row-n, col+m);
		}
		if (col-m >= 0 && m != 0) {
			dfs(row-n, col-m);
		}
	}
}
int main () {
	int t;
	cin >> t;
	for (int x=1; x<=t; x++) {
		cin >> r >> c >> m >> n;
		cin >> wc;
		int in1, in2;
		w.clear();
		for (int i=0; i<wc; i++) {
			cin >> in1 >> in2;
			w.insert(make_pair(in1, in2));
		}
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				cnt[i][j] = 0;
			}
		}
		dfs(0, 0);
		cnt[0][0]--;
		int o1 = 0, o2 = 0;
		for (int i=0; i<r; i++) {
			for (int j=0; j<c; j++) {
				if (cnt[i][j]%2 == 1) {
					o2++;
				} else if (cnt[i][j] > 0 || (i==0 && j==0)) {
					o1++;
				}
			}
		}
		cout << "Case " << x << ": " << o1 << " " << o2 << endl;
	}
}