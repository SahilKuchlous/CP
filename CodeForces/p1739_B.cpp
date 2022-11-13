#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int d[n];
		for (int i=0; i<n; i++) {
			cin >> d[i];
		}
		int a[n];
		a[0] = d[0];
		bool done = false;
		for (int i=1; i<n; i++) {
			if (a[i-1]+d[i] >= 0 && a[i-1]-d[i] >= 0 && a[i-1]+d[i] != a[i-1]-d[i]) {
				cout << -1 << endl;
				done = true;
				break;
			}
			a[i] = max(a[i-1]+d[i], a[i-1]-d[i]);
		}
		if (done) {
			continue;
		}
		for (int i=0; i<n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	}
}