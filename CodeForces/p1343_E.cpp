#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, m, a, b, c;
vector<int> adj[200100];
int dist[200100][3];
void bfs (int x, int t) {
	bool vis[n];
	for (int i=0; i<n; i++) {
		vis[i] = false;
	}
	vector<int> cur = {x};
	vector<int> next;
	int cur_d = 0;
	while (cur.size() > 0) {
		for (auto i: cur) {
			dist[i][t] = cur_d;
			vis[i] = true;
		}
		for (auto i: cur) {
			for (auto j: adj[i]) {
				if (!vis[j]) {
					next.push_back(j);
				}
			}
		}
		cur = next;
		next.clear();
		cur_d++;
	}
}
int main () {
	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m >> a >> b >> c;
		a--; b--; c--;
		for (int i=0; i<n; i++) {
			adj[i].clear();
		}
		int wts[m];
		for (int i=0; i<m; i++) {
			cin >> wts[i];
		}
		sort(wts, wts+m);
		int ai, bi;
		for (int i=0; i<m; i++) {
			cin >> ai >> bi;
			ai--; bi--;
			adj[ai].push_back(bi);
			adj[bi].push_back(ai);
		}
		bfs(a, 0);
		bfs(b, 1);
		bfs(c, 2);
		long long psum[m+1];
		psum[0] = 0;
		for (int i=1; i<=m; i++) {
			psum[i] = psum[i-1]+wts[i-1];
		}
		long long ans = 1e14;
		long long cur = 0;
		for (int i=0; i<n; i++) {
			if (dist[i][0] + dist[i][1] + dist[i][2] <= m) {
				cur = psum[dist[i][1]]+psum[dist[i][0] + dist[i][1] + dist[i][2]];
				ans = min(ans, cur);
			}
		}
		cout << ans << endl;
	}
}