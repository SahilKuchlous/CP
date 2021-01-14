#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int m;
		cin >> m;
		int e[n];
		for (int i=0; i<n; i++) {
			e[i] = -1;
		}
		int x, y;
		for (int i=0; i<m; i++) {
			cin >> x >> y;
			y--;
			e[y] = max(e[y], x);
		}
		for (int i=n-1; i>0; i--) {
			e[i-1] = max(e[i-1], e[i]);
		}
		int t = 1;
		int maxs = 0;
		bool p = true;
		int d = -1;
		for (int i=0; i<n; i++) {
			maxs = max(a[i], maxs);
			d++;
			if (maxs > e[d]) {
				if (d == 0) {
					p = false;
					break;
				}
				t++;
				d = -1;
				maxs = 0;
				i--;
			}
		}
		if (p) {
			cout << t << endl;
		} else {
			cout << -1 << endl;
		}
	}
}