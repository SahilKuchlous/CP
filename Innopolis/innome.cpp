#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long m, k;
		cin >> m >> k;
		long long l = 0, r = 1e9, mid, lim = 0;
		while (l <= r) {
			mid = (l+r)/2;
			if (mid == 0 || m*2/(mid*(mid+1)) >= k) {
				lim = mid;
				l = mid+1;
			} else {
				r = mid-1;
			}
		}
		long long o = k*lim;
		long long rem = m - k*lim*(lim+1)/2;
		o += rem/(lim+1);
		cout << o << endl;
	}
}