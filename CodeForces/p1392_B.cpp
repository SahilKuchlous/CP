#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		long long k;
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int mx = a[0];
		for (int i=1; i<n; i++) {
			mx = max(mx, a[i]);
		}
		for (int i=0; i<n; i++) {
			a[i] = mx-a[i];
		}
		if (k%2 == 1) {
			for (int i=0; i<n; i++) {
				cout << a[i] << " ";
			}
			cout << endl;
			continue;
		}
		mx = a[0];
		for (int i=1; i<n; i++) {
			mx = max(mx, a[i]);
		}
		for (int i=0; i<n; i++) {
			cout << mx-a[i] << " ";
		}
		cout << endl;
	}
}