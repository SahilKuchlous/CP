#include <iostream>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int c[n];
		for (int i=0; i<n; i++) {
			cin >> c[i];
		}
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int b[n];
		for (int i=0; i<n; i++) {
			cin >> b[i];
		}
		int val[n];
		for (int i=1; i<n-1; i++) {
			val[i] = c[i]-abs(a[i+1]-b[i+1])-1;
		}
		val[n-1] = c[n-1];
		long long best = abs(a[1]-b[1])+2;
		long long o = 0;
		for (int i=1; i<n; i++) {
			o = max(o, best+c[i]-1);
			if (i < n-1) {
				best = max(best+val[i], (long long)abs(a[i+1]-b[i+1]));
				if (a[i+1] == b[i+1]) best = 0;
				best += 2;
			}
		}
		cout << o << endl;
	}
}