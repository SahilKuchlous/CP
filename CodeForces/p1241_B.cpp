#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		bool f = false;
		for (int i=0; i<a.size(); i++) {
			for (int j=0; j<b.size(); j++) {
				if (a[i] == b[j]) {
					f = true;
				}
			}
		}
		if (f) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}