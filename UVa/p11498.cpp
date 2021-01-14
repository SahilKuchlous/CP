#include <iostream>
using namespace std;
int main () {
	while (true) {
		int k;
		cin >> k;
		if (k == 0) {
			break;
		}
		int n, m;
		cin >> n >> m;
		while (k--) {
			int x, y;
			cin >> x >> y;
			if (x > n && y > m) {
				cout << "NE" << endl;
			} else if (x > n && y < m) {
				cout << "SE" << endl;
			} else if (x < n && y > m) {
				cout << "NO" << endl;
			} else if (x < n && y < m) {
				cout << "SO" << endl;
			} else {
				cout << "divisa" << endl;
			}
		}
	}
}