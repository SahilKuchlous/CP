#include <iostream>
#include <string>
using namespace std;
int n;
string s;
string o = "";
bool done = false;
void check (string s1, string s2) {
	bool pre[n];
	pre[0] = true;
	for (int i=0; i<s1.size(); i++) {
		pre[i+1] = (pre[i] && s1[i] == s2[i]);
	}
	bool post[n];
	post[s2.size()] = true;
	for (int i=s2.size()-1; i>=0; i--) {
		post[i] = (post[i+1] && s1[i-1] == s2[i]);
	}
	for (int i=0; i<s2.size(); i++) {
		if (pre[i] && post[i+1]) {
			if (i == 0) done = true;
			if (o == "") {
				o = s1;
				break;
			} else {
				o = "NOT UNIQUE";
			}
		}
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> s;
	if (n%2 == 0) {
		cout << "NOT POSSIBLE" << endl;
		return 0;
	}
	check(s.substr(0, n/2), s.substr(n/2));
	if (!done) check(s.substr(n/2+1), s.substr(0, n/2+1));
	if (o == "") {
		cout << "NOT POSSIBLE" << endl;
	} else {
		cout << o << endl;
	}
}