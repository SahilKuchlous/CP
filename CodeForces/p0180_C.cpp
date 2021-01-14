#include <iostream>
#include <string>
using namespace std;
int main () {
	string s;
	cin >> s;
	int cl = 0;
	int cr = 0;
	for (int i=0; i<s.size(); i++) {
		if (s.at(i)-'a' < 0) cr++;
	}
	int o = cr;
	for (int i=0; i<s.size(); i++) {
		if (s.at(i)-'a' < 0) {
			cr--;
		} else {
			cl++;
		}
		o = min(o, cl+cr);
	}
	cout << o << endl;
}