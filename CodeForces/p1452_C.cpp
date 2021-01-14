#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int o = 0;
		int c1 = 0, c2 = 0;
		for (auto i: s) {
			if (i == '(') c1++;
			if (i == '[') c2++;
			if (i == ')' && c1 > 0) {
				o++; c1--;
			}
			if (i == ']' && c2 > 0) {
				o++; c2--;
			}
		}
		cout << o << endl;
	}
}