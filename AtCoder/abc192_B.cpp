#include <iostream>
using namespace std;
int main () {
	string s;
	cin >> s;
	bool o = true;
	for (int i=0; i<s.length(); i++) {
		if ((i%2 == 0 && s[i] >= 97 && s[i] <= 122) || (i%2 == 1 && s[i] >= 65 && s[i] <= 90)) continue;
		o = false;
	}
	if (o) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
}