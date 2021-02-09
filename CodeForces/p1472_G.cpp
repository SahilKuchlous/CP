#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
#define MAXN 200005
void solve () {
	int n, m;
	cin >> n >> m;
	vector<int> adj[n];
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
	}
	queue<int> q;
	bool vis[n];
	for (int i=0; i<n; i++) {
		vis[i] = false;
	}
	int dist[n];
	q.push(0);
	dist[0] = 0;
	vis[0] = true;
	while (q.size() > 0) {
		int cur = q.front();
		q.pop();
		for (auto i: adj[cur]) {
			if (vis[i]) continue;
			dist[i] = dist[cur]+1;
			vis[i] = true;
			q.push(i); 
		}
	}
	int o[n];
	for (int i=0; i<n; i++) {
		o[i] = dist[i];
		for (auto j: adj[i]) {
			o[i] = min(o[i], dist[j]);
		}
	}
	pair<int, int> ord[n];
	for (int i=0; i<n; i++) {
		ord[i] = make_pair(-dist[i], i);
	}
	sort(ord, ord+n);
	for (auto i: ord) {
		for (auto j: adj[i.second]) {
			if (dist[j] > dist[i.second]) {
				o[i.second] = min(o[i.second], o[j]);
			}
		}
	}
	for (int i=0; i<n; i++) {
		cout << o[i] << " ";
	}
	cout << endl;
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}