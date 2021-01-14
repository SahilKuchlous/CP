#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n;
		int m;
		cin >> n >> m;
		int cnt[65];
		for (int i=0; i<65; i++) {
			cnt[i] = 0;
		}
		int ai;
		for (int i=0; i<m; i++) {
			cin >> ai;
			cnt[(int)log2(ai)]++;
		}
		bool pos = true;
		int o = 0;
		for (int i=0; i<60; i++) {
			if (i > 0) cnt[i] += cnt[i-1]/2;
			if (n & (1ll<<i)) {
				if (cnt[i] > 0) {
					cnt[i]--;
				} else {
					int nxt = -1;
					for (int j=i; j<35; j++) {
						if (cnt[j] > 0) {
							nxt = j; break;
						}
					}
					if (nxt == -1) {
						pos = false; break;
					}
					cnt[nxt]--;
					for (int j=i+1; j<nxt; j++) {
						cnt[j]++;
					}
					o += nxt-i;
				}
			}
		}
		if (pos) {
			cout << o << endl;
		} else {
			cout << -1 << endl;
		}
	}
}