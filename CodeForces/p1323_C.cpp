#include <iostream>
#include <string>
using namespace std;
int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int c = 0, l = 0, x = 0, o = 0;
	for (int i=0; i<n; i++) {
		if (s.at(i) == '(') {
			c++;
		} else {
			c--;
		}
		l = min(l, c);
		if (c == 0) {
			if (l < 0) o += i-x+1;
			x = i+1;
			c = l = 0;
		}
	}
	if (c != 0) {
		cout << -1 << endl;
	} else {
		cout << o << endl;
	}
}