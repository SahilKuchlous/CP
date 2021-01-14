#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {
	unsigned long long n, x;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		int c2 = 0;
		int c5 = 0;
		for (int j=2; j<=x; j*=2) {
			c2 += floor(x/j);
		}
		for (int j=5; j<=x; j*=5) {
			c5 += floor(x/j);
		}
		cout << min(c2, c5) << endl;
	}
	return 0;
}