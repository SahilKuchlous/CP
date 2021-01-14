#include <iostream>
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
		int o = 0;
		for (int i=0; i<n; i++) {
			int cur = a[0];
			int l = 0, r = 0;
			while (true) {
				if (l == r) {
					r++;
					if (r == n) break;
					cur += a[r];
					continue;
				}
				if (cur == a[i]) {
					o++;
					break;
				}
				if (cur < a[i]) {
					r++;
					if (r == n) break;
					cur += a[r];
					continue;
				}
				cur -= a[l];
				l++;
			}
		}
		cout << o << endl;
	}
}