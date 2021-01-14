#include <iostream>
#include <iomanip>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		cout << fixed << setprecision(15);
		int n, len;
		cin >> n >> len;
		double a[n+2];
		a[0] = 0;
		for (int i=1; i<=n; i++) {
			cin >> a[i];
		}
		a[n+1] = len;
		double l = 0, r = len, m, t1, t2;
		while (r-l > 0.000000001) {
			m = (l+r)/2;
			t1 = 0;
			for (int i=1; i<n+2; i++) {
				if (a[i] > m) {
					t1 += (m-a[i-1])/i;
					break;
				}
				t1 += (a[i]-a[i-1])/i;
			}
			t2 = 0;
			for (int i=n; i>=0; i--) {
				if (a[i] < m) {
					t2 += (a[i+1]-m)/(n-i+1);
					break;
				}
				t2 += (a[i+1]-a[i])/(n-i+1);
			}
			if (t1 < t2) {
				l = m;
			} else if (t1 > t2) {
				r = m;
			} else {
				break;
			}
		}
		cout << t1 << endl;
	}
}