#include <iostream>
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
		int cnt = 0;
		for (int i=1; i<n; i++) {
			if (a[i] > a[i-1]) cnt++;
		}
		if (k == 1) {
			cout << (cnt>0 ? -1:1)<< endl;
			continue;
		}
		if (cnt == 0) {
			cout << 1 << endl;
			continue;
		}
		cout << (cnt+k-2)/(k-1) << endl;
	}
}