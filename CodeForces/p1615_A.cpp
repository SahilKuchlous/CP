#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		int sum = 0;
		for (int i=0; i<n; i++) {
			sum += a[i];
		}
		if (sum%n == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
		}
	}
}