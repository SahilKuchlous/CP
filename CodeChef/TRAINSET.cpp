#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		map< string, pair<int, int> > m;
		string s;
		int x;
		for (int i=0; i<n; i++) {
			cin >> s >> x;
			if (m.find(s) != m.end()) {
				if (x == 0) {
					m[s].first++;
				} else {
					m[s].second++;
				}
			} else {
				if (x == 0) {
					m[s].first = 1;
					m[s].second = 0;
				} else {
					m[s].first = 0;
					m[s].second = 1;
				}
			}
		}
		int o = 0;
		for (auto i: m) {
			o += max(i.second.first, i.second.second);
		}
		cout << o << endl;
	}
}