#include <iostream>
#include <string>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string a[n];
		for (int i=0; i<n; i++) {
			cin >> a[i];
		}
		bool s[n][26];
		for (int i=0; i<n; i++) {
			for (int j=0; j<26; j++) {
				s[i][j] = false;
			}
			for (auto j: a[i]) {
				s[i][j-'a'] = true;
			}
		}
		int o = 0;
		for (int i=0; i<26; i++) {
			bool spec = true;
			for (int j=0; j<n; j++) {
				if (!s[j][i]) {
					spec = false;
					break;
				}
			}
			if (spec) {
				o++;
			}
		}
		cout << o << endl;
	}
}