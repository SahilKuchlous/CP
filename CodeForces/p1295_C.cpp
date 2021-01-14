#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string a, b;
		cin >> a >> b;
		map< char, set<int> > pos;
		for (int i=0; i<a.length(); i++) {
			pos[a.at(i)].insert(i);
		}
		int o = 1;
		int x = -1;
		bool imp = false;
		for (auto i: b) {
			if (pos.find(i) == pos.end()) {
				imp = true;
				break;
			}
			if (pos[i].upper_bound(x) != pos[i].end()) {
				x = *pos[i].upper_bound(x);
			} else {
				x = *pos[i].begin();
				o++;
			}
		}
		if (imp) {
			cout << -1 << endl;
		} else {
			cout << o << endl;
		}
	}
}