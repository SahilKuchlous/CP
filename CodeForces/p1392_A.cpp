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
		bool bad = true;
		for (int i=1; i<n; i++) {
			if (a[i] != a[0]) bad = false;
		}
		if (bad) {
			cout << n << endl;
		} else {
			cout << 1 << endl;
		}
	}
}