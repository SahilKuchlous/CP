#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int best = -1;
		k = min(m-1, k);
		for (int i=0; i<=k; i++) {
			int ans = 1e9;
			for (int j=0; j<m-k; j++) {
				/*
				cout << a[i+j] << " " << a[n-1-(k-i)-j] << " ";
				ans = min(ans, a[i+j]);
				ans = min(ans, a[n-1-(k-i)-j]);
				*/
				// cout << a[i+j] << " " << a[n-1-(k-i)-(m-k-j-1)] << " ";
				ans = min(ans, max(a[i+j], a[n-1-(k-i)-(m-k-j-1)]));
			}
			// cout << endl;
			best = max(best, ans);
		}
		cout << best << endl;
	}
}