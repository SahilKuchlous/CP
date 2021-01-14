#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main () {
	int t;
	cin >> t;
	while (t--) {
		int n, k;
		cin >> n >> k;
		int ai, bi;
		set<int> adj[n];
		for (int i=0; i<n-1; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].insert(bi);
			adj[bi].insert(ai);
		}
		vector<int> lvs[n];
		for (int i=0; i<n; i++) {
			for (auto j: adj[i]) {
				if (adj[j].size() == 1) lvs[i].push_back(j);
			}
		}
		set< pair<int, int>, greater< pair<int, int> > > ord;
		bool done[n];
		for (int i=0; i<n; i++) {
			ord.insert(make_pair(lvs[i].size(), i));
			done[i] = false;
		}
		int o = 0;
		while (true) {
			pair<int, int> cur = *ord.begin();
			ord.erase(ord.begin());
			if (done[cur.second]) continue;
			if (cur.first < k) break;
			o++;
			for (int i=0; i<k; i++) {
				adj[cur.second].erase(lvs[cur.second].back());
				done[lvs[cur.second].back()] = true;
				lvs[cur.second].pop_back();
			}
			ord.insert(make_pair(lvs[cur.second].size(), cur.second));
			if (adj[cur.second].size() == 1) {
				int par = *adj[cur.second].begin();
				ord.erase(make_pair(lvs[par].size(), par));
				lvs[par].push_back(cur.second);
				ord.insert(make_pair(lvs[par].size(), par));
			}
		}
		cout << o << endl;
	}
}