#include <iostream>
#include <algorithm>
using namespace std;
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	for (int test=0; test<t; test++) {
		cout << "Case #" << test+1 << ": ";
		string s;
		cin >> s;
		int n = s.length();
		string o = "";
		bool extend[n];
		for (int i=0; i<n; i++) {
			extend[i] = false;
		}
		for (int i=0; i<s.length()-1; i++) {
			if (s[i] < s[i+1]) {
				extend[i] = true;
			}
		}
		o += s[n-1];
		for (int i=n-2; i>=0; i--) {
			if (s[i] == s[i+1]) {
				extend[i] = extend[i+1];
			}
			o += s[i];
			if (extend[i]) {
				o += s[i];
			}
		}
		reverse(o.begin(), o.end());
		cout << o << '\n';
	}
}