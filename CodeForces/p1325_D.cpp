#include <iostream>
using namespace std;
int main () {
	long long u, v;
	cin >> u >> v;
	if (u%2 != v%2 || u > v) {
		cout << -1 << endl;
		return 0;
	}
	if (u == v) {
		if (u == 0) {
			cout << 0 << endl;
		} else {
			cout << 1 << endl;
			cout << u << endl;
		}
		return 0;
	}
	long long x = (v-u)/2;
	if (u & x) {
		cout << 3 << endl;
		cout << u << " " << x << " " << x << endl;
	} else {
		cout << 2 << endl;
		cout << (u^x) << " " << x << endl;
	}
}