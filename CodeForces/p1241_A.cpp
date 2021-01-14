#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		if (n<=3) {
			cout << 4-n << endl;
		} else {
			cout << n%2 << endl;
		}
	}
}