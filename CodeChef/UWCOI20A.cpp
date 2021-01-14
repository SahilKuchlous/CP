#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int o = 0;
		int x;
		for (int i=0; i<n; i++) {
			cin >> x;
			o = max(o, x);
		}
		cout << o << endl;
	}
}