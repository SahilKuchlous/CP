#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		int n = s.length();
		bool a[n];
		for (int i=0; i<n; i++) {
			a[i] = false;
		}
		bool out = true;
		for (int i=0; i<n; i++) {
			if (s[i] != '.') {
				for (int j=max(0, i-(s[i]-'0')); j<=min(n-1, i+(s[i]-'0')); j++) {
					if (a[j]) {
						out = false;
						break;
					} else {
						a[j] = true;
					}
				}
				if (!out) {
					break;
				}
			}
		}
		if (out) {
			cout << "safe" << endl;
		} else {
			cout << "unsafe" << endl;
		}
	}
}