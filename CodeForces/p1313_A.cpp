#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		int o = 0;
		if (a > 0) {
			a--; o++;
		}
		if (b > 0) {
			b--; o++;
		}
		if (c > 0) {
			c--; o++;
		}
		if (c > a) {
			swap(a, c);
		}
		if (b > a) {
			swap(a, b);
		}
		if (a > 0 && b > 0) {
			a--; b--; o++;
		}
		if (a > 0 && c > 0) {
			a--; c--; o++;
		}
		if (b > 0 && c > 0) {
			b--; c--; o++;
		}
		if (a > 0 && b > 0 && c > 0) {
			o++;
		}
		cout << o << endl;
	}
}