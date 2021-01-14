#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		int ttl = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			ttl += a[i];
		}
		if (ttl % x != 0) {
			cout << n << endl;
			continue;
		}
		int s = 0;
		for (int i=0; i<n; i++) {
			if (a[i]%x != 0) break;
			s++;
		}
		int e = 0;
		for (int i=n-1; i>=0; i--) {
			if (a[i]%x != 0) break;
			e++;
		}
		if (s < n || e < n) {
			cout << max(n-s-1, n-e-1) << endl;
		} else {
			cout << -1 << endl;
		}
	}
}