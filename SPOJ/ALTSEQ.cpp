#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	cin.tie(NULL);
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int b[n][n][2];
	for (int i=0; i<n; i++) {
		for (int j=0; j<n; j++) {
			b[i][j][0] = 1e9 + 1;
			b[i][j][1] = 1e9 + 1;
		}
	}
	if (a[0] > 0) {
		b[0][0][0] = abs(a[0]);
	} else {
		b[0][0][1] = abs(a[0]);
	}
	for (int i=1; i<n; i++) {
		if (a[i] > 0) {
			if (a[i] < b[i-1][0][0]) {
				b[i][0][0] = a[i];
			} else {
				b[i][0][0] = b[i-1][0][0];
			}
			b[i][0][1] = b[i-1][0][1];
		} else {
			if (abs(a[i]) < b[i-1][0][1]) {
				b[i][0][1] = abs(a[i]);
			} else {
				b[i][0][1] = b[i-1][0][1];
			}
			b[i][0][0] = b[i-1][0][0];
		}
		for (int j=1; j<=i; j++) {
			if (a[i] > 0) {
				if (b[i-1][j-1][1] < a[i] && a[i] < b[i-1][j][0]) {
					b[i][j][0] = a[i];
				} else {
					b[i][j][0] = b[i-1][j][0];
				}
				b[i][j][1] = b[i-1][j][1];
			} else {
				if (b[i-1][j-1][0] < abs(a[i]) && abs(a[i]) < b[i-1][j][1]) {
					b[i][j][1] = abs(a[i]);
				} else {
					b[i][j][1] = b[i-1][j][1];
				}
				b[i][j][0] = b[i-1][j][0];
			}
		}
	}
	int c;
	for (c=0; c<n; c++) {
		if (b[n-1][c][0] == 1e9 + 1 && b[n-1][c][1] == 1e9 + 1) {
			break;
		}
	}
	cout << c << endl;
}