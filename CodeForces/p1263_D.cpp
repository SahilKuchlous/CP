#include <iostream>
#include <set>
using namespace std;
int main () {
	int n;
	cin >> n;
	set< set<char> > v;
	string s;
	set<char> cur;
	for (int i=0; i<n; i++) {
		cur.clear();
		cin >> s;
		for (auto j: s) {
			cur.insert(j);
		}
		v.insert(cur);
	}
	bool e;
	while (true) {
		for (auto i: v) {
			e = false;
			for (auto j: v) {
				if (v.find(i) == v.find(j)) {
					continue;
				}
				for (char x='a'; x<='z'; x++) {
					if (i.find(x) != i.end() && j.find(x) != j.end()) {
						cur.clear();
						for (auto z: i) {
							cur.insert(z);
						}
						for (auto z: j) {
							cur.insert(z);
						}
						v.erase(i);
						v.erase(j);
						v.insert(cur);
						e = true;
						break;
					}
				}
				if (e) {
					break;
				}
			}
			if (e) {
				break;
			}
		}
		if (!e) {
			break;
		}
	}
	cout << v.size() << endl;
}