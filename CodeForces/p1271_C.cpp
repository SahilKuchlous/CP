#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n, sx, sy;
	cin >> n >> sx >> sy;
	int u = 0, d = 0, r = 0, l = 0;
	int x, y;
	for (int i=0; i<n; i++) {
		cin >> x >> y;
		if (x < sx) {
			l++;
		}
		if (x > sx) {
			r++;
		}
		if (y > sy) {
			u++;
		}
		if (y < sy) {
			d++;
		}
	}
	int m = max(r, max(l, max(u, d)));
	cout << m << endl;
	if (m == l) {
		cout << sx-1 << " " << sy << endl;
	} else if (m == r) {
		cout << sx+1 << " " << sy << endl;
	} else if (m == u) {
		cout << sx << " " << sy+1 << endl;
	} else {
		cout << sx << " " << sy-1 << endl;
	}
}