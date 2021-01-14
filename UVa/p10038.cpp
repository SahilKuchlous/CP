#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int n;
	while (cin >> n) {
		int a[n];
		bool f[n-1];
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (i != n-1) {
				f[i] = false;
			}
		}
		if (n == 1) {
			cout << "Jolly" << endl;
			continue;
		}
		int d;
		for (int i=0; i<n-1; i++) {
			d = abs(a[i+1]-a[i])-1;
			f[d] = true;
		}
		bool j = true;
		for (int i=0; i<n-1; i++) {
			if (!f[i]) {
				cout << "Not jolly" << endl;
				j = false;
				break;
			}
		}
		if (j) {
			cout << "Jolly" << endl;
		}
	}
}