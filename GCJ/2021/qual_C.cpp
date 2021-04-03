#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void solve () {
	int n, c;
	cin >> n >> c;
	if (c < n-1) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	bool rev = false;
	int o[n];
	for (int i=0; i<n; i++) {
		o[i] = -1;
	}
	for (int i=0; i<n; i++) {
		int mx = n-i;
		if (mx+n-i-2 <= c) {
			c -= mx;
			if (rev) {
				o[i/2] = i+1;
			} else {
				o[n-i/2-1] = i+1;
			}
			rev = !rev;
			continue;
		}
		if (!rev) {
			int pos = i/2+c-n+i+2;
			o[pos] = i+1;
			int cur = i+2;
			for (int j=pos+1; j<n; j++) {
				if (o[j] != -1) break;
				o[j] = cur;
				cur++;
			}
			for (int j=pos-1; j>=0; j--) {
				if (o[j] != -1) break;
				o[j] = cur;
				cur++;
			}
		} else {
			int pos = n-i/2-1-c+n-i-2;
			o[pos] = i+1;
			int cur = i+2;
			for (int j=pos-1; j>=0; j--) {
				if (o[j] != -1) break;
				o[j] = cur;
				cur++;
			}
			for (int j=pos+1; j<n; j++) {
				if (o[j] != -1) break;
				o[j] = cur;
				cur++;
			}
		}
		c = 0;
		break;
	}
	if (c > 0) {
		cout << "IMPOSSIBLE" << endl;
		return;
	}
	for (int i=0; i<n; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}
int main () {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ": ";
		solve();
	}
}