#include <iostream>
#include <vector>
using namespace std;
#define MAXN 1000005
int n, x;
int a[MAXN];
bool pres[MAXN];
int lim[MAXN];
bool check_l (int v) {
	int m = -1;
	for (int i=0; i<n; i++) {
		if (a[i] > v) continue;
		if (a[i] < m) {
			return false;
		}
		m = a[i];
	}
	return true;
}
bool check_r (int v) {
	int m = -1;
	for (int i=0; i<n; i++) {
		if (a[i] < v) continue;
		if (a[i] < m) {
			return false;
		}
		m = a[i];
	}
	return true;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> x;
	for (int i=0; i<n; i++) {
		cin >> a[i];
		pres[a[i]] = true;
	}
	int min_v = x;
	for (int i=n-1; i>=0; i--) {
		lim[a[i]] = min_v;
		min_v = min(min_v, a[i]);
	}
	int bound_l = -1, bound_r = -1;
	int l = 1, r = x, m;
	while (l <= r) {
		m = (l+r)/2;
		if (check_l(m)) {
			bound_l = m;
			l = m+1;
		} else {
			r = m-1;
		}
	}
	l = 1; r = x;
	while (l <= r) {
		m = (l+r)/2;
		if (check_r(m)) {
			bound_r = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	long long o = 0;
	min_v = bound_l+1;
	for (int i=x; i>=bound_r-1; i--) {
		o += min(i, min_v);
		if (pres[i]) min_v = min(min_v, lim[i]);
	}
	cout << o << endl;
}