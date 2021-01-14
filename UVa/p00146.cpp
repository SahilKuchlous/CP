#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	while (true) {
		string s;
		cin >> s;
		if (s == "#") {
			break;
		}
		char c[s.size()];
		for (int i=0; i<s.size(); i++) {
			c[i] = s[i];
		}
		if (next_permutation(c, c+s.size())) {
			for (int i=0; i<s.size(); i++) {
				cout << c[i];
			}
			cout << endl;
		} else {
			cout << "No Successor" << endl;
		}
	}
}