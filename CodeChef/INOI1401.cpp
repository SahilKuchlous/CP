#include <iostream>
#include <algorithm>
#include <map>
#include <array>
using namespace std;

int a[310][310];
int r, c, d, e;
int b[310][310];
map < array<int, 4>, int> m;

int rec (int x, int y, int dir, int rgt) {
	if (x == r-1 && y == c-1) {
		return 1;
	}
	array<int, 4> id = {x, y, dir, rgt};
	if (m.count(id) != 0) {
		return m[id];
	}
	int o = 0;
	if (x < r-1 && b[x+1][y]) {
		if (!rgt) {
			if (dir < d) {
				o += rec(x+1, y, dir+1, 0);
			}
		} else {
			o += rec(x+1, y, 1, 0);
		}
	}
	if (y < c-1 && b[x][y+1]) {
		if (rgt) {
			if (dir < d) {
				o += rec(x, y+1, dir+1, 1);
			}
		} else {
			o += rec(x, y+1, 1, 1);
		}
	}
	// cout << x << " " << y << " " << o << " " << dir << " " << rgt << endl;
	m[id] = o%20011;
	return o%20011;
}

int main () {
	cin >> r >> c >> d;
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cin >> e;
			if (e == 1) {
				b[i][j] = true;
			} else {
				b[i][j] = false;
			}
			a[i][j] = 0;
		}
	}
	/*
	for (int i=0; i<min(r, d); i++) {
		if (b[i][0]) {
			a[i][0][i][1] = 1;
			a[i][0][d][1] = 1;
		} else {
			break;
		}
	}
	for (int i=0; i<min(c, d); i++) {
		if (b[0][i]) {
			a[0][i][i][0] = 1;
			a[0][i][d][0] = 1;
		} else {
			break;
		}
	}
	for (int i=1; i<r; i++) {
		for (int j=1; j<c; j++) {
			if (b[i][j]) {
				a[i][j][0][0] = a[i][j-1][d][1];
				a[i][j][d][0] += a[i][j-1][d][1];
				a[i][j][0][1] = a[i-1][j][d][0];
				a[i][j][d][1] += a[i-1][j][d][0];
				for (int k=1; k<d; k++) {
					a[i][j][k][0] = a[i][j-1][k-1][0];
					a[i][j][d][0] += a[i][j-1][k-1][0];
					a[i][j][k][1] = a[i-1][j][k-1][1];
					a[i][j][d][1] += a[i-1][j][k-1][1];
					a[i][j][d][0] %= 20011;
					a[i][j][d][1] %= 20011;
				}
			}
		}
	}
	for (int i=0; i<r; i++) {
		for (int j=0; j<c; j++) {
			cout << a[i][j][0][0] << " " << a[i][j][0][1] << "\t";
		}
		cout << endl;
	}
	int s = 0;
	for (int i=0; i<d; i++) {
		s += a[r-1][c-1][i][0];
		s += a[r-1][c-1][i][1];
		s %= 20011;
	}
	cout << s << endl;
	*/
	// cout << endl;
	cout << rec(0, 0, 0, 1) << endl;
}