#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		cout << 9;
		if (n == 1) {
			cout << endl;
			continue;
		}
		cout << 8;
		if (n == 2) {
			cout << endl;
			continue;
		}
		cout << 9;
		for (int i=0; i<n-3; i++) {
			cout << i%10;
		}
		cout << endl;
	}
}