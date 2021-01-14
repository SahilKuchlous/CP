#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n], b[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		for (int i=0; i<n; i++) {
			cin >> b[i];
		}
		for (int i=0; i<k; i++) {
			sort(a, a+n);
			sort(b, b+n);
			if (a[0] < b[n-1]) {
				swap(a[0], b[n-1]);
			}
		}
		int o = 0;
		for (int i=0; i<n; i++) {
			o += a[i];
		}
		cout << o << endl;
	}
}