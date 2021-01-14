#include <iostream>
#include <vector>
using namespace std;
int n, m, k;
vector<int> adj[100100];
vector<int> vis[100100];
vector<int> hist;
int type = 0;
vector<int> ans;
void dfs1 (int x, int p, int d) {
	if (type > 0) return;
	if (vis[x].size() > 0) {
		if (d-vis[x].back() <= k) {
			type = 2;
			for (int i=vis[x].back(); i<d; i++) {
				ans.push_back(hist[i]);
			}
		} else {
			type = 1;
			for (int i=vis[x].back(); i<d; i+=2) {
				ans.push_back(hist[i]);
				if (ans.size() == (k+1)/2) break;
			}
		}
	}
	vis[x].push_back(d);
	hist.push_back(x);
	for (auto i: adj[x]) {
		if (i == p) continue;
		if (vis[i].size() > 0) dfs1(i, x, d+1);
		if (type > 0) return;
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		if (vis[i].size() == 0) dfs1(i, x, d+1);
		if (type > 0) return;
	}
	vis[x].pop_back();
	hist.pop_back();
}
vector<int> v1, v2;
void dfs2 (int x, int p, bool t) {
	if (t) {
		v1.push_back(x);
	} else {
		v2.push_back(x);
	}
	for (auto i: adj[x]) {
		if (i == p) continue;
		dfs2(i, x, !t);
	}
}
int main () {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m >> k;
	int ai, bi;
	for (int i=0; i<m; i++) {
		cin >> ai >> bi;
		ai--; bi--;
		adj[ai].push_back(bi);
		adj[bi].push_back(ai);
	}
	dfs1(0, 0, 0);
	if (type == 0) {
		cout << 1 << endl;
		dfs2(0, 0, 0);
		if (v1.size() < v2.size()) v1 = v2;
		for (int i=0; i<(k+1)/2; i++) {
			cout << v1[i]+1 << " ";
		}
		cout << endl;
		return 0;
	}
	cout << type << endl;
	if (type == 2) cout << ans.size() << endl;
	for (auto i: ans) cout << i+1 << " ";
	cout << endl;
}