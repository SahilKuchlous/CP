#include <iostream>
#include <algorithm>
using namespace std;
void solve () {
	int n, d;
	cin >> n >> d;
	int a[n];
	bool done = true;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		if (a[i] > d) done = false;
	}
	if (done) {
		cout << "YES" << endl;
		return;
	}
	sort(a, a+n);
	if (a[0]+a[1] <= d) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}