#include <iostream>
#include <algorithm>
using namespace std;
int n, t;
int a[210];
int m[210][210][210];

int rec (int b, int w, int i) {
	if (i == n-1) {
		if (a[i] > a[b] || a[i] < a[w]) {
			return 1;
		} else {
			return 0;
		}
	}
	if (m[b][w][i] != -1) {
		return m[b][w][i];
	}
	int o = 0;
	int t;
	if (a[i] > a[b]) {
		o = rec(i, w, i+1)+1;
	}
	if (a[i] < a[w]) {
		t = rec(b, i, i+1)+1;
		if (t > o) {
			o = t;
		}
	}
	t = rec(b, w, i+1);
	if (t > o) {
		o = t;
	}
	m[b][w][i] = o;
	return o;
}

int main () {
	cin >> t;
	for (int z=0; z<t; z++) {
		cin >> n;
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		a[n] = 0;
		a[n+1] = 1000001;
		for (int i=0; i<210; i++) {
			for (int j=0; j<210; j++) {
				for (int k=0; k<210; k++) {
					m[i][j][k] = -1;
				}
			}
		}
		cout << max(rec(0, n+1, 1)+1, max(rec(n, 0, 1)+1, rec(n, n+1, 1))) << endl;
	}
}