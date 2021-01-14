#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		if (n%2 != 0) {
			for (int i=2; i<=n; i++) {
				if (n%i == 0) {
					n += i;
					break;
				}
			}
			n += 2*(k-1);
		} else {
			n += 2*k;
		}
		cout << n << endl;
	}
}