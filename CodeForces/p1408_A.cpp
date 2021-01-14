#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n], b[n], c[n];
		for (int i=0; i<n; i++) cin >> a[i];
		for (int i=0; i<n; i++) cin >> b[i];
		for (int i=0; i<n; i++) cin >> c[i];
		int o[n];
		o[0] = a[0];
		for (int i=1; i<n-1; i++) {
			if (a[i] != o[i-1]) {
				o[i] = a[i];
			} else {
				o[i] = b[i];
			}
		}
		if (a[n-1] != o[n-2] && a[n-1] != o[0]) o[n-1] = a[n-1];
		if (b[n-1] != o[n-2] && b[n-1] != o[0]) o[n-1] = b[n-1];
		if (c[n-1] != o[n-2] && c[n-1] != o[0]) o[n-1] = c[n-1];
		for (int i=0; i<n; i++) cout << o[i] << " ";
		cout << endl;
	}
}