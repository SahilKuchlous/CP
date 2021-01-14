#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		char a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		cout << a[k-1];
		if (a[0] < a[k-1]) {
			cout << endl;
			continue;
		}
		if (a[k] == a[n-1]) {
			for (int i=0; i<ceil((1.0*n-k)/k); i++) {
				cout << a[k];
			}
			cout << endl;
			continue;
		}
		for (int i=k; i<n; i++) {
			cout << a[i];
		}
		cout << endl;
	}
}