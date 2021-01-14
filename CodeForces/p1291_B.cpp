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
		bool ans = true;
		int x = n, y = -1;
		for (int i=0; i<n; i++) {
			if (a[i] < i) {
				x = i;
				break;
			}
		}
		for (int i=n-1; i>=0; i--) {
			if (a[i] < n-i-1) {
				y = i;
				break;
			}
		}
		// cout << y << " " << x << endl;
		if (y < x-1) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}