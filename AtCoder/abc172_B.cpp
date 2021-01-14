#include <iostream>
using namespace std;
int main () {
	string s, t;
	cin >> s >> t;
	int o = 0;
	for (int i=0; i<s.length(); i++) {
		if (s.at(i) != t.at(i)) o++;
	}
	cout << o << endl;
}