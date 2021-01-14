#include <iostream>
#include <cmath>
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
		bool pos = true;
		for (int i=0; i<n-1; i++) {
			if (abs(a[i+1]-a[i])%2 == 1) pos = false;
		}
		if (pos) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}