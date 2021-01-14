#include <iostream>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		set<int> used;
		used.insert(a[0]);
		int m = a[0];
		int x = 1;
		int o[n];
		o[0] = a[0];
		bool pos = true;
		for (int i=1; i<n; i++) {
			if (a[i] > n) {
				pos = false;
				break;
			}
			if (a[i] == a[i-1]) {
				while (used.find(x) != used.end()) {
					x++;
				}
				if (x > a[i]) {
					pos = false;
					break;
				}
				o[i] = x;
				used.insert(x);
				if (x > m) {
					m = x;
				}
				x++;
			} else {
				if (used.find(a[i]) == used.end() && a[i] > m) {
					o[i] = a[i];
					used.insert(a[i]);
					m = a[i];
				} else {
					pos = false;
					break;
				}
			}
		}
		if (pos) {
			for (int i=0; i<n; i++) {
				cout << o[i] << " ";
			}
			cout << endl;
		} else {
			cout << -1 << endl;
		}
	}
}