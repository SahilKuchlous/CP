#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long n, k;
		cin >> n >> k;
		if (n%2 != k%2) {
			cout << "NO" << endl;
		} else if (k*k > n) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
}