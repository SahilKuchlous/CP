#include <iostream>
#include <cmath>
using namespace std;
int main () {
	while (true) {
		int n;
		cin >> n;
		if (n == -1) {
			break;
		}
		int a[n];
		int s = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			s += a[i];
		}
		if (s%n == 0) {
			int d = 0;
			for (int i=0; i<n; i++) {
				d += abs(a[i]-(s/n));
			}
			cout << d/2 << endl;
		} else {
			cout << -1 << endl;
		}
	}
	return 0;
}