#include <iostream>
#include <vector>
#include <set>
using namespace std;
#define MAXN 300005
int n, m;
vector<int> adj[MAXN];
set<int> ban;
set<int> opts;
set<int> o;
void init () {
	for (int i=0; i<n; i++) {
		adj[i].clear();
	}
	ban.clear();
	opts.clear();
	o.clear();
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		init();
		int ai, bi;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		opts.insert(0);
		while (opts.size() > 0) {
			int cur = *opts.begin();
			opts.erase(opts.begin());
			ban.insert(cur);
			o.insert(cur);
			for (auto i: adj[cur]) {
				if (ban.find(i) != ban.end()) continue;
				ban.insert(i);
				opts.erase(i);
				for (auto j: adj[i]) {
					if (ban.find(j) == ban.end()) {
						opts.insert(j);
					}
				}
			}
		}
		if (ban.size() != n) {
			cout << "NO" << endl;
			continue;
		}
		cout << "YES" << endl;
		cout << o.size() << endl;
		for (auto i: o) {
			cout << i+1 << " ";
		}
		cout << endl;
	}
}