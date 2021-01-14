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
		for (int i=0; i<s.length(); i++) {
			if (s.at(i) == s.at(s.length()-i-1)) {
				p = i;
			} else {
				break;
			}
		}
		int len = s.length()-2*(p+1);
		string cur = s.substr(p+1, len);
		rs = cur;
		reverse(rs.begin(), rs.end());
		cur += "#"+rs;
		int pi[2*len+10];
		pi[0] = -1;
		for (int i=0; i<2*len+1; i++) {
			int k = pi[i];
			while (k >= 0 && cur.at(k) != cur.at(i)) k = pi[k];
			pi[i+1] = k+1;
		}
		int ans1 = min(len, pi[2*len+1]);
		cur = s.substr(p+1, len);
		rs = cur;
		reverse(rs.begin(), rs.end());
		cur = rs+"#"+cur;
		pi[0] = -1;
		for (int i=0; i<2*len+1; i++) {
			int k = pi[i];
			while (k >= 0 && cur.at(k) != cur.at(i)) k = pi[k];
			pi[i+1] = k+1;
		}
		int ans2 = min(len, pi[2*len+1]);
		string o = "";
		for (int i=0; i<=p; i++) {
			o += s.at(i);
		}
		if (ans1 >= ans2) {
			for (int i=0; i<ans1; i++) {
				o += s.at(p+i+1);
			}
		} else {
			for (int i=0; i<ans2; i++) {
				o += s.at(p+(len-ans2)+i+1);
			}
		}
		for (int i=s.length()-p-1; i<s.length(); i++) {
			o += s.at(i);
		}
		cout << o << endl;
	}
}