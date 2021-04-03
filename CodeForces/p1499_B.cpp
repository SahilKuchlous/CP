#include <iostream>
using namespace std;
void solve () {
	string s;
	cin >> s;
	bool ones = true;
	int prev = -2;
	bool o = true;
	for (int i=0; i<s.length(); i++) {
		if (ones && s[i] == '1') {
			if (prev == i-1) {
				ones = false;
				continue;
			}
			prev = i;
		}
		if (!ones && s[i] == '0') {
			if (prev == i-1) {
				o = false;
				break;
			}
			prev = i;
		}
	}
	if (o) {
		cout << "YES" << endl;
	} else {
		cout << "NO" << endl;
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}