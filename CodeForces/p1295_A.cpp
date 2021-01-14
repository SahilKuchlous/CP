#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string o = "";
		if (n%2 == 0) {
			for (int i=0; i<n/2; i++) {
				o += '1';
			}
		} else {
			o += '7';
			for (int i=0; i<(n-3)/2; i++) {
				o += '1';
			}
		}
		cout << o << endl;
	}
}