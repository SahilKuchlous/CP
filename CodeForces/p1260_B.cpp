#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int temp;
		if (a < b) {
			temp = a;
			a = b;
			b = temp;
		}
		if (2*b < a) {
			cout << "NO" << endl;
			continue;
		}
		int x = b-(a-b);
		if (x%3 == 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}