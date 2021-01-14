#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int q;
	cin >> q;
	while (q--) {
		int n, r;
		cin >> n >> r;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		sort(a, a+n);
		int c = 1;
		for (int i=2; i<=n; i++) {
			if (a[n-i] == a[n-i+1]) {
				continue;
			}
			if (a[n-i]-r*c <= 0) {
				break;
			}
			c++;
		}
		cout << c << endl;
	}
}