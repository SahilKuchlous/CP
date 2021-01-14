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
		int ec = 0, oc = 0;
		for (int i=0; i<n; i++) {
			if (i%2 == 0 && a[i]%2 == 1) ec++;
			if (i%2 == 1 && a[i]%2 == 0) oc++;
		}
		if (ec != oc) {
			cout << -1 << endl;
		} else {
			cout << ec << endl;
		}
	}
}