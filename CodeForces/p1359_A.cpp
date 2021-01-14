#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, m, k;
		cin >> n >> m >> k;
		if (m <= n/k) {
			cout << m << endl;
			continue;
		}
		cout << n/k-ceil(1.0*(m-n/k)/(k-1)) << endl;
	}
}