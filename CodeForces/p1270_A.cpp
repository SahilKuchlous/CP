#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k1, k2;
		cin >> n >> k1 >> k2;
		string o = "";
		int x;
		for (int i=0; i<k1; i++) {
			cin >> x;
			if (x == n) {
				o = "YES";
			}
		}
		for (int i=0; i<k2; i++) {
			cin >> x;
			if (x == n) {
				o = "NO";
			}
		}
		cout << o << endl;
	}
}