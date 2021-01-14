#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int x, y;
		cin >> x >> y;
		if (y <= x) {
			cout << "YES" << endl;
			continue;
		}
		if (x >= 4) {
			cout << "YES" << endl;
			continue;
		}
		if ((x == 3 || x == 2) && y <= 3) {
			cout << "YES" << endl;
			continue;
		}
		cout << "NO" << endl;
	}
}