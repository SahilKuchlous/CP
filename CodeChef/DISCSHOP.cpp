#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		bool done = false;
		for (int i=0; i<s.length()-1; i++) {
			if (s[i]-'0' > s[i+1]-'0') {
				if (i == 0) {
					cout << stoi(s.substr(1, s.length()-1)) << endl;
				} else {
					cout << stoi(s.substr(0, i)+s.substr(i+1, s.length()-i-1)) << endl;
				}
				done = true;
				break;
			}
		}
		if (!done) {
			cout << stoi(s.substr(0, s.length()-1)) << endl;
		}
	}
}