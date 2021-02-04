#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		if (n >= k) {
			if (n%k == 0) {
				cout << 1 << endl;
			} else {
				cout << 2 << endl;
			}
		} else {
			cout << (int)ceil(1.0*k/n) << endl;
		}
	}
}