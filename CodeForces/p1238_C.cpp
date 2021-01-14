#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int q;
	cin >> q;
	while (q--) {
		int h, n;
		cin >> h >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[n-i-1];
		}
		a[n-1] = -1;
		int x = 0;
		if (a[0] == 1) {
			x = 1;
			for (int i=1; i<n; i++) {
				if (a[i]-a[i-1] == 1) {
					x++;
				} else {
					break;
				}
			}
		}
		int o = 0;
		int c = 1;
		for (int i=x+1; i<n; i++) {
			if (a[i]-a[i-1] == 1) {
				c++;
			} else {
				// cout << c << endl;
				if (c%2 == 1) {
					o++;
				}
				c = 1;
			}
		}
		cout << o << endl;
	}
}