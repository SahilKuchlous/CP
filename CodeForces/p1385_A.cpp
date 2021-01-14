#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b) swap(a, b);
		if (a > c) swap(a, c);
		if (b > c) swap(a, c);
		if (b != c) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		if (a == b) {
			cout << a << " " << a << " " << a << endl;
			continue;
		}
		cout << a << " " << a << " " << b << endl;
	}
}