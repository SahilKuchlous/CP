#include <iostream>
#include <cmath>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, l, r;
		cin >> n >> l >> r;
		int cnt[n];
		for (int i=0; i<n; i++) {
			cnt[i] = 0; 
		}
		int inp;
		for (int i=0; i<l; i++) {
			cin >> inp;
			inp--;
			cnt[inp]++;
		}
		for (int i=0; i<r; i++) {
			cin >> inp;
			inp--;
			cnt[inp]--;
		}
		int ttl = 0, delta = 0, extra = 0;
		for (int i=0; i<n; i++) {
			ttl += abs(cnt[i]);
			delta += cnt[i];
		}
		for (int i=0; i<n; i++) {
			if ((cnt[i] < 0 && delta < 0) || (cnt[i] > 0 && delta > 0)) extra += abs(cnt[i]/2*2);
		}
		if (extra >= abs(delta)) {
			cout << ttl/2 << endl;
		} else {
			cout << abs(delta)-extra + (ttl-(abs(delta)-extra))/2 << endl;
		}
	}
}