#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		int w = n-(n/2);
		int a, b, c;
		cin >> a >> b >> c;
		string s;
		cin >> s;
		int o = 0;
		string p = "";
		for (auto i: s) {
			if (i == 'R') {
				if (b>0) {
					b--;
					o++;
					p += "P";
				} else {
					p += "_";
				}
			} else if (i == 'P') {
				if (c>0) {
					c--;
					o++;
					p += "S";
				} else {
					p += "_";
				}
			} else if (i == 'S') {
				if (a>0) {
					a--;
					o++;
					p += "R";
				} else {
					p += "_";
				}
			}
		}
		if (o < w) {
			cout << "NO" << endl;
			continue;
		} else {
			string x = "";
			for (auto i: p) {
				if (i == '_') {
					if (a>0) {
						x += "R";
						a--;
					} else if (b>0) {
						x += "P";
						b--;
					} else if (c>0) {
						x += "S";
						c--;
					}
				} else {
					x += i;
				}
			}
			cout << "YES" << endl;
			cout << x << endl;
		}
	}
}