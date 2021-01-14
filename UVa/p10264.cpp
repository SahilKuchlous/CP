#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	while (cin >> n) {
		int e = pow(2, n);
		int a[e];
		for (int i=0; i<e; i++) {
			cin >> a[i];
		}
		int p[e];
		int x, s;
		for (int i=0; i<e; i++) {
			s = 0;
			for (int j=0; j<n; j++) {
				s += a[i^(1<<j)];
			}
			p[i] = s;
		}
		int m = 0;
		for (int i=0; i<e; i++) {
			for (int j=0; j<n; j++) {
				x = p[i]+p[i^(1<<j)];
				if (x > m) {
					m = x;
				}
			}
		}
		cout << m << endl;
	}
}