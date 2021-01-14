#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, d;
		cin >> n >> d;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int o = a[0];
		int c = 0;
		for (int i=1; i<n; i++) {
			if (c + a[i]*i <= d) {
				c += a[i]*i;
				o += a[i];
			} else {
				o += (d-c)/i;
				break;
			}
		}
		cout << o << endl;
	}
}