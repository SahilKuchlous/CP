#include <iostream>
using namespace std;
int n, k;
int a[200000];
int dp1[200005], dp2[200005];
bool check (int x) {
	for (int i=0; i<n; i++) {
		dp2[i+1] = dp1[i];
		dp1[i+1] = dp2[i];
		if (a[i] <= x) {
			dp1[i+1]++;
			if (i > 0) dp1[i+1]++;
		}
		dp1[i+1] = max(dp1[i+1], dp2[i+1]);
	}
	return (max(dp1[n], dp1[n-1]+1) >= k);
}
int main () {
	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	int l = 0, r = 1e9, m, o;
	while (l <= r) {
		m = (l+r)/2;
		if (check(m)) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << o << endl;
}