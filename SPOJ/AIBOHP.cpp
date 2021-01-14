#include <string>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
string s;
int m[7000][7000];
int rec (int l, int u) {
	if (u-l < 1) {
		return 0;
	}
	if (m[l][u] != -1) {
		return m[l][u];
	}
	int d;
	if (s[l] == s[u]) {
		d = rec(l+1, u-1);
	} else {
		d = min(rec(l+1, u), rec(l, u-1))+1;
	}
	m[l][u] = d;
	return d;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin >> t;
	for (int z=0; z<t; z++) {
		cin >> s;
		for (int i=0; i<s.size(); i++) {
			for (int j=0; j<s.size(); j++) {
				m[i][j] = -1;
			}
		}
		cout << rec(0, s.size()-1) << '\n';
	}
	return 0;
}