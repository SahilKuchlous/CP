#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c, n;
		cin >> a >> b >> c >> n;
		int temp;
		if (max(a, b) == b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (max(a, c) == c) {
			temp = a;
			a = c;
			c = temp;
		}
		if (n-(2*a-b-c) >= 0 && (n-(2*a-b-c))%3 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}