#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	int a[m];
	for (int i=0; i<m; i++) {
		cin >> a[i];
		if (a[i] > n-i) {
			cout << -1 << endl;
			return 0;
		}
	}
	long long suf_sum[m+1];
	suf_sum[m] = 0;
	for (int i=m-1; i>=0; i--) {
		suf_sum[i] = suf_sum[i+1]+a[i];
	}
	if (suf_sum[0] < n) {
		cout << -1 << endl;
		return 0;
	}
	for (int i=0; i<m; i++) {
		cout << max((long long)i+1, n-suf_sum[i]+1) << " ";
	}
	cout << endl;
}