#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n;
	cin >> n;
	long long a[n];
	for (int i=0; i<n; i++) {
		cin >> a[i];
	}
	long long l = -1e12, r = a[0];
	long long nl, nr;
	for (int i=1; i<n; i++) {
		nl = max(a[i-1], 2*a[i-1]-r);
		nr = min(a[i], 2*a[i-1]-l);
		l = nl; r = nr;
	}
	cout << max(0ll, r-l+1) << endl;
}