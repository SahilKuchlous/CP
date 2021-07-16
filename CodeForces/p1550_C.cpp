#include <iostream>
using namespace std;
void solve () {
	int n;
	cin >> n;
	int a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int o = 2*n-1;
	for (int i=0; i<n-2; i++) {
		if ((a[i+1] < a[i] && a[i+1] < a[i+2]) || (a[i+1] > a[i] && a[i+1] > a[i+2])) o++;
	}
	for (int i=0; i<n-3; i++) {
		if ((a[i+1] < a[i] && a[i+1] < a[i+3] && a[i+2] > a[i] && a[i+2] > a[i+3]) || (a[i+1] > a[i] && a[i+1] > a[i+3] && a[i+2] < a[i] && a[i+2] < a[i+3])) o++;
	}
	cout << o << '\n';
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}