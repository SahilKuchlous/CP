#include <iostream>
using namespace std;
int main () {
	string s;
	cin >> s;
	int k;
	cin >> k;
	char c1 = 'z', c2 = 'z';
	for (int i=0; i<s.length()-1; i++) {
		if (s[i] < c1 || (s[i] == c1 && s[i+1] < c2)) {
			c1 = s[i];
			c2 = s[i+1];
		}
	}
	for (int i=s.length()-1; i>0; i--) {
		if (s[i] < c1 || (s[i] == c1 && s[i-1] < c2)) {
			c1 = s[i];
			c2 = s[i-1];
		}
	}
	string o = "";
	for (int i=0; i<k; i++) {
		if (i%2 == 0) {
			o += c1;
		} else {
			o += c2;
		}
	}
	cout << o << endl;
}