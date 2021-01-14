#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int o = 0;
		for (int i=1; i<s.size(); i++) {
			if (s[i] == s[i-1] || (i > 1 && s[i] == s[i-2])) {
				for (int j='a'; j<='z'; j++) {
					if (i > 1 && j == s[i-2]) continue;
					if (j == s[i-1]) continue;
					if (i < s.size()-1 && j == s[i+1]) continue;
					if (i < s.size()-2 && j == s[i+2]) continue;
					s[i] = j;
					break;
				}
				o++;
			}
		}
		cout << o << endl;
	}
}