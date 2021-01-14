#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string o = "";
		for (auto i: s) {
			if ((int)i % 2 == 1) {
				o += i;
			}
			if (o.length() == 2) {
				break;
			}
		}
		if (o.length() == 2) {
			cout << o << endl;
		} else {
			cout << -1 << endl;
		}
	}
}