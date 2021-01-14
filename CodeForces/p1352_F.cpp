#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int a, b, c;
		cin >> a >> b >> c;
		string o = "";
		char prev = '0';
		if (a != 0) {
			b--;
			for (int i=0; i<=a; i++) {
				o += '0';
			}
		}
		if (c != 0) {
			b--;
			for (int i=0; i<=c; i++) {
				o += '1';
			}
			prev = '1';
		}
		char cur = (prev=='0' ? '1':'0');
		for (int i=0; i<=b; i++) {
			o += cur;
			cur = (cur=='0' ? '1':'0');
		}
		cout << o << endl;
	}
}