#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		long long a, b;
		cin >> a >> b;
		if (a == 1) cout << 0 << endl;
		if (a == 2) cout << b << endl;
		if (a > 2) cout << 2*b << endl;
	}
}