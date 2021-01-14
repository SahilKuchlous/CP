#include <iostream>
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
		int b[n];
		for (int i=0; i<n; i++) {
			cin >> b[i];
		}
		int dif = 0;
		bool f = false;
		bool o = true;
		for (int i=0; i<n; i++) {
			if (a[i] != b[i]) {
				if (!f) {
					f = true;
					dif = b[i]-a[i];
					if (dif < 0) {
						o = false;
						break;
					}
				} else {
					if (b[i]-a[i] != dif) {
						o = false;
						break;
					}
				}
			} else {
				dif = 0;
			}
		}
		if (o) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}