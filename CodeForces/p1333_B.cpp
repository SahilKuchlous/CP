#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		bool pos[n];
		bool neg[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i] == 1 || (i > 0 && pos[i-1])) {
				pos[i] = true;
			} else {
				pos[i] = false;
			}
			if (a[i] == -1 || (i > 0 && neg[i-1])) {
				neg[i] = true;
			} else {
				neg[i] = false;
			}
		}
		int b[n];
		for (int i=0; i<n; i++) {
			cin >> b[i];
		}
		bool o = true;
		if (a[0] != b[0]) o = false;
		for (int i=1; i<n; i++) {
			if (a[i] > b[i] && !neg[i-1]) o = false;
			if (a[i] < b[i] && !pos[i-1]) o = false;
		}
		if (o) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}