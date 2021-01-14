#include <iostream>
#include <set>
using namespace std;
int main () {
	int n, m;
	cin >> n >> m;
	set<int> adj[n+1];
	int ui, vi;
	for (int i=0; i<m; i++) {
		cin >> ui >> vi;
		adj[vi].insert(ui);
	}
	int k;
	cin >> k;
	int path[k];
	for (int i=0; i<k; i++) {
		cin >> path[i];
	}
	int dist[n+1];
	bool mult[n+1];
	bool vis[n+1];
	for (int i=1; i<=n; i++) {
		mult[i] = vis[i] = false;
	}
	set<int> cur;
	set<int> next;
	cur.insert(path[k-1]);
	int d = 0;
	while (cur.size() > 0) {
		for (auto i: cur) {
			dist[i] = d;
			vis[i] = true;
		}
		for (auto i: cur) {
			dist[i] = d;
			for (auto j: adj[i]) {
				if (!vis[j]) {
					if (next.find(j) == next.end()) {
						next.insert(j);
					} else {
						mult[j] = true;
					}
				}
			}
		}
		cur = next;
		next.clear();
		d++;
	}
	int o1=0, o2=0;
	for (int i=1; i<k; i++) {
		if (dist[path[i-1]]-dist[path[i]] < 1) o1++;
		if (dist[path[i-1]]-dist[path[i]] < 1 || mult[path[i-1]]) o2++;
	}
	cout << o1 << " " << o2 << endl;
}