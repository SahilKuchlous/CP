#include <iostream>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		bool pos = false;
		for (int i=1; i<n; i++) {
			if (s[i]<s[i-1]) pos = true;
		}
		if (!pos) {
			cout << s << endl;
			continue;
		}
		string o = "0";
		for (int i=0; i<n; i++) {
			if (s[i] == '1') break;
			o += "0";
		}
		for (int i=n-1; i>=0; i--) {
			if (s[i] == '0') break;
			o += "1";
		}
		cout << o << endl;
	}
}