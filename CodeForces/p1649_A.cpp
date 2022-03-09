#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int f = -1, l = -1;
		for (int i=0; i<n; i++) {
			int inp;
			cin >> inp;
			if (inp == 0) {
				l = i;
				if (f == -1) f = i;
			}
		}
		if (f == -1) {
			cout << 0 << endl;
		} else {
			cout << l-f+2 << endl;
		}
	}
}