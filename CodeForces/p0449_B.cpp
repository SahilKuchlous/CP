#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	map<long long, long long> adj[n+1];
	long long ai, bi, ci;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi >> ci;
		if (adj[ai].find(bi) == adj[ai].end()) {
			adj[ai][bi] = adj[bi][ai] = ci;
		} else {
			adj[ai][bi] = adj[bi][ai] = min(adj[ai][bi], ci);
		}
	}
	set< pair<long long, long long> > rails;
	for (int i=0; i<k; i++) {
		cin >> ai >> bi;
		rails.insert(make_pair(ai, bi));
	}
	long long dist[n+1];
	bool vis[n+1];
	bool used[n+1];
	for (int i=1; i<=n; i++) {
		dist[i] = 1e12;
		vis[i] = false;
		used[i] = true;
	}
	dist[1] = 0;
	set< pair< pair<long long, long long>, int> > cur;
	cur.insert(make_pair(make_pair(0, 1), 0));
	for (auto i: rails) {
		cur.insert(make_pair(make_pair(i.second, i.first), 1));
		dist[i.first] = min(dist[i.first], i.second);
	}
	long long x, d;
	int t;
	int o = 0;
	while (cur.size() > 0) {
		x = (*cur.begin()).first.second;
		d = (*cur.begin()).first.first;
		t = (*cur.begin()).second;
		cur.erase(cur.begin());
		if (vis[x]) {
			continue;
		}
		// cout << x << " " << d << " " << t << endl;
		vis[x] = true;
		if (t == 1) {
			// cout << x << endl;
			o++;
		}
		for (auto i: adj[x]) {
			if (!vis[i.first] && d+i.second <= dist[i.first]) {
				if (used[i.first]) {
					cur.erase(make_pair(make_pair(dist[i.first], i.first), 1));
				} else {
					cur.erase(make_pair(make_pair(dist[i.first], i.first), 0));
				}
				used[i.first] = false;
				dist[i.first] = d+i.second;
				cur.insert(make_pair(make_pair(dist[i.first], i.first), 0));
			}
		}
	}
	cout << k-o << endl;
}