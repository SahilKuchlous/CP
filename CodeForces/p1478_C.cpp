#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		long long a[2*n];
		for (int i=0; i<2*n; i++) {
			cin >> a[i];
		}
		sort(a, a+2*n);
		bool pos = true;
		for (int i=0; i<n; i++) {
			if (a[2*i] != a[2*i+1] || a[2*i]%2 == 1 || (i>0 && a[2*i]==a[2*i-1])) pos = false;
		}
		if (!pos) {
			cout << "NO" << endl;
			continue;
		}
		long long ttl = 0;
		for (int i=n; i>0; i--) {
			long long val = (a[2*i-1]-ttl)/2;
			if (val <= 0) {
				pos = false;
				break;
			}
			if (val%i != 0) {
				pos = false;
				break;
			}
			val /= i;
			ttl += 2*val;
		}
		if (pos) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}