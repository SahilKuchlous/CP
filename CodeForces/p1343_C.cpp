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
		long long total = 0;
		int cur = a[0];
		bool pos = (a[0] > 0 ? true : false);
		for (int i=1; i<n; i++) {
			if ((a[i] < 0 && pos) || (a[i] > 0 && !pos)) {
				total += cur;
				pos = !pos;
				cur = a[i];
			} else {
				cur = max(cur, a[i]);
			}
		}
		total += cur;
		cout << total << endl;
	}
}