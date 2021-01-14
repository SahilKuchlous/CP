#include <iostream>
#include <set>
#include <vector>
using namespace std;
int n, m, k;
set<int> adj[200100];
pair<int, int> edges[200100];
int deg[200100];
set< pair<int, int> > ord;
int o[200100];
int main () {
	cin >> n >> m >> k;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
		edges[i] = make_pair(ai, bi);
		deg[ai]++; deg[bi]++;
	}
	for (int i=0; i<n; i++) {
		ord.insert(make_pair(deg[i], i));
	}
	for (int i=m-1; i>=0; i--) {
		while (ord.size() > 0 && ord.begin()->first < k) {
			int v = ord.begin()->second;
			ord.erase(ord.begin());
			deg[v] = -1;
			for (auto j: adj[v]) {
				if (deg[j] > -1) {
					ord.erase(make_pair(deg[j], j));
					deg[j]--;
					ord.insert(make_pair(deg[j], j));
				}
			}
		}
		o[i] = ord.size();
		if (deg[edges[i].first] > -1 && deg[edges[i].second] > -1) {
			ord.erase(make_pair(deg[edges[i].first], edges[i].first));
			deg[edges[i].first]--;
			ord.insert(make_pair(deg[edges[i].first], edges[i].first));
			adj[edges[i].first].erase(edges[i].second);
			ord.erase(make_pair(deg[edges[i].second], edges[i].second));
			deg[edges[i].second]--;
			ord.insert(make_pair(deg[edges[i].second], edges[i].second));
			adj[edges[i].second].erase(edges[i].first);
		}
	}
	for (int i=0; i<m; i++) {
		cout << o[i] << endl;
	}
}