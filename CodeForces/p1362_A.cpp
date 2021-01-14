#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if (a > b) swap(a, b);
		int o = 0;
		while (true) {
			if (a == b) break;
			if (8*a <= b) {
				a *= 8;
			} else if (4*a <= b) {
				a *= 4;
			} else if (2*a <= b) {
				a *= 2;
			} else {
				o = -1;
				break;
			}
			o++;
		}
		cout << o << endl;
	}
}