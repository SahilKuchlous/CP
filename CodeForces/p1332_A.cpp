#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		int x, y, x1, y1, x2, y2;
		cin >> x >> y >> x1 >> y1 >> x2 >> y2;
		bool pos = true;
		if ((a > 0 || b > 0) && (x1 == x && x == x2)) pos = false;
		if ((c > 0 || d > 0) && (y1 == y && y == y2)) pos = false;
		if (a >= b && x-x1 < a-b) pos = false;
		if (a <= b && x2-x < b-a) pos = false;
		if (c >= d && y-y1 < c-d) pos = false;
		if (c <= d && y2-y < d-c) pos = false;
		if (pos) {
			cout << "Yes" << endl;
		} else {
			cout << "No" << endl;
		}
	}
}