#include <iostream>
using namespace std;
void solve () {
	int n;
	cin >> n;
	int a[n+1];
	for (int i=1; i<=n; i++) {
		cin >> a[i];
	}
	int psum[n+1];
	psum[0] = 0;
	int rt = n-1;
	for (int i=1; i<=n; i++) {
		psum[i] = psum[i-1];
		if (i%2) {
			psum[i] += a[i];
			if (psum[i] < 0 && i < rt) rt = i;
		} else {
			psum[i] -= a[i];
			if (psum[i] > 0 && i < rt) rt = i;
		}
	}
	int lim[n+2][2];
	lim[n+1][0] = 1e9;
	lim[n+1][1] = -1e9;
	for (int i=n; i>=0; i--) {
		lim[i][0] = lim[i+1][0];
		lim[i][1] = lim[i+1][1];
		if (i%2) {
			lim[i][0] = min(lim[i][0], psum[i]);
		} else {
			lim[i][1] = max(lim[i][1], psum[i]);
		}
	}
	if (psum[n] == 0 && lim[0][0] >= 0 && lim[0][1] <= 0) {
		cout << "YES" << endl;
		return;
	}
	bool o = false;
	for (int i=1; i<=rt; i++) {
		int del = 0;
		if (i%2) {
			if (psum[i-1]+a[i+1] < 0) continue;
			if (psum[i-1]+a[i+1]-a[i] > 0) continue;
			del = 2*a[i+1]-2*a[i];
		} else {
			if (psum[i-1]-a[i+1] > 0) continue;
			if (psum[i-1]-a[i+1]+a[i] < 0) continue;
			del = 2*a[i]-2*a[i+1];
		}
		if (del != -psum[n]) continue;
		if (lim[i+2][0]+del < 0) continue;
		if (lim[i+2][1]+del > 0) continue;
		o = true;
	}
	if (o) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}