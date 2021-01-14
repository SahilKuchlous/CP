#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int r, g, b;
		cin >> r >> g >> b;
		if (g >= r+b) {
			cout << r+b << endl;
		} else if (r >= g+b) {
			cout << g+b << endl;
		} else if (b >= r+g) {
			cout << r+g << endl;
		} else {
			cout << (r+g+b)/2 << endl;
		}
	}
}