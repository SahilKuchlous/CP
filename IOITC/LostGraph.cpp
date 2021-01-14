#include <iostream>
#include <vector>
#include <stack>
using namespace std;
int main () {
	int n, m, k;
	cin >> n >> m >> k;
	vector< vector < pair<int, long long> > > adj (n+1);
	int u, v;
	long long y;
	for (int i=0; i<m; i++) {
		cin >> u >> v >> y;
		adj[u].push_back(make_pair(v, y));
		adj[v].push_back(make_pair(u, y));
	}
	vector<bool> vis (n+1, false);
	stack<int> s;
	int l;
	while (true) {
		for (int i=1; i<=n; i++) {
			if (!vis[i]) {
				l = i;
				s.push(i);
				while (s.size()>0) {
					bool f = true;
					vis[s.top()] = true;
					for (auto j: adj[s.top()]) {
						if (!vis[j.first]) {
							s.push(j.first);
							f = false;
							break;
						}
					}
					if (f) {
						s.pop();
					}
				}
			}
		}
		bool g = true;
		for (int i=1; i<=n; i++) {
			if (!vis[i]) {
				g = false;
				break;
			}
		}
		if (g) {
			break;
		}
	}
	int a[n+1];
	bool pos = true;
	for (int i=0; i<=n; i++) {
		vis[i] = false;
		a[i] = -1;
	}
	while (true) {
		for (int i=1; i<=n; i++) {
			if (!vis[i]) {
				if (i == l) {
					a[i] = k-1;
				} else {
					a[i] = 0;
				}
				s.push(i);
				while (s.size()>0) {
					bool f = true;
					vis[s.top()] = true;
					for (auto j: adj[s.top()]) {
						if (!vis[j.first]) {
							a[j.first] = a[s.top()]^j.second;
							s.push(j.first);
							f = false;
							break;
						} else {
							if (a[j.first] != (a[s.top()]^j.second)) {
								pos = false;
								break;
							}
						}
					}
					if (f) {
						s.pop();
					}
					if (!pos) {
						break;
					}
				}
			}
			if (!pos) {
				break;
			}
		}
		if (!pos) {
			break;
		}
		bool g = true;
		for (int i=1; i<=n; i++) {
			if (!vis[i]) {
				g = false;
				break;
			}
		}
		if (g) {
			break;
		}
	}
	if (pos) {
		for (int i=1; i<=n; i++) {
			cout << a[i] << " ";
		}
		cout << endl;
	} else {
		cout << -1 << endl;
	}
}