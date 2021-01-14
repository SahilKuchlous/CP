#include <iostream>
#include <climits>
using namespace std;
int main () {
	int c, f, x, y, p;
	cin >> c >> f;
	unsigned int a[c][c];
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			if (i != j) {
				a[i][j] = INT_MAX;
			} else {
				a[i][j] = 0;
			}
		}
	}
	for (int i=0; i<f; i++) {
		cin >> x >> y >> p;
		x--;
		y--;
		a[x][y] = p;
		a[y][x] = p;
	}
	unsigned int d[c][c];
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			d[i][j] = a[i][j];
		}
	}
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			for (int k=0; k<c; k++) {
				if (d[j][k] > d[i][k] + d[i][j]) {
					d[j][k] = d[i][k] + d[i][j];
				}
			}
		}
	}
	/*
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	*/
	unsigned int m = 0;
	for (int i=0; i<c; i++) {
		for (int j=0; j<c; j++) {
			if (d[i][j] > m && d[i][j] != INT_MAX) {
				m = d[i][j];
			}
		}
	}
	cout << m << endl;
	return 0;
}