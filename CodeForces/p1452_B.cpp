#include <iostream>
#include <set>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long a[n];
		long long sum = 0, mx = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			sum += a[i];
			mx = max(mx, a[i]);
		}
		if (mx*(n-1) >= sum) {
			cout << mx*(n-1)-sum << endl;
		} else {
			cout << ((sum%(n-1)) ? ((n-1)-sum%(n-1)):0) << endl;
		}
	}
}