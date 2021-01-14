#include <iostream>
#include <set>
using namespace std;
int n, m;
set<int> adj[500];
set<int> vis;
set<int> bound;
set<int> nbound;
int d = 0;
bool found = false;
int main () {
	cin >> n >> m;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	bool use = false;
	if (adj[1].find(n) == adj[1].end()) {
		use = true;
	}
	bound.insert(1);
	while (bound.size() > 0 && !found) {
		for (auto i: bound) {
			vis.insert(i);
			if (i == n) {
				found = true;
				break;
			}
			if (use) {
				for (auto j: adj[i]) {
					if (vis.find(j) == vis.end()) nbound.insert(j);
				}
			} else {
				for (int j=1; j<=n; j++) {
					if (adj[i].find(j) == adj[i].end() && vis.find(j) == vis.end()) nbound.insert(j);
				}
			}
		}
		bound = nbound;
		nbound.clear();
		d++;
	}
	if (found) {
		cout << d-1 << endl;
	} else {
		cout << -1 << endl;
	}
}