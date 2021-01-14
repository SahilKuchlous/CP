#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		if (a > b+c+1) {
			cout << "No" << endl;
		} else if (b > a+c+1) {
			cout << "No" << endl;
		} else if (c > a+b+1) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
		}
	}
}