#include <iostream>
#include <string>
using namespace std;
int main () {
	int k;
	cin >> k;
	string s;
	cin >> s;
	if (s.length() <= k) {
		cout << s << endl;
		return 0;
	}
	string o = "";
	for (int i=0; i<k; i++) {
		o += s[i];
	}
	o += "...";
	cout << o << endl;
	return 0;
}