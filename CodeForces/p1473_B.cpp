#include <iostream>
using namespace std;
void solve () {
	string s, t;
	cin >> s >> t;
	int lcm;
	for (int i=1; i<=s.length()*t.length(); i++) {
		if (i%s.length() == 0 && i%t.length() == 0) {
			lcm = i;
			break;
		}
	}
	bool pos = true;
	for (int i=0; i<lcm; i++) {
		if (s[i%s.length()] != t[i%t.length()]) {
			pos = false;
			break;
		}
	}
	if (pos) {
		for (int i=0; i<lcm/s.length(); i++) {
			cout << s;
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}