#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		bool pos = false;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i] == k) pos = true;
		}
		if (!pos) {
			cout << "NO" << endl;
			continue;
		}
		pos = false;
		for (int i=0; i<n; i++) {
			if (i < n-1 && a[i] >= k && a[i+1] >= k) pos = true;
			if (i < n-1 && i > 0 && a[i-1] >= k && a[i+1] >= k) pos = true;
		}
		if (n == 1) pos = true;
		cout << (pos?"YES":"NO") << endl;
	}
}