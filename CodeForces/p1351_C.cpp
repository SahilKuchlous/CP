#include <iostream>
#include <string>
#include <set>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s;
		set< pair< pair<int, int>, pair<int, int> > > vis;
		pair<int, int> cur = make_pair(0, 0);
		pair<int, int> next;
		int o = 0;
		for (auto i: s) {
			next = cur;
			if (i == 'N') next.second++;
			if (i == 'S') next.second--;
			if (i == 'E') next.first++;
			if (i == 'W') next.first--;
			if (vis.find(make_pair(cur, next)) == vis.end()) {
				o += 5;
				vis.insert(make_pair(cur, next));
				vis.insert(make_pair(next, cur));
			} else {
				o += 1;
			}
			cur = next;
		}
		cout << o << endl;
	}
}