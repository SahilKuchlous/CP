#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int a[n];
		int odd_c = 0;
		for (int i=0; i<n; i++) {
			cin >> a[i];
			if (a[i]%2==1) odd_c++;
		}
		if (odd_c == 0) {
			cout << "NO" << endl;
		} else if (odd_c < n) {
			cout << "YES" << endl;
		} else {
			if (n%2 == 0) {
				cout << "NO" << endl;
			} else {
				cout << "YES" << endl;
			}
		}
	}
}