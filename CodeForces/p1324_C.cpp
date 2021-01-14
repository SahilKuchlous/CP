#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int prev = -1;
		int o = 0;
		for (int i=0; i<s.length(); i++) {
			if (s.at(i) == 'R') {
				o = max(o, i-prev);
				prev = i;
			}
		}
		o = max(o, (int)s.length()-prev);
		cout << o << endl;
	}
}