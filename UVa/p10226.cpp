#include <iostream>
#include <string>
#include <map>
#include <iomanip>
using namespace std;
int main () {
	int t;
	cin >> t;
	string s;
	getline(cin, s);
	getline(cin, s);
	cout << fixed;
	cout << setprecision(4);
	while (t--) {
		map<string, int> m;
		int c = 0;
		while (getline(cin, s)) {
			if (s == "") {
				break;
			}
			c++;
			if (m.find(s) == m.end()) {
				m[s] = 1;
			} else {
				m[s] += 1;
			}
		}
		for (auto i: m) {
			cout << i.first << " ";
			cout << i.second*100.0/c << endl;
		}
		if (t > 0) {
			cout << endl;
		}
	}
}