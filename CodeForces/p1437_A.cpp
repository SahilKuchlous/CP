#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int l, r;
		cin >> l >> r;
		int sz = l-(r-l);
		if (2*sz > r) {
			cout << "YES" << endl;
			continue;
		}
		if (l >= (r+2)/2) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}
