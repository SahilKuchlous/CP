#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
int main () {
	int n, m;
	while (cin >> n >> m) {
		char w1, w2, w3;
		cin >> w1 >> w2 >> w3;
		set<char> awake;
		set<char> areas;
		awake.insert(w1);
		awake.insert(w2);
		awake.insert(w3);
		areas.insert(w1);
		areas.insert(w2);
		areas.insert(w3);
		map< char, vector<char> > adj;
		for (int i=0; i<m; i++) {
			cin >> w1 >> w2;
			adj[w1].push_back(w2);
			adj[w2].push_back(w1);
			areas.insert(w1);
			areas.insert(w2);
		}
		set<char> awake_new = awake;
		int o = 0;
		bool pos = true;
		while (true) {
			if (awake.size() == n) {
				cout << "WAKE UP IN, " << o << ", YEARS" << endl;
				break;
			}
			for (auto i: areas) {
				if (awake.find(i) == awake.end()) {
					int c = 0;
					for (auto j: adj[i]) {
						if (awake.find(j) != awake.end()) {
							c++;
						}
					}
					if (c >= 3) {
						awake_new.insert(i);
					}
				}
			}
			if (awake_new.size() == awake.size()) {
				pos = false;
				break;
			}
			awake = awake_new;
			o++;
		}
		if (!pos) {
			cout << "THIS BRAIN NEVER WAKES UP" << endl;
		}
	}
}