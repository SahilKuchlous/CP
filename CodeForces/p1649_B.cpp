#include <iostream>
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
		long long ttl = 0;
		long long mv = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			ttl += a[i];
			mv = max(mv, a[i]);
		}
		if (mv == 0) {
			cout << 0 << '\n';
			continue;
		}
		if (mv > (ttl-mv+1)) {
			cout << 1+mv-(ttl-mv+1) << '\n';
		} else {
			cout << 1 << '\n';
		}
	}
}