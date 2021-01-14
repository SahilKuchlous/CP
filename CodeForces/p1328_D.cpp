#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int type[n];
		for (int i=0; i<n; i++) {
			cin >> type[i];
		}
		bool ez = true;
		for (int i=1; i<n; i++) {
			if (type[i] != type[i-1]) {
				ez = false;
				break;
			}
		}
		if (ez) {
			cout << 1 << endl;
			for (int i=0; i<n; i++) {
				cout << 1 << " ";
			}
			cout << endl;
			continue;
		}
		bool parity = false;
		if (n%2 == 1) parity = true;
		int color[n];
		color[0] = 0;
		for (int i=1; i<n; i++) {
			if (type[i] == type[i-1]) {
				if (parity) {
					color[i] = color[i-1];
					parity = false;
				} else {
					color[i] = (color[i-1]+1)%2;
				}
			} else {
				color[i] = (color[i-1]+1)%2;
			}
		}
		if (parity && type[0] != type[n-1]) {
			color[n-1] = 2;
			cout << 3 << endl;
			for (int i=0; i<n; i++) {
				cout << color[i]+1 << " ";
			}
			cout << endl;
		} else {
			cout << 2 << endl;
			for (int i=0; i<n; i++) {
				cout << color[i]+1 << " ";
			}
			cout << endl;
		}
	}
}