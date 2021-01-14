#include <iostream>
#include <algorithm>
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
		sort(a, a+n, greater<int>());
		double s = 0;
		int o = 0;
		for (int i=0; i<n; i++) {
			s += a[i];
			if (s/(i+1) >= x) {
				o = i+1;
			}
		}
		cout << o << endl;
	}
}