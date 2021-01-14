#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		int o = 0;
		if (a[n-2] <= k) {
			for (int i=0; i<n; i++) {
				o += a[i];
			}
			cout << o << endl;
			continue;
		}
		int s = 0;
		int c = 1;
		for (int i=0; i<n-2; i++) {
			if (a[i] <= k) {
				o += a[i];
			} else {
				s += a[i]-k;
				c++;
			}
		}
		if (s <= a[n-2]-k) {
			o += a[n-1]-(a[n-2]-k-s)+c*k;
		} else {
			if ((a[n-2]-k)%2 == s%2) {
				o += a[n-1]+c*k;
			} else {
				o += a[n-1]+c*k-1;
			}
		}
		cout << o << endl;
	}
}
/*
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		int o = 0;
		if (a[n-2] <= k) {
			for (int i=0; i<n; i++) {
				o += a[i];
			}
			cout << o << endl;
			continue;
		}
		int s = 0;
		int c = 2;
		for (int i=0; i<n-2; i++) {
			if (a[i] > k) {
				s += a[i]-k;
				c++;
			} else {
				o += a[i];
			}
		}
		if (s < a[n-2]-k) {
			int x = 0;
			for (int i=0; i<n; i++) {
				x += a[i];
			}
			cout << x-2*(a[n-2]-k) << endl;
		} else {
			if (s%2 == (a[n-2]-k)%2) {
				o += c*k + a[n-1] - k;
			} else {
				o += c*k + a[n-1] - k - 1;
			}
			cout << o << endl;
		}
	}
}
*/