#include <iostream>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;
bool sort_func (const pair<int, int> p1, const pair<int, int> p2) {
	if ((p1.first-p1.second) != (p2.first-p2.second)) return (p1.first-p1.second) < (p2.first-p2.second);
	return p1.second < p2.second;
}
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	int spec[k];
	for (int i=0; i<k; i++) {
		cin >> spec[i];
	}
	set<int> adj[n+1];
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		adj[ai].insert(bi);
		adj[bi].insert(ai);
	}
	pair<int, int> dist[n+1];
	queue< pair<int, int> > cur;
	bool vis[n+1];
	for (int i=0; i<=n; i++) vis[i] = false;
	cur.push(make_pair(1, 0));
	vis[1] = true;
	while (cur.size() > 0) {
		dist[cur.front().first].first = cur.front().second;
		for (auto i: adj[cur.front().first]) {
			if (!vis[i]) {
				cur.push(make_pair(i, cur.front().second+1));
				vis[i] = true;
			}
		}
		cur.pop();
	}
	for (int i=0; i<=n; i++) vis[i] = false;
	cur.push(make_pair(n, 0));
	vis[n] = true;
	while (cur.size() > 0) {
		dist[cur.front().first].second = cur.front().second;
		for (auto i: adj[cur.front().first]) {
			if (!vis[i]) {
				cur.push(make_pair(i, cur.front().second+1));
				vis[i] = true;
			}
		}
		cur.pop();
	}
	int o = 0;
	pair<int, int> imp[k];
	for (int i=0; i<k; i++) {
		imp[i] = dist[spec[i]];
	}
	sort(imp, imp+k, sort_func);
	int cur_max = imp[k-1].second;
	for (int i=k-2; i>=0; i--) {
		o = max(o, imp[i].first+cur_max+1);
		cur_max = max(cur_max, imp[i].second); 
	}
	cout << min(o, dist[n].first) << endl;
}