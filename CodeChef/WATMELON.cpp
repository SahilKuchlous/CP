#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int inp;
		int sum = 0;
		for (int i=0; i<n; i++) {
			cin >> inp;
			sum += inp;
		}
		if (sum >= 0) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}