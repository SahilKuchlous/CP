#include <iostream>
#include <cmath>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		long long ttl = a[0];
		long long o = 0;
		for (int i=1; i<n; i++) {
			if (1ll*a[i]*100 <= ttl*k) {
				ttl += a[i];
				continue;
			}
			long long inc = ceil(1.0*a[i]*100/k)-ttl;
			o += inc;
			ttl += inc+a[i];
		}
		cout << o << endl;
	}
}