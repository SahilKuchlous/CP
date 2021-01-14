#include <iostream>
using namespace std;
int main () {
	int q;
	cin >> q;
	while (q--) {
		int h, n;
		cin >> h >> n;
		int a[h];
		for (int i=0; i<h; i++) {
			a[i] = 0;
		}
		int p;
		for (int i=0; i<n; i++) {
			cin >> p;
			a[p-1] = 1;
		}
		a[h-1] = 0;
		/*
		for (int i=0; i<h; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
		*/
		int x = 0;
		for (int i=0; i<n; i++) {
			if (a[i] == 1) {
				x++;
			} else {
				break;
			}
		}
		int c = 0;
		bool f = false;
		int s = 0;
		for (int i=x; i<h; i++) {
			if (a[i] == 1) {
				if (f) {
					s++;
				} else {
					f = true;
					s = 1;
				}
			} else {
				if (f) {
					f = false;
					if (s%2 == 1) {
						c++;
					}
				}
			}
		}
		cout << c << endl;
	}
}