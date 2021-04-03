#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int solve () {
	int x, y;
	string s;
	cin >> x >> y >> s;
	char prv = s[0];
	int o = 0;
	for (int i=0; i<s.size(); i++) {
		if (s[i] == '?') {
			continue;
		}
		if (s[i] == 'J' && prv == 'C') o += x;
		if (s[i] == 'C' && prv == 'J') o += y;
		prv = s[i];
	}
	return o;
}
int main () {
	int t;
	cin >> t;
	for (int i=0; i<t; i++) {
		cout << "Case #" << i+1 << ": " << solve() << endl;
	}
}