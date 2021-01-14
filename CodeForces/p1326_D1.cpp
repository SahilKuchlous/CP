#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		string rs = s;
		reverse(rs.begin(), rs.end());
		if (s == rs) {
			cout << s << endl;
			continue;
		}
		int p = -1;
		for (int i=0; i<=s.length()-i-1; i++) {
			if (s.at(i) == s.at(s.length()-i-1)) {
				p = i;
			} else {
				break;
			}
		}
		int len = 0;
		string mid = "";
		vector<char> cur;
		string n = "";
		for (int i=p+1; i<s.length()-p-1; i++) {
			n += s.at(i);
			rs = n;
			reverse(rs.begin(), rs.end());
			if (n == rs && i-p > len) {
				len = i-p;
				mid = n;
			}
		}
		n = "";
		for (int i=s.length()-p-2; i>p; i--) {
			n += s.at(i);
			rs = n;
			reverse(rs.begin(), rs.end());
			if (n == rs && s.length()-p-1-i > len) {
				len = s.length()-p-1-i;
				mid = n;
			}
		}
		string o = "";
		for (int i=0; i<=p; i++) {
			o += s.at(i);
		}
		o += mid;
		for (int i=s.length()-p-1; i<s.length(); i++) {
			o += s.at(i);
		}
		cout << o << endl;
	}
}