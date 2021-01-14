#include <iostream>
#include <cmath>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long x, y;
		cin >> x >> y;
		long long a, b;
		cin >> a >> b;
		if (abs(x) < abs(y)) swap(x, y);
		long long o = 0;
		if ((x > 0 && y < 0) || (x < 0 && y > 0) || 2*a <= b) {
			o = a*(abs(x)+abs(y));
		} else {
			o = a*abs(x-y) + b*min(abs(x), abs(y));
		}
		cout << o << endl;
	}
}