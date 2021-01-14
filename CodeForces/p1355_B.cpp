#include <iostream>
#include <algorithm>
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
		sort(a, a+n);
		int o = 0;
		int cnt = 0;
		for (int i=0; i<n; i++) {
			cnt++;
			if (cnt >= a[i]) {
				o++;
				cnt = 0;
			}
		}
		cout << o << endl;
	}
}