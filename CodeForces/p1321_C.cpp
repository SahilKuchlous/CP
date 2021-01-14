#include <iostream>
#include <string>
using namespace std;
int main () {
	int n;
	cin >> n;
	string s;
	cin >> s;
	char cur = 'z';
	while (cur > 'a') {
		bool found = false;
		for (int i=0; i<s.length(); i++) {
			if (s.at(i) == cur) {
				if ((i>0 && s.at(i-1) == cur-1) || (i<s.length()-1 && s.at(i+1) == cur-1)) {
					found = true;
					s = s.substr(0, i)+s.substr(i+1);
					break;
				}
			}
		}
		if (!found) cur--;
	}
	cout << n-s.length() << endl;
}