#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int x;
		long long s = 0;
		long long o = 0;
		for (int i=0; i<n; i++) {
			cin >> x;
			s += x;
			o = o^x;
		}
		cout << 2 << endl;
		cout << o << " " << o+s << endl;
	}
}