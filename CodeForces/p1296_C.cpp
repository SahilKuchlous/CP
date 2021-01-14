#include <iostream>
#include <string>
#include <map>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		string s;
		cin >> s;
		int r = 0, u = 0;
		map< pair<int, int>, int > occ;
		occ[make_pair(0, 0)] = 0;
		int best_val = 1000000;
		pair<int, int> best_range;
		for (int i=0; i<s.length(); i++) {
			if (s.at(i) == 'L') {
				r--;
			} else if (s.at(i) == 'R') {
				r++;
			} else if (s.at(i) == 'U') {
				u++;
			} else {
				u--;
			}
			if (occ.find(make_pair(r, u)) != occ.end()) {
				if (i-occ[make_pair(r, u)] < best_val) {
					best_val = i-occ[make_pair(r, u)];
					best_range = make_pair(i+1, occ[make_pair(r, u)]+1);
				}
			}
			occ[make_pair(r, u)] = i+1;
		}
		if (best_val == 1000000) {
			cout << -1 << endl;
		} else {
			cout << best_range.second << " " << best_range.first << endl;
		}
	}
}