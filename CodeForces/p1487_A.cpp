#include <iostream>
using namespace std;
void solve () {
	int n;
	cin >> n;
	int a[n];
	int min_v = 1e5;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		min_v = min(min_v, a[i]);
	}
	int o = 0;
	for (int i=0; i<n; i++) {
		if (a[i] != min_v) {
			o++;
		}
	}
	cout << o << endl;
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}