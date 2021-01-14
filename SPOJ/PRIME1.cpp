#include <iostream>
using namespace std;
bool prime (int n) {
	if (n == 1) {
		return false;
	} else {
		bool p = true;
		for (int i=2; i*i<=n; i++) {
			if (n%i == 0) {
				p = false;
				break;
			}
		}
		return p;
	}
}
int main () {
	unsigned long n, a, b;
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> a;
		cin >> b;
		for (int j=a; j<=b; j++) {
			if (prime(j)) {
				cout << j << endl;
			}
		}
		cout << endl;
	}
	return 0;
}