#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int suf = 0;
		for (int i=n-1; i>0; i--) {
			if (a[i] < a[i-1]) {
				suf = i+1;
				break;
			}
		}
		int cnt = 0;
		bool pos = true;
		for (int i=0; i<suf; i++) {
			if (a[i] > x) {
				swap(a[i], x);
				cnt++;
			}
			if (i < n-1 && a[i] > a[i+1]) {
				pos = false;
				break;
			}
		}
		if (pos) {
			cout << cnt << endl;
		} else {
			cout << -1 << endl;
		}
	}
}