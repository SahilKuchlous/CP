#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		bool pres[n];
		for (int i=0; i<n; i++) pres[i] = false;
		bool zero = true;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			a[i]--;
			pres[a[i]] = true;
			if (i > 0 && a[i] != a[i-1]) zero = false;
		}
		if (zero) {
			cout << 0 << endl;
			continue;
		}
		int cnt[n];
		for (int i=0; i<n; i++) cnt[i] = 0;
		for (int i=1; i<n; i++) {
			if (a[i] != a[i-1]) cnt[a[i]]++;
		}
		for (int i=0; i<n; i++) {
			if (i != a[n-1]) cnt[i]++;
		}
		int o = n;
		for (int i=0; i<n; i++) {
			if (pres[i]) o = min(o, cnt[i]);
		}
		cout << o << endl;
	}
}