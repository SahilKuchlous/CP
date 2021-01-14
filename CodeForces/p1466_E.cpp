#include <iostream>
using namespace std;
#define MOD 1000000007
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long a[n];
		int cnt[60];
		for (int i=0; i<60; i++) {
			cnt[i] = 0;
		}
		for (int i=0; i<n; i++) {
			cin >> a[i];
			for (int j=0; j<60; j++) {
				if (a[i]&(1ll<<j)) cnt[j] += 1;
			}
		}
		long long ans = 0;
		for (int i=0; i<n; i++) {
			long long sum_or = 0, sum_and = 0;
			for (int j=0; j<60; j++) {
				if (a[i]&(1ll<<j)) {
					sum_or = (sum_or+(1ll<<j)%MOD*n%MOD)%MOD;
					sum_and = (sum_and+(1ll<<j)%MOD*cnt[j]%MOD)%MOD;
				} else {
					sum_or = (sum_or+(1ll<<j)%MOD*cnt[j]%MOD)%MOD;
				}
			}
			ans = (ans+sum_or*sum_and%MOD)%MOD;
		}
		cout << ans << endl;
	}
}