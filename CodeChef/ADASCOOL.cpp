#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		int n, m;
		cin >> n >> m;
		if (n%2 == 1 && m%2 == 1) {
			cout << "NO" << endl;
		} else {
			cout << "YES" << endl;
		}
	}
}