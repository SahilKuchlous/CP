#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int tn=1; tn<=t; tn++) {
		cout << "Case #" << tn << ": ";
		int a[3][4];
		for (int i=0; i<3; i++) {
			for (int j=0; j<4; j++) {
				cin >> a[i][j];
			}
		}
		int min_c[4];
		for (int i=0; i<4; i++) {
			min_c[i] = 10000000;
		}
		for (int i=0; i<3; i++) {
			for (int j=0; j<4; j++) {
				min_c[j] = min(min_c[j], a[i][j]);
			}
		}
		int ans[4];
		int ttl = 0;
		for (int i=0; i<4; i++) {
			if (ttl + min_c[i] <= 1000000) {
				ttl += min_c[i];
				ans[i] = min_c[i];
			} else {
				ans[i] = 1000000-ttl;
				ttl += 1000000-ttl;
			}
		}
		if (ttl < 1000000) {
			cout << "IMPOSSIBLE" << endl;
		} else {
			for (int i=0; i<4; i++) {
				cout << ans[i] << " ";
			}
			cout << endl;
		}
	}
}