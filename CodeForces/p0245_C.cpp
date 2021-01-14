#include <iostream>
using namespace std;
int main () {
	int n;
	cin >> n;
	int a[n+1];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	if (n < 3 || n%2 == 0) {
		cout << -1 << endl;
		return 0;
	}
	int st = 0;
	while (true) {
		if (2*st+3 > n) break;
		st += 2;
	}
	int o = 0;
	for (int i=n-1; i>=st; i-=2) {
		o += max(a[i], a[i+1]);
		a[i/2] -= max(a[i], a[i+1]);
	}
	for (int i=st-1; i>0; i--) {
		if (a[i] <= 0) continue;
		o += a[i];
		a[i/2] -= a[i];
		if (i%2 == 1) {
			a[i-1] -= a[i];
		}
	}
	cout << o << endl;
}