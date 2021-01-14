#include <iostream>
#include <string>
#include <map>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		long long n;
		cin >> n;
		int total = 0;
		for (auto i: s) {
			if (i == 'a') {
				total++;
			} else {
				total--;
			}
		}
		string ns = "";
		if (total == 0) {
			ns = s;
		} else {
			for (int i=0; i<min(n, (long long) s.length()); i++) {
				ns += s;
			}
		}
		long long c = 0;
		int cur = 0;
		for (auto i: ns) {
			if (i == 'a') {
				cur++;
			} else {
				cur--;
			}
			if (cur > 0) c++;
		}
		if (total == 0) {
			cout << c*n << endl;
		} else if (total > 0) {
			cout << c+max(0ll, (n-(long long)s.length()))*(long long)s.length() << endl;
		} else {
			cout << c << endl;
		}
	}
}