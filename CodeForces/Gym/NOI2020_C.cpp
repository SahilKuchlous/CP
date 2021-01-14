#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		string cur = "";
		int c1 = 0, c2 = 0, c3 = 0;
		for (auto i: s) {
			cur += i;
			if (cur == "TJ") {
				c1++;
				cur = "";
			} else if (cur == "si") {
				c2++;
				cur = "";
			} else if (cur == "log") {
				c3++;
				cur = "";
			}
		}
		cout << c1 << " " << c2 << " " << c3 << endl;
	}
}