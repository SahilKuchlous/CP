#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> x >> y;
		if (x-y > 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}